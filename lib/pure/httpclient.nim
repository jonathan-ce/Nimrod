#
#
#            Nimrod's Runtime Library
#        (c) Copyright 2010 Dominik Picheta, Andreas Rumpf
#
#    See the file "copying.txt", included in this
#    distribution, for details about the copyright.
#

## This module implements a simple HTTP client that can be used to retrieve
## webpages/other data.
##
##
## **Note**: This module is not ideal, connection is not kept alive so sites with
## many redirects are expensive. As such in the future this module may change,
## and the current procedures will be deprecated.
##
## Retrieving a website
## ====================
## 
## This example uses HTTP GET to retrieve
## ``http://google.com``
## 
## .. code-block:: nimrod
##   echo(getContent("http://google.com"))
## 
## Using HTTP POST
## ===============
## 
## This example demonstrates the usage of the W3 HTML Validator, it 
## uses ``multipart/form-data`` as the ``Content-Type`` to send the HTML to
## the server. 
## 
## .. code-block:: nimrod
##   var headers: string = "Content-Type: multipart/form-data; boundary=xyz\c\L"
##   var body: string = "--xyz\c\L"
##   # soap 1.2 output
##   body.add("Content-Disposition: form-data; name=\"output\"\c\L")
##   body.add("\c\Lsoap12\c\L")
##    
##   # html
##   body.add("--xyz\c\L")
##   body.add("Content-Disposition: form-data; name=\"uploaded_file\";" &
##            " filename=\"test.html\"\c\L")
##   body.add("Content-Type: text/html\c\L")
##   body.add("\c\L<html><head></head><body><p>test</p></body></html>\c\L")
##   body.add("--xyz--")
##    
##   echo(postContent("http://validator.w3.org/check", headers, body))
##
## SSL/TLS support
## ===============
## This requires the OpenSSL library, fortunately it's widely used and installed
## on many operating systems. httpclient will use SSL automatically if you give
## any of the functions a url with the ``https`` schema, for example:
## ``https://github.com/``, you also have to compile with ``ssl`` defined like so:
## ``nimrod c -d:ssl ...``.
##
## Timeouts
## ========
## Currently all functions support an optional timeout, by default the timeout is set to
## `-1` which means that the function will never time out. The timeout is
## measured in miliseconds, once it is set any call on a socket which may
## block will be susceptible to this timeout, however please remember that the
## function as a whole can take longer than the specified timeout, only
## individual internal calls on the socket are affected. In practice this means
## that as long as the server is sending data an exception will not be raised,
## if however data does not reach client within the specified timeout an ETimeout
## exception will then be raised.
##
## Proxy
## =====
##
## A proxy can be specified as a param to any of these procedures, the ``newProxy``
## constructor should be used for this purpose. However,
## currently only basic authentication is supported.

import sockets, strutils, parseurl, parseutils, strtabs, base64
import asyncnet, asyncdispatch
import rawsockets

type
  TResponse* = tuple[
    version: string, 
    status: string, 
    headers: PStringTable,
    body: string]

  PProxy* = ref object
    url*: TUrl
    auth*: string

  EInvalidProtocol* = object of ESynch ## exception that is raised when server
                                       ## does not conform to the implemented
                                       ## protocol

  EHttpRequestErr* = object of ESynch ## Thrown in the ``getContent`` proc 
                                      ## and ``postContent`` proc,
                                      ## when the server returns an error

const defUserAgent* = "Nimrod httpclient/0.1"

proc httpError(msg: string) =
  var e: ref EInvalidProtocol
  new(e)
  e.msg = msg
  raise e
  
proc fileError(msg: string) =
  var e: ref EIO
  new(e)
  e.msg = msg
  raise e

