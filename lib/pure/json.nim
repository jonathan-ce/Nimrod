#
#
#            Nimrod's Runtime Library
#        (c) Copyright 2012 Andreas Rumpf, Dominik Picheta
#
#    See the file "copying.txt", included in this
#    distribution, for details about the copyright.
#

## This module implements a simple high performance `JSON`:idx:
## parser. JSON (JavaScript Object Notation) is a lightweight 
## data-interchange format that is easy for humans to read and write 
## (unlike XML). It is easy for machines to parse and generate.
## JSON is based on a subset of the JavaScript Programming Language,
## Standard ECMA-262 3rd Edition - December 1999.
##
## Usage example:
##
## .. code-block:: nimrod
##  let
##    small_json = """{"test": 1.3, "key2": true}"""
##    jobj = parseJson(small_json)
##  assert (jobj.kind == JObject)
##  echo($jobj["test"].fnum)
##  echo($jobj["key2"].bval)
##
## Results in:
##
## .. code-block:: nimrod
##
##   1.3000000000000000e+00
##   true

import 
  hashes, strutils, lexbase, streams, unicode

type 
  TJsonEventKind* = enum ## enumeration of all events that may occur when parsing
    jsonError,           ## an error ocurred during parsing
    jsonEof,             ## end of file reached
    jsonString,          ## a string literal
    jsonInt,             ## an integer literal
    jsonFloat,           ## a float literal
    jsonTrue,            ## the value ``true``
    jsonFalse,           ## the value ``false``
    jsonNull,            ## the value ``null``
    jsonObjectStart,     ## start of an object: the ``{`` token
    jsonObjectEnd,       ## end of an object: the ``}`` token
    jsonArrayStart,      ## start of an array: the ``[`` token
    jsonArrayEnd         ## start of an array: the ``]`` token
    
  TTokKind = enum        # must be synchronized with TJsonEventKind!
    tkError,
    tkEof,
    tkString,
    tkInt,
    tkFloat,
    tkTrue,
    tkFalse,
    tkNull,
    tkCurlyLe,
    tkCurlyRi,
    tkBracketLe,
    tkBracketRi,
    tkColon,
    tkComma
    
  TJsonError* = enum       ## enumeration that lists all errors that can occur
    errNone,               ## no error
    errInvalidToken,       ## invalid token
    errStringExpected,     ## string expected
    errColonExpected,      ## ``:`` expected
    errCommaExpected,      ## ``,`` expected
    errBracketRiExpected,  ## ``]`` expected
    errCurlyRiExpected,    ## ``}`` expected
    errQuoteExpected,      ## ``"`` or ``'`` expected
    errEOC_Expected,       ## ``*/`` expected
    errEofExpected,        ## EOF expected
    errExprExpected        ## expr expected
    
  TParserState = enum 
    stateEof, stateStart, stateObject, stateArray, stateExpectArrayComma,
    stateExpectObjectComma, stateExpectColon, stateExpectValue

  TJsonParser* = object of TBaseLexer ## the parser object.
    a: string
    tok: TTokKind
    kind: TJsonEventKind
    err: TJsonError
    state: seq[TParserState]
    filename: string
 
const
  errorMessages: array [TJsonError, string] = [
    "no error",
    "invalid token",
    "string expected",
    "':' expected",
    "',' expected",
    "']' expected",
    "'}' expected",
    "'\"' or \"'\" expected",
    "'*/' expected",
    "EOF expected",
    "expression expected"
  ]
  tokToStr: array [TTokKind, string] = [
    "invalid token",
    "EOF",
    "string literal",
    "int literal",
    "float literal",
    "true",
    "false",
    "null",
    "{", "}", "[", "]", ":", ","
  ]

proc open*(my: var TJsonParser, input: PStream, filename: string) =
  ## initializes the parser with an input stream. `Filename` is only used
  ## for nice error messages.
  lexbase.open(my, input)
  my.filename = filename
  my.state = @[stateStart]
  my.kind = jsonError
  my.a = ""
  
proc close*(my: var TJsonParser) {.inline.} = 
  ## closes the parser `my` and its associated input stream.
  lexbase.close(my)