proc parseChunks(s: TSocket, timeout: int): string =
  result = ""
  var ri = 0
  while true:
    var chunkSizeStr = ""
    var chunkSize = 0
    s.readLine(chunkSizeStr, timeout)
    var i = 0
    if chunkSizeStr == "":
      httpError("Server terminated connection prematurely")
    while true:
      case chunkSizeStr[i]
      of '0'..'9':
        chunkSize = chunkSize shl 4 or (ord(chunkSizeStr[i]) - ord('0'))
      of 'a'..'f':
        chunkSize = chunkSize shl 4 or (ord(chunkSizeStr[i]) - ord('a') + 10)
      of 'A'..'F':
        chunkSize = chunkSize shl 4 or (ord(chunkSizeStr[i]) - ord('A') + 10)
      of '\0':
        break
      of ';':
        # http://tools.ietf.org/html/rfc2616#section-3.6.1
        # We don't care about chunk-extensions.
        break
      else:
        httpError("Invalid chunk size: " & chunkSizeStr)
      inc(i)
    if chunkSize <= 0: break
    result.setLen(ri+chunkSize)
    var bytesRead = 0
    while bytesRead != chunkSize:
      let ret = recv(s, addr(result[ri]), chunkSize-bytesRead, timeout)
      ri += ret
      bytesRead += ret
    s.skip(2, timeout) # Skip \c\L
    # Trailer headers will only be sent if the request specifies that we want
    # them: http://tools.ietf.org/html/rfc2616#section-3.6.1
  
proc parseBody(s: TSocket, headers: PStringTable, timeout: int): string =
  result = ""
  if headers["Transfer-Encoding"] == "chunked":
    result = parseChunks(s, timeout)
  else:
    # -REGION- Content-Length
    # (http://tools.ietf.org/html/rfc2616#section-4.4) NR.3
    var contentLengthHeader = headers["Content-Length"]
    if contentLengthHeader != "":
      var length = contentLengthHeader.parseint()
      result = newString(length)
      var received = 0
      while true:
        if received >= length: break
        let r = s.recv(addr(result[received]), length-received, timeout)
        if r == 0: break
        received += r
      if received != length:
        httpError("Got invalid content length. Expected: " & $length &
                  " got: " & $received)
    else:
      # (http://tools.ietf.org/html/rfc2616#section-4.4) NR.4 TODO
      
      # -REGION- Connection: Close
      # (http://tools.ietf.org/html/rfc2616#section-4.4) NR.5
      if headers["Connection"] == "close":
        var buf = ""
        while True:
          buf = newString(4000)
          let r = s.recv(addr(buf[0]), 4000, timeout)
          if r == 0: break
          buf.setLen(r)
          result.add(buf)

proc parseResponse(s: TSocket, getBody: bool, timeout: int): TResponse =
  var parsedStatus = false
  var linei = 0
  var fullyRead = false
  var line = ""
  result.headers = newStringTable(modeCaseInsensitive)
  while True:
    line = ""
    linei = 0
    s.readLine(line, timeout)
    if line == "": break # We've been disconnected.
    if line == "\c\L":
      fullyRead = true
      break
    if not parsedStatus:
      # Parse HTTP version info and status code.
      var le = skipIgnoreCase(line, "HTTP/", linei)
      if le <= 0: httpError("invalid http version")
      inc(linei, le)
      le = skipIgnoreCase(line, "1.1", linei)
      if le > 0: result.version = "1.1"
      else:
        le = skipIgnoreCase(line, "1.0", linei)
        if le <= 0: httpError("unsupported http version")
        result.version = "1.0"
      inc(linei, le)
      # Status code
      linei.inc skipWhitespace(line, linei)
      result.status = line[linei .. -1]
      parsedStatus = true
    else:
      # Parse headers
      var name = ""
      var le = parseUntil(line, name, ':', linei)
      if le <= 0: httpError("invalid headers")
      inc(linei, le)
      if line[linei] != ':': httpError("invalid headers")
      inc(linei) # Skip :
      
      result.headers[name] = line[linei.. -1].strip()
  if not fullyRead:
    httpError("Connection was closed before full request has been made")
  if getBody:
    result.body = parseBody(s, result.headers, timeout)
  else:
    result.body = ""

type
  THttpMethod* = enum ## the requested HttpMethod
    httpHEAD,         ## Asks for the response identical to the one that would
                      ## correspond to a GET request, but without the response
                      ## body.
    httpGET,          ## Retrieves the specified resource.
    httpPOST,         ## Submits data to be processed to the identified 
                      ## resource. The data is included in the body of the 
                      ## request.
    httpPUT,          ## Uploads a representation of the specified resource.
    httpDELETE,       ## Deletes the specified resource.
    httpTRACE,        ## Echoes back the received request, so that a client 
                      ## can see what intermediate servers are adding or
                      ## changing in the request.
    httpOPTIONS,      ## Returns the HTTP methods that the server supports 
                      ## for specified address.
    httpCONNECT       ## Converts the request connection to a transparent 
                      ## TCP/IP tunnel, usually used for proxies.

when not defined(ssl):
  type PSSLContext = ref object
  let defaultSSLContext: PSSLContext = nil
else:
  let defaultSSLContext = newContext(verifyMode = CVerifyNone)

proc newProxy*(url: string, auth = ""): PProxy =
  ## Constructs a new ``TProxy`` object.
  result = PProxy(url: parseUrl(url), auth: auth)

proc request*(url: string, httpMethod = httpGET, extraHeaders = "", 
              body = "",
              sslContext: PSSLContext = defaultSSLContext,
              timeout = -1, userAgent = defUserAgent,
              proxy: PProxy = nil): TResponse =
  ## | Requests ``url`` with the specified ``httpMethod``.
  ## | Extra headers can be specified and must be seperated by ``\c\L``
  ## | An optional timeout can be specified in miliseconds, if reading from the
  ## server takes longer than specified an ETimeout exception will be raised.
  var r = if proxy == nil: parseUrl(url) else: proxy.url
  var headers = substr($httpMethod, len("http"))
  if proxy == nil:
    headers.add(" /" & r.path & r.query)
  else:
    headers.add(" " & url)

  headers.add(" HTTP/1.1\c\L")
  
  add(headers, "Host: " & r.hostname & "\c\L")
  if userAgent != "":
    add(headers, "User-Agent: " & userAgent & "\c\L")
  if proxy != nil and proxy.auth != "":
    let auth = base64.encode(proxy.auth, newline = "")
    add(headers, "Proxy-Authorization: basic " & auth & "\c\L")
  add(headers, extraHeaders)
  add(headers, "\c\L")
  
  var s = socket()
  var port = sockets.TPort(80)
  if r.scheme == "https":
    when defined(ssl):
      sslContext.wrapSocket(s)
      port = sockets.TPort(443)
    else:
      raise newException(EHttpRequestErr,
                "SSL support is not available. Cannot connect over SSL.")
  if r.port != "":
    port = sockets.TPort(r.port.parseInt)
  
  if timeout == -1:
    s.connect(r.hostname, port)
  else:
    s.connect(r.hostname, port, timeout)
  s.send(headers)
  if body != "":
    s.send(body)
  
  result = parseResponse(s, httpMethod != httpHEAD, timeout)
  s.close()
  
proc redirection(status: string): bool =
  const redirectionNRs = ["301", "302", "303", "307"]
  for i in items(redirectionNRs):
    if status.startsWith(i):
      return True

proc getNewLocation(lastUrl: string, headers: PStringTable): string =
  result = headers["Location"]
  if result == "": httpError("location header expected")
  # Relative URLs. (Not part of the spec, but soon will be.)
  let r = parseURL(result)
  if r.hostname == "" and r.path != "":
    let origParsed = parseURL(lastUrl)
    result = origParsed.hostname & "/" & r.path
  
proc get*(url: string, extraHeaders = "", maxRedirects = 5,
          sslContext: PSSLContext = defaultSSLContext,
          timeout = -1, userAgent = defUserAgent,
          proxy: PProxy = nil): TResponse =
  ## | GETs the ``url`` and returns a ``TResponse`` object
  ## | This proc also handles redirection
  ## | Extra headers can be specified and must be separated by ``\c\L``.
  ## | An optional timeout can be specified in miliseconds, if reading from the
  ## server takes longer than specified an ETimeout exception will be raised.
  result = request(url, httpGET, extraHeaders, "", sslContext, timeout,
                   userAgent, proxy)
  var lastURL = url
  for i in 1..maxRedirects:
    if result.status.redirection():
      let redirectTo = getNewLocation(lastURL, result.headers)
      result = request(redirectTo, httpGET, extraHeaders, "", sslContext,
                       timeout, userAgent, proxy)
      lastUrl = redirectTo
      