proc str*(my: TJsonParser): string {.inline.} = 
  ## returns the character data for the events: ``jsonInt``, ``jsonFloat``, 
  ## ``jsonString``
  assert(my.kind in {jsonInt, jsonFloat, jsonString})
  return my.a

proc getInt*(my: TJsonParser): BiggestInt {.inline.} = 
  ## returns the number for the event: ``jsonInt``
  assert(my.kind == jsonInt)
  return parseBiggestInt(my.a)

proc getFloat*(my: TJsonParser): float {.inline.} = 
  ## returns the number for the event: ``jsonFloat``
  assert(my.kind == jsonFloat)
  return parseFloat(my.a)

proc kind*(my: TJsonParser): TJsonEventKind {.inline.} = 
  ## returns the current event type for the JSON parser
  return my.kind
  
proc getColumn*(my: TJsonParser): int {.inline.} = 
  ## get the current column the parser has arrived at.
  result = getColNumber(my, my.bufPos)

proc getLine*(my: TJsonParser): int {.inline.} = 
  ## get the current line the parser has arrived at.
  result = my.linenumber

proc getFilename*(my: TJsonParser): string {.inline.} = 
  ## get the filename of the file that the parser processes.
  result = my.filename
  
proc errorMsg*(my: TJsonParser): string = 
  ## returns a helpful error message for the event ``jsonError``
  assert(my.kind == jsonError)
  result = "$1($2, $3) Error: $4" % [
    my.filename, $getLine(my), $getColumn(my), errorMessages[my.err]]

proc errorMsgExpected*(my: TJsonParser, e: string): string = 
  ## returns an error message "`e` expected" in the same format as the
  ## other error messages 
  result = "$1($2, $3) Error: $4" % [
    my.filename, $getLine(my), $getColumn(my), e & " expected"]

proc handleHexChar(c: char, x: var int): bool = 
  result = true # Success
  case c
  of '0'..'9': x = (x shl 4) or (ord(c) - ord('0'))
  of 'a'..'f': x = (x shl 4) or (ord(c) - ord('a') + 10)
  of 'A'..'F': x = (x shl 4) or (ord(c) - ord('A') + 10)
  else: result = false # error

proc parseString(my: var TJsonParser): TTokKind =
  result = tkString
  var pos = my.bufpos + 1
  var buf = my.buf
  while true:
    case buf[pos] 
    of '\0': 
      my.err = errQuoteExpected
      result = tkError
      break
    of '"':
      inc(pos)
      break
    of '\\':
      case buf[pos+1]
      of '\\', '"', '\'', '/': 
        add(my.a, buf[pos+1])
        inc(pos, 2)
      of 'b':
        add(my.a, '\b')
        inc(pos, 2)      
      of 'f':
        add(my.a, '\f')
        inc(pos, 2)      
      of 'n':
        add(my.a, '\L')
        inc(pos, 2)      
      of 'r':
        add(my.a, '\C')
        inc(pos, 2)    
      of 't':
        add(my.a, '\t')
        inc(pos, 2)
      of 'u':
        inc(pos, 2)
        var r: int
        if handleHexChar(buf[pos], r): inc(pos)
        if handleHexChar(buf[pos], r): inc(pos)
        if handleHexChar(buf[pos], r): inc(pos)
        if handleHexChar(buf[pos], r): inc(pos)
        add(my.a, toUTF8(TRune(r)))
      else: 
        # don't bother with the error
        add(my.a, buf[pos])
        inc(pos)
    of '\c': 
      pos = lexbase.HandleCR(my, pos)
      buf = my.buf
      add(my.a, '\c')
    of '\L': 
      pos = lexbase.HandleLF(my, pos)
      buf = my.buf
      add(my.a, '\L')
    else:
      add(my.a, buf[pos])
      inc(pos)
  my.bufpos = pos # store back
  