proc getContent*(url: string, extraHeaders = "", maxRedirects = 5,
                 sslContext: PSSLContext = defaultSSLContext,
                 timeout = -1, userAgent = defUserAgent,
                 proxy: PProxy = nil): string =
  ## | GETs the body and returns it as a string.
  ## | Raises exceptions for the status codes ``4xx`` and ``5xx``
  ## | Extra headers can be specified and must be separated by ``\c\L``.
  ## | An optional timeout can be specified in miliseconds, if reading from the
  ## server takes longer than specified an ETimeout exception will be raised.
  var r = get(url, extraHeaders, maxRedirects, sslContext, timeout, userAgent,
              proxy)
  if r.status[0] in {'4','5'}:
    raise newException(EHTTPRequestErr, r.status)
  else:
    return r.body
  
proc post*(url: string, extraHeaders = "", body = "",
           maxRedirects = 5,
           sslContext: PSSLContext = defaultSSLContext,
           timeout = -1, userAgent = defUserAgent,
           proxy: PProxy = nil): TResponse =
  ## | POSTs ``body`` to the ``url`` and returns a ``TResponse`` object.
  ## | This proc adds the necessary Content-Length header.
  ## | This proc also handles redirection.
  ## | Extra headers can be specified and must be separated by ``\c\L``.
  ## | An optional timeout can be specified in miliseconds, if reading from the
  ## server takes longer than specified an ETimeout exception will be raised.
  var xh = extraHeaders & "Content-Length: " & $len(body) & "\c\L"
  result = request(url, httpPOST, xh, body, sslContext, timeout, userAgent,
                   proxy)
  var lastUrl = ""
  for i in 1..maxRedirects:
    if result.status.redirection():
      let redirectTo = getNewLocation(lastURL, result.headers)
      var meth = if result.status != "307": httpGet else: httpPost
      result = request(redirectTo, meth, xh, body, sslContext, timeout,
                       userAgent, proxy)
      lastUrl = redirectTo
  
proc postContent*(url: string, extraHeaders = "", body = "",
                  maxRedirects = 5,
                  sslContext: PSSLContext = defaultSSLContext,
                  timeout = -1, userAgent = defUserAgent,
                  proxy: PProxy = nil): string =
  ## | POSTs ``body`` to ``url`` and returns the response's body as a string
  ## | Raises exceptions for the status codes ``4xx`` and ``5xx``
  ## | Extra headers can be specified and must be separated by ``\c\L``.
  ## | An optional timeout can be specified in miliseconds, if reading from the
  ## server takes longer than specified an ETimeout exception will be raised.
  var r = post(url, extraHeaders, body, maxRedirects, sslContext, timeout,
               userAgent, proxy)
  if r.status[0] in {'4','5'}:
    raise newException(EHTTPRequestErr, r.status)
  else:
    return r.body
  
proc downloadFile*(url: string, outputFilename: string,
                   sslContext: PSSLContext = defaultSSLContext,
                   timeout = -1, userAgent = defUserAgent,
                   proxy: PProxy = nil) =
  ## | Downloads ``url`` and saves it to ``outputFilename``
  ## | An optional timeout can be specified in miliseconds, if reading from the
  ## server takes longer than specified an ETimeout exception will be raised.
  var f: TFile
  if open(f, outputFilename, fmWrite):
    f.write(getContent(url, sslContext = sslContext, timeout = timeout,
            userAgent = userAgent, proxy = proxy))
    f.close()
  else:
    fileError("Unable to open file")

proc generateHeaders(r: TURL, httpMethod: THttpMethod,
                     headers: PStringTable): string =
  result = substr($httpMethod, len("http"))
  # TODO: Proxies
  result.add(" /" & r.path & r.query)
  result.add(" HTTP/1.1\c\L")

  add(result, "Host: " & r.hostname & "\c\L")
  add(result, "Connection: Keep-Alive\c\L")
  for key, val in headers:
    add(result, key & ": " & val & "\c\L")

  add(result, "\c\L")