proc skip(my: var TJsonParser) = 
  var pos = my.bufpos
  var buf = my.buf
  while true: 
    case buf[pos]
    of '/': 
      if buf[pos+1] == '/': 
        # skip line comment:
        inc(pos, 2)
        while true:
          case buf[pos] 
          of '\0': 
            break
          of '\c': 
            pos = lexbase.HandleCR(my, pos)
            buf = my.buf
            break
          of '\L': 
            pos = lexbase.HandleLF(my, pos)
            buf = my.buf
            break
          else:
            inc(pos)
      elif buf[pos+1] == '*':
        # skip long comment:
        inc(pos, 2)
        while true:
          case buf[pos] 
          of '\0': 
            my.err = errEOC_Expected
            break
          of '\c': 
            pos = lexbase.HandleCR(my, pos)
            buf = my.buf
          of '\L': 
            pos = lexbase.HandleLF(my, pos)
            buf = my.buf
          of '*':
            inc(pos)
            if buf[pos] == '/': 
              inc(pos)
              break
          else:
            inc(pos)
      else: 
        break
    of ' ', '\t': 
      inc(pos)
    of '\c':  
      pos = lexbase.HandleCR(my, pos)
      buf = my.buf
    of '\L': 
      pos = lexbase.HandleLF(my, pos)
      buf = my.buf
    else:
      break
  my.bufpos = pos

proc parseNumber(my: var TJsonParser) = 
  var pos = my.bufpos
  var buf = my.buf
  if buf[pos] == '-': 
    add(my.a, '-')
    inc(pos)
  if buf[pos] == '.': 
    add(my.a, "0.")
    inc(pos)
  else:
    while buf[pos] in Digits:
      add(my.a, buf[pos])
      inc(pos)
    if buf[pos] == '.':
      add(my.a, '.')
      inc(pos)
  # digits after the dot:
  while buf[pos] in Digits:
    add(my.a, buf[pos])
    inc(pos)
  if buf[pos] in {'E', 'e'}:
    add(my.a, buf[pos])
    inc(pos)
    if buf[pos] in {'+', '-'}:
      add(my.a, buf[pos])
      inc(pos)
    while buf[pos] in Digits:
      add(my.a, buf[pos])
      inc(pos)
  my.bufpos = pos

proc parseName(my: var TJsonParser) = 
  var pos = my.bufpos
  var buf = my.buf
  if buf[pos] in IdentStartChars:
    while buf[pos] in IdentChars:
      add(my.a, buf[pos])
      inc(pos)
  my.bufpos = pos

proc getTok(my: var TJsonParser): TTokKind = 
  setLen(my.a, 0)
  skip(my) # skip whitespace, comments
  case my.buf[my.bufpos]
  of '-', '.', '0'..'9': 
    parseNumber(my)
    if {'.', 'e', 'E'} in my.a:
      result = tkFloat
    else:
      result = tkInt
  of '"':
    result = parseString(my)
  of '[':
    inc(my.bufpos)
    result = tkBracketLe
  of '{':
    inc(my.bufpos)
    result = tkCurlyLe
  of ']':
    inc(my.bufpos)
    result = tkBracketRi
  of '}':
    inc(my.bufpos)
    result = tkCurlyRi
  of ',':
    inc(my.bufpos)
    result = tkComma
  of ':':
    inc(my.bufpos)
    result = tkColon
  of '\0':
    result = tkEof
  of 'a'..'z', 'A'..'Z', '_':
    parseName(my)
    case my.a 
    of "null": result = tkNull
    of "true": result = tkTrue
    of "false": result = tkFalse
    else: result = tkError
  else: 
    inc(my.bufpos)
    result = tkError
  my.tok = result