type
  PAsyncHttpClient* = ref object
    socket: PAsyncSocket
    connected: bool
    currentURL: TURL ## Where we are currently connected.
    headers: PStringTable
    userAgent: string

proc newAsyncHttpClient*(): PAsyncHttpClient =
  new result
  result.headers = newStringTable(modeCaseInsensitive)
  result.userAgent = defUserAgent

proc close*(client: PAsyncHttpClient) =
  ## Closes any connections held by the HttpClient.
  if client.connected:
    client.socket.close()
    client.connected = false

proc recvFull(socket: PAsyncSocket, size: int): PFuture[string] {.async.} =
  ## Ensures that all the data requested is read and returned.
  result = ""
  while true:
    if size == result.len: break
    let data = await socket.recv(size - result.len)
    if data == "": break # We've been disconnected.
    result.add data

proc parseChunks(client: PAsyncHttpClient): PFuture[string] {.async.} =
  result = ""
  var ri = 0
  while true:
    var chunkSize = 0
    var chunkSizeStr = await client.socket.recvLine()
    var i = 0
    if chunkSizeStr == "":
      httpError("Server terminated connection prematurely")
    while true:
      case chunkSizeStr[i]
      of '0'..'9':
        chunkSize = chunkSize shl 4 or (ord(chunkSizeStr[i]) - ord('0'))
      of 'a'..'f':
        chunkSize = chunkSize shl 4 or (ord(chunkSizeStr[i]) - ord('a') + 10)
      of 'A'..'F':
        chunkSize = chunkSize shl 4 or (ord(chunkSizeStr[i]) - ord('A') + 10)
      of '\0':
        break
      of ';':
        # http://tools.ietf.org/html/rfc2616#section-3.6.1
        # We don't care about chunk-extensions.
        break
      else:
        httpError("Invalid chunk size: " & chunkSizeStr)
      inc(i)
    if chunkSize <= 0: break
    result.add await recvFull(client.socket, chunkSize)
    discard await recvFull(client.socket, 2) # Skip \c\L
    # Trailer headers will only be sent if the request specifies that we want
    # them: http://tools.ietf.org/html/rfc2616#section-3.6.1
  
proc parseBody(client: PAsyncHttpClient,
               headers: PStringTable): PFuture[string] {.async.} =
  result = ""
  if headers["Transfer-Encoding"] == "chunked":
    result = await parseChunks(client)
  else:
    # -REGION- Content-Length
    # (http://tools.ietf.org/html/rfc2616#section-4.4) NR.3
    var contentLengthHeader = headers["Content-Length"]
    if contentLengthHeader != "":
      var length = contentLengthHeader.parseint()
      result = await client.socket.recvFull(length)
      if result == "":
        httpError("Got disconnected while trying to read body.")
      if result.len != length:
        httpError("Received length doesn't match expected length. Wanted " &
                  $length & " got " & $result.len)
    else:
      # (http://tools.ietf.org/html/rfc2616#section-4.4) NR.4 TODO
      
      # -REGION- Connection: Close
      # (http://tools.ietf.org/html/rfc2616#section-4.4) NR.5
      if headers["Connection"] == "close":
        var buf = ""
        while True:
          buf = await client.socket.recvFull(4000)
          if buf == "": break
          result.add(buf)