proc next*(my: var TJsonParser) = 
  ## retrieves the first/next event. This controls the parser.
  var tk = getTok(my)
  var i = my.state.len-1
  # the following code is a state machine. If we had proper coroutines,
  # the code could be much simpler.
  case my.state[i]
  of stateEof:
    if tk == tkEof:
      my.kind = jsonEof
    else:
      my.kind = jsonError
      my.err = errEofExpected
  of stateStart: 
    # tokens allowed? 
    case tk
    of tkString, tkInt, tkFloat, tkTrue, tkFalse, tkNull:
      my.state[i] = stateEof # expect EOF next!
      my.kind = TJsonEventKind(ord(tk))
    of tkBracketLe: 
      my.state.add(stateArray) # we expect any
      my.kind = jsonArrayStart
    of tkCurlyLe:
      my.state.add(stateObject)
      my.kind = jsonObjectStart
    of tkEof:
      my.kind = jsonEof
    else:
      my.kind = jsonError
      my.err = errEofExpected
  of stateObject: 
    case tk
    of tkString, tkInt, tkFloat, tkTrue, tkFalse, tkNull:
      my.state.add(stateExpectColon)
      my.kind = TJsonEventKind(ord(tk))
    of tkBracketLe: 
      my.state.add(stateExpectColon)
      my.state.add(stateArray)
      my.kind = jsonArrayStart
    of tkCurlyLe:
      my.state.add(stateExpectColon)
      my.state.add(stateObject)
      my.kind = jsonObjectStart
    of tkCurlyRi:
      my.kind = jsonObjectEnd
      discard my.state.pop()
    else:
      my.kind = jsonError
      my.err = errCurlyRiExpected
  of stateArray:
    case tk
    of tkString, tkInt, tkFloat, tkTrue, tkFalse, tkNull:
      my.state.add(stateExpectArrayComma) # expect value next!
      my.kind = TJsonEventKind(ord(tk))
    of tkBracketLe: 
      my.state.add(stateExpectArrayComma)
      my.state.add(stateArray)
      my.kind = jsonArrayStart
    of tkCurlyLe:
      my.state.add(stateExpectArrayComma)
      my.state.add(stateObject)
      my.kind = jsonObjectStart
    of tkBracketRi:
      my.kind = jsonArrayEnd
      discard my.state.pop()
    else:
      my.kind = jsonError
      my.err = errBracketRiExpected
  of stateExpectArrayComma:
    case tk 
    of tkComma: 
      discard my.state.pop()
      next(my)
    of tkBracketRi:
      my.kind = jsonArrayEnd
      discard my.state.pop() # pop stateExpectArrayComma
      discard my.state.pop() # pop stateArray
    else:
      my.kind = jsonError
      my.err = errBracketRiExpected
  of stateExpectObjectComma:
    case tk 
    of tkComma: 
      discard my.state.pop()
      next(my)
    of tkCurlyRi:
      my.kind = jsonObjectEnd
      discard my.state.pop() # pop stateExpectObjectComma
      discard my.state.pop() # pop stateObject
    else:
      my.kind = jsonError
      my.err = errCurlyRiExpected
  of stateExpectColon: 
    case tk 
    of tkColon: 
      my.state[i] = stateExpectValue
      next(my)
    else:
      my.kind = jsonError
      my.err = errColonExpected
  of stateExpectValue:
    case tk
    of tkString, tkInt, tkFloat, tkTrue, tkFalse, tkNull:
      my.state[i] = stateExpectObjectComma
      my.kind = TJsonEventKind(ord(tk))
    of tkBracketLe: 
      my.state[i] = stateExpectObjectComma
      my.state.add(stateArray)
      my.kind = jsonArrayStart
    of tkCurlyLe:
      my.state[i] = stateExpectObjectComma
      my.state.add(stateObject)
      my.kind = jsonObjectStart
    else:
      my.kind = jsonError
      my.err = errExprExpected


# ------------- higher level interface ---------------------------------------

type
  TJsonNodeKind* = enum ## possible JSON node types
    JNull,
    JBool,
    JInt,
    JFloat,
    JString,
    JObject,
    JArray
    
  PJsonNode* = ref TJsonNode ## JSON node 
  TJsonNode* {.final, pure, acyclic.} = object
    case kind*: TJsonNodeKind
    of JString:
      str*: string
    of JInt:
      num*: BiggestInt
    of JFloat:
      fnum*: float
    of JBool:
      bval*: bool
    of JNull:
      nil
    of JObject:
      fields*: seq[tuple[key: string, val: PJsonNode]]
    of JArray:
      elems*: seq[PJsonNode]

  EJsonParsingError* = object of EInvalidValue ## is raised for a JSON error

proc raiseParseErr*(p: TJsonParser, msg: string) {.noinline, noreturn.} =
  ## raises an `EJsonParsingError` exception.
  raise newException(EJsonParsingError, errorMsgExpected(p, msg))

proc newJString*(s: string): PJsonNode =
  ## Creates a new `JString PJsonNode`.
  new(result)
  result.kind = JString
  result.str = s

proc newJStringMove(s: string): PJsonNode =
  new(result)
  result.kind = JString
  shallowCopy(result.str, s)

proc newJInt*(n: BiggestInt): PJsonNode =
  ## Creates a new `JInt PJsonNode`.
  new(result)
  result.kind = JInt
  result.num  = n

proc newJFloat*(n: float): PJsonNode =
  ## Creates a new `JFloat PJsonNode`.
  new(result)
  result.kind = JFloat
  result.fnum  = n

proc newJBool*(b: bool): PJsonNode =
  ## Creates a new `JBool PJsonNode`.
  new(result)
  result.kind = JBool
  result.bval = b

proc newJNull*(): PJsonNode =
  ## Creates a new `JNull PJsonNode`.
  new(result)

proc newJObject*(): PJsonNode =
  ## Creates a new `JObject PJsonNode`
  new(result)
  result.kind = JObject
  result.fields = @[]

proc newJArray*(): PJsonNode =
  ## Creates a new `JArray PJsonNode`
  new(result)
  result.kind = JArray
  result.elems = @[]


proc `%`*(s: string): PJsonNode =
  ## Generic constructor for JSON data. Creates a new `JString PJsonNode`.
  new(result)
  result.kind = JString
  result.str = s

proc `%`*(n: BiggestInt): PJsonNode =
  ## Generic constructor for JSON data. Creates a new `JInt PJsonNode`.
  new(result)
  result.kind = JInt
  result.num  = n

proc `%`*(n: float): PJsonNode =
  ## Generic constructor for JSON data. Creates a new `JFloat PJsonNode`.
  new(result)
  result.kind = JFloat
  result.fnum  = n

proc `%`*(b: bool): PJsonNode =
  ## Generic constructor for JSON data. Creates a new `JBool PJsonNode`.
  new(result)
  result.kind = JBool
  result.bval = b

proc `%`*(keyVals: openArray[tuple[key: string, val: PJsonNode]]): PJsonNode =
  ## Generic constructor for JSON data. Creates a new `JObject PJsonNode`
  new(result)
  result.kind = JObject
  newSeq(result.fields, keyVals.len)
  for i, p in pairs(keyVals): result.fields[i] = p

proc `%`*(elements: openArray[PJsonNode]): PJsonNode =
  ## Generic constructor for JSON data. Creates a new `JArray PJsonNode`
  new(result)
  result.kind = JArray
  newSeq(result.elems, elements.len)
  for i, p in pairs(elements): result.elems[i] = p

proc len*(n: PJsonNode): int = 
  ## If `n` is a `JArray`, it returns the number of elements.
  ## If `n` is a `JObject`, it returns the number of pairs.
  ## Else it returns 0.
  case n.kind
  of JArray: result = n.elems.len
  of JObject: result = n.fields.len
  else: nil

proc `[]`*(node: PJsonNode, name: string): PJsonNode =
  ## Gets a field from a `JObject`. Returns nil if the key is not found.
  assert(node.kind == JObject)
  for key, item in items(node.fields):
    if key == name:
      return item
  return nil
  
proc `[]`*(node: PJsonNode, index: int): PJsonNode =
  ## Gets the node at `index` in an Array.
  assert(node.kind == JArray)
  return node.elems[index]

proc hasKey*(node: PJsonNode, key: string): bool =
  ## Checks if `key` exists in `node`.
  assert(node.kind == JObject)
  for k, item in items(node.fields):
    if k == key: return True
proc existsKey*(node: PJsonNode, key: string): bool {.deprecated.} = node.hasKey(key)
  ## Deprecated for `hasKey`

proc add*(father, child: PJsonNode) = 
  ## Adds `child` to a JArray node `father`. 
  assert father.kind == JArray
  father.elems.add(child)

proc add*(obj: PJsonNode, key: string, val: PJsonNode) = 
  ## Adds ``(key, val)`` pair to the JObject node `obj`. For speed
  ## reasons no check for duplicate keys is performed!
  ## But ``[]=`` performs the check.
  assert obj.kind == JObject
  obj.fields.add((key, val))

proc `[]=`*(obj: PJsonNode, key: string, val: PJsonNode) =
  ## Sets a field from a `JObject`. Performs a check for duplicate keys.
  assert(obj.kind == JObject)
  for i in 0..obj.fields.len-1:
    if obj.fields[i].key == key: 
      obj.fields[i].val = val
      return
  obj.fields.add((key, val))