proc parseResponse(client: PAsyncHttpClient,
                   getBody: bool): PFuture[TResponse] {.async.} =
  var parsedStatus = false
  var linei = 0
  var fullyRead = false
  var line = ""
  result.headers = newStringTable(modeCaseInsensitive)
  while True:
    linei = 0
    line = await client.socket.recvLine()
    if line == "": break # We've been disconnected.
    if line == "\c\L":
      fullyRead = true
      break
    if not parsedStatus:
      # Parse HTTP version info and status code.
      var le = skipIgnoreCase(line, "HTTP/", linei)
      if le <= 0:
        while true:
          let nl = await client.socket.recvLine()
          echo("Got another line: ", nl)
        httpError("invalid http version, " & line.repr)
      inc(linei, le)
      le = skipIgnoreCase(line, "1.1", linei)
      if le > 0: result.version = "1.1"
      else:
        le = skipIgnoreCase(line, "1.0", linei)
        if le <= 0: httpError("unsupported http version")
        result.version = "1.0"
      inc(linei, le)
      # Status code
      linei.inc skipWhitespace(line, linei)
      result.status = line[linei .. -1]
      parsedStatus = true
    else:
      # Parse headers
      var name = ""
      var le = parseUntil(line, name, ':', linei)
      if le <= 0: httpError("invalid headers")
      inc(linei, le)
      if line[linei] != ':': httpError("invalid headers")
      inc(linei) # Skip :
      
      result.headers[name] = line[linei.. -1].strip()
  if not fullyRead:
    httpError("Connection was closed before full request has been made")
  if getBody:
    result.body = await parseBody(client, result.headers)
  else:
    result.body = ""

proc newConnection(client: PAsyncHttpClient, url: TURL) {.async.} =
  if client.currentURL.hostname != url.hostname or
      client.currentURL.scheme != url.scheme:
    if client.connected: client.close()
    client.socket = newAsyncSocket()
    if url.scheme == "https":
      assert false, "TODO SSL"

    # TODO: I should be able to write 'net.TPort' here...
    let port =
      if url.port == "": rawsockets.TPort(80)
      else: rawsockets.TPort(url.port.parseInt)
    
    await client.socket.connect(url.hostname, port)
    client.currentURL = url
    client.connected = true

proc request*(client: PAsyncHttpClient, url: string, httpMethod = httpGET,
              body = ""): PFuture[TResponse] {.async.} =
  let r = parseUrl(url)
  await newConnection(client, r)

  if not client.headers.hasKey("user-agent") and client.userAgent != "":
    client.headers["User-Agent"] = client.userAgent
  
  var headers = generateHeaders(r, httpMethod, client.headers)
  
  await client.socket.send(headers)
  if body != "":
    await client.socket.send(body)
  
  result = await parseResponse(client, httpMethod != httpHEAD)

when isMainModule:
  when true:
    # Async
    proc main() {.async.} =
      var client = newAsyncHttpClient()
      var resp = await client.request("http://picheta.me")
      
      echo("Got response: ", resp.status)
      echo("Body:\n")
      echo(resp.body)

      resp = await client.request("http://picheta.me/asfas.html")
      echo("Got response: ", resp.status)

      resp = await client.request("http://picheta.me/aboutme.html")
      echo("Got response: ", resp.status)

      resp = await client.request("http://nimrod-lang.org/")
      echo("Got response: ", resp.status)

      resp = await client.request("http://nimrod-lang.org/download.html")
      echo("Got response: ", resp.status)

    main()
    runForever()

  else:
    #downloadFile("http://force7.de/nimrod/index.html", "nimrodindex.html")
    #downloadFile("http://www.httpwatch.com/", "ChunkTest.html")
    #downloadFile("http://validator.w3.org/check?uri=http%3A%2F%2Fgoogle.com",
    # "validator.html")

    #var r = get("http://validator.w3.org/check?uri=http%3A%2F%2Fgoogle.com&
    #  charset=%28detect+automatically%29&doctype=Inline&group=0")
    
    var headers: string = "Content-Type: multipart/form-data; boundary=xyz\c\L"
    var body: string = "--xyz\c\L"
    # soap 1.2 output
    body.add("Content-Disposition: form-data; name=\"output\"\c\L")
    body.add("\c\Lsoap12\c\L")
    
    # html
    body.add("--xyz\c\L")
    body.add("Content-Disposition: form-data; name=\"uploaded_file\";" &
             " filename=\"test.html\"\c\L")
    body.add("Content-Type: text/html\c\L")
    body.add("\c\L<html><head></head><body><p>test</p></body></html>\c\L")
    body.add("--xyz--")

    echo(postContent("http://validator.w3.org/check", headers, body))