proc delete*(obj: PJsonNode, key: string) =
  ## Deletes ``obj[key]`` preserving the order of the other (key, value)-pairs.
  assert(obj.kind == JObject)
  for i in 0..obj.fields.len-1:
    if obj.fields[i].key == key:
      obj.fields.delete(i)
      return
  raise newException(EInvalidIndex, "key not in object")

proc copy*(p: PJsonNode): PJsonNode =
  ## Performs a deep copy of `a`.
  case p.kind
  of JString:
    result = newJString(p.str)
  of JInt:
    result = newJInt(p.num)
  of JFloat:
    result = newJFloat(p.fnum)
  of JBool:
    result = newJBool(p.bval)
  of JNull:
    result = newJNull()
  of JObject:
    result = newJObject()
    for key, field in items(p.fields):
      result.fields.add((key, copy(field)))
  of JArray:
    result = newJArray()
    for i in items(p.elems):
      result.elems.add(copy(i))

# ------------- pretty printing ----------------------------------------------

proc indent(s: var string, i: int) = 
  s.add(repeatChar(i))

proc newIndent(curr, indent: int, ml: bool): int =
  if ml: return curr + indent
  else: return indent

proc nl(s: var string, ml: bool) = 
  if ml: s.add("\n")

proc escapeJson*(s: string): string = 
  ## Converts a string `s` to its JSON representation.
  result = newStringOfCap(s.len + s.len shr 3)
  result.add("\"")
  for x in runes(s):
    var r = int(x)
    if r >= 32 and r <= 127:
      var c = chr(r)
      case c
      of '"': result.add("\\\"")
      of '\\': result.add("\\\\")
      else: result.add(c)
    else:
      result.add("\\u")
      result.add(toHex(r, 4))
  result.add("\"")

proc toPretty(result: var string, node: PJsonNode, indent = 2, ml = True, 
              lstArr = False, currIndent = 0) =
  case node.kind
  of JObject:
    if currIndent != 0 and not lstArr: result.nl(ml)
    result.indent(currIndent) # Indentation
    if node.fields.len > 0:  
      result.add("{")
      result.nl(ml) # New line
      for i in 0..len(node.fields)-1:
        if i > 0:
          result.add(", ")
          result.nl(ml) # New Line
        # Need to indent more than {
        result.indent(newIndent(currIndent, indent, ml)) 
        result.add(escapeJson(node.fields[i].key))
        result.add(": ")
        toPretty(result, node.fields[i].val, indent, ml, False, 
                 newIndent(currIndent, indent, ml))
      result.nl(ml)
      result.indent(currIndent) # indent the same as {
      result.add("}")
    else:
      result.add("{}")
  of JString: 
    if lstArr: result.indent(currIndent)
    result.add(escapeJson(node.str))
  of JInt:
    if lstArr: result.indent(currIndent)
    result.add($node.num)
  of JFloat:
    if lstArr: result.indent(currIndent)
    result.add($node.fnum)
  of JBool:
    if lstArr: result.indent(currIndent)
    result.add($node.bval)
  of JArray:
    if lstArr: result.indent(currIndent)
    if len(node.elems) != 0:
      result.add("[")
      result.nl(ml)
      for i in 0..len(node.elems)-1:
        if i > 0:
          result.add(", ")
          result.nl(ml) # New Line
        toPretty(result, node.elems[i], indent, ml,
            True, newIndent(currIndent, indent, ml))
      result.nl(ml)
      result.indent(currIndent)
      result.add("]")
    else: result.add("[]")
  of JNull:
    if lstArr: result.indent(currIndent)
    result.add("null")

proc pretty*(node: PJsonNode, indent = 2): string =
  ## Converts `node` to its JSON Representation, with indentation and
  ## on multiple lines.
  result = ""
  toPretty(result, node, indent)

proc `$`*(node: PJsonNode): string =
  ## Converts `node` to its JSON Representation on one line.
  result = ""
  toPretty(result, node, 1, False)

iterator items*(node: PJsonNode): PJsonNode =
  ## Iterator for the items of `node`. `node` has to be a JArray.
  assert node.kind == JArray
  for i in items(node.elems):
    yield i

iterator pairs*(node: PJsonNode): tuple[key: string, val: PJsonNode] =
  ## Iterator for the child elements of `node`. `node` has to be a JObject.
  assert node.kind == JObject
  for key, val in items(node.fields):
    yield (key, val)

proc eat(p: var TJsonParser, tok: TTokKind) = 
  if p.tok == tok: discard getTok(p)
  else: raiseParseErr(p, tokToStr[tok])

proc parseJson(p: var TJsonParser): PJsonNode = 
  ## Parses JSON from a JSON Parser `p`.
  case p.tok
  of tkString:
    # we capture 'p.a' here, so we need to give it a fresh buffer afterwards:
    result = newJStringMove(p.a)
    p.a = ""
    discard getTok(p)
  of tkInt:
    result = newJInt(parseBiggestInt(p.a))
    discard getTok(p)
  of tkFloat:
    result = newJFloat(parseFloat(p.a))
    discard getTok(p)
  of tkTrue:
    result = newJBool(true)
    discard getTok(p)
  of tkFalse: 
    result = newJBool(false)
    discard getTok(p)
  of tkNull: 
    result = newJNull()
    discard getTok(p)
  of tkCurlyLe: 
    result = newJObject()
    discard getTok(p)
    while p.tok != tkCurlyRi: 
      if p.tok != tkString: 
        raiseParseErr(p, "string literal as key expected")
      var key = p.a
      discard getTok(p)
      eat(p, tkColon)
      var val = parseJson(p)
      result[key] = val
      if p.tok != tkComma: break
      discard getTok(p)
    eat(p, tkCurlyRi)
  of tkBracketLe:
    result = newJArray()
    discard getTok(p)
    while p.tok != tkBracketRi: 
      result.add(parseJson(p))
      if p.tok != tkComma: break
      discard getTok(p)
    eat(p, tkBracketRi)
  of tkError, tkCurlyRi, tkBracketRi, tkColon, tkComma, tkEof:
    raiseParseErr(p, "{")

proc parseJson*(s: PStream, filename: string): PJsonNode =
  ## Parses from a stream `s` into a `PJsonNode`. `filename` is only needed
  ## for nice error messages.
  var p: TJsonParser
  p.open(s, filename)
  discard getTok(p) # read first token
  result = p.parseJson()
  p.close()

proc parseJson*(buffer: string): PJsonNode = 
  ## Parses JSON from `buffer`.
  result = parseJson(newStringStream(buffer), "input")

proc parseFile*(filename: string): PJsonNode =
  ## Parses `file` into a `PJsonNode`.
  var stream = newFileStream(filename, fmRead)
  if stream == nil: 
    raise newException(EIO, "cannot read from file: " & filename)
  result = parseJson(stream, filename)
  
when false:
  import os
  var s = newFileStream(ParamStr(1), fmRead)
  if s == nil: quit("cannot open the file" & ParamStr(1))
  var x: TJsonParser
  open(x, s, ParamStr(1))
  while true:
    next(x)
    case x.kind
    of jsonError:
      Echo(x.errorMsg())
      break
    of jsonEof: break
    of jsonString, jsonInt, jsonFloat: echo(x.str)
    of jsonTrue: Echo("!TRUE")
    of jsonFalse: Echo("!FALSE")
    of jsonNull: Echo("!NULL")
    of jsonObjectStart: Echo("{")
    of jsonObjectEnd: Echo("}")
    of jsonArrayStart: Echo("[")
    of jsonArrayEnd: Echo("]")
    
  close(x)

# { "json": 5 } 
# To get that we shall use, obj["json"]

when isMainModule:
  #var node = parse("{ \"test\": null }")
  #echo(node.existsKey("test56"))
  var parsed = parseFile("tests/testdata/jsontest.json")
  var parsed2 = parseFile("tests/testdata/jsontest2.json")
  echo(parsed)
  echo()
  echo(pretty(parsed, 2))
  echo()
  echo(parsed["keyÄÖöoßß"])
  echo()
  echo(pretty(parsed2))
  try:
    echo(parsed["key2"][12123])
    raise newException(EInvalidValue, "That line was expected to fail")
  except EInvalidIndex: echo()

  discard """
  while true:
    var json = stdin.readLine()
    var node = parse(json)
    echo(node)
    echo()
    echo()
  """
