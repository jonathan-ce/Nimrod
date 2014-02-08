#
#
#            Nimrod's Runtime Library
#        (c) Copyright 2012 Andreas Rumpf
#
#    See the file "copying.txt", included in this
#    distribution, for details about the copyright.
#

## Regular expression support for Nimrod. Consider using the pegs module
## instead.
## This module is implemented by providing a wrapper around the
## `PRCE (Perl-Compatible Regular Expressions) <http://www.pcre.org>`_
## C library. This means that your application will depend on the PRCE
## library's licence when using this module, which should not be a problem
## though.
## PRCE's licence follows:
##
## .. include:: ../doc/regexprs.txt
##

import
  pcre, strutils

const
  MaxSubpatterns* = 10
    ## defines the maximum number of subpatterns that can be captured.
    ## More subpatterns cannot be captured!

type
  TRegexFlag* = enum     ## options for regular expressions
    reIgnoreCase = 0,    ## do caseless matching
    reMultiLine = 1,     ## ``^`` and ``$`` match newlines within data 
    reDotAll = 2,        ## ``.`` matches anything including NL
    reExtended = 3,      ## ignore whitespace and ``#`` comments
    reStudy = 4          ## study the expression (may be omitted if the
                         ## expression will be used only once)
    
  TRegexDesc {.pure, final.}  = object 
    h: PPcre
    e: ptr TExtra
    
  TRegex* = ref TRegexDesc ## a compiled regular expression
    
  EInvalidRegEx* = object of EInvalidValue
    ## is raised if the pattern is no valid regular expression.

proc raiseInvalidRegex(msg: string) {.noinline, noreturn.} = 
  var e: ref EInvalidRegEx
  new(e)
  e.msg = msg
  raise e
  
proc rawCompile(pattern: string, flags: cint): PPcre =
  var
    msg: cstring
    offset: cint
  result = pcre.Compile(pattern, flags, addr(msg), addr(offset), nil)
  if result == nil:
    raiseInvalidRegex($msg & "\n" & pattern & "\n" & repeatChar(offset) & "^\n")

proc finalizeRegEx(x: TRegex) = 
  # XXX This is a hack, but PCRE does not export its "free" function properly.
  # Sigh. The hack relies on PCRE's implementation (see ``pcre_get.c``).
  # Fortunately the implementation is unlikely to change. 
  pcre.free_substring(cast[cstring](x.h))
  if not isNil(x.e):
    pcre.free_substring(cast[cstring](x.e))

proc re*(s: string, flags = {reExtended, reStudy}): TRegex =
  ## Constructor of regular expressions. Note that Nimrod's
  ## extended raw string literals support this syntax ``re"[abc]"`` as
  ## a short form for ``re(r"[abc]")``.
  new(result, finalizeRegEx)
  result.h = rawCompile(s, cast[cint](flags - {reStudy}))
  if reStudy in flags:
    var msg: cstring
    result.e = pcre.study(result.h, 0, msg)
    if not isNil(msg): raiseInvalidRegex($msg)

proc matchOrFind(s: string, pattern: TRegex, matches: var openArray[string],
                 start, flags: cint): cint =
  var
    rawMatches: array[0..maxSubpatterns * 3 - 1, cint]
    res = pcre.Exec(pattern.h, pattern.e, s, len(s).cint, start, flags,
      cast[ptr cint](addr(rawMatches)), maxSubpatterns * 3)
  if res < 0'i32: return res
  for i in 1..int(res)-1:
    var a = rawMatches[i * 2]
    var b = rawMatches[i * 2 + 1]
    if a >= 0'i32: matches[i-1] = substr(s, int(a), int(b)-1)
    else: matches[i-1] = ""
  return rawMatches[1] - rawMatches[0]
  
proc findBounds*(s: string, pattern: TRegex, matches: var openArray[string],
                 start = 0): tuple[first, last: int] =
  ## returns the starting position and end position of `pattern` in `s` 
  ## and the captured
  ## substrings in the array `matches`. If it does not match, nothing
  ## is written into `matches` and ``(-1,0)`` is returned.
  var
    rawMatches: array[0..maxSubpatterns * 3 - 1, cint]
    res = pcre.Exec(pattern.h, pattern.e, s, len(s).cint, start.cint, 0'i32,
      cast[ptr cint](addr(rawMatches)), maxSubpatterns * 3)
  if res < 0'i32: return (-1, 0)
  for i in 1..int(res)-1:
    var a = rawMatches[i * 2]
    var b = rawMatches[i * 2 + 1]
    if a >= 0'i32: matches[i-1] = substr(s, int(a), int(b)-1)
    else: matches[i-1] = ""
  return (rawMatches[0].int, rawMatches[1].int - 1)
  
proc findBounds*(s: string, pattern: TRegex, 
                 matches: var openArray[tuple[first, last: int]],
                 start = 0): tuple[first, last: int] =
  ## returns the starting position and end position of ``pattern`` in ``s`` 
  ## and the captured substrings in the array `matches`. 
  ## If it does not match, nothing is written into `matches` and
  ## ``(-1,0)`` is returned.
  var
    rawMatches: array[0..maxSubpatterns * 3 - 1, cint]
    res = pcre.Exec(pattern.h, pattern.e, s, len(s).cint, start.cint, 0'i32,
      cast[ptr cint](addr(rawMatches)), maxSubpatterns * 3)
  if res < 0'i32: return (-1, 0)
  for i in 1..int(res)-1:
    var a = rawMatches[i * 2]
    var b = rawMatches[i * 2 + 1]
    if a >= 0'i32: matches[i-1] = (int(a), int(b)-1)
    else: matches[i-1] = (-1,0)
  return (rawMatches[0].int, rawMatches[1].int - 1)

proc findBounds*(s: string, pattern: TRegex, 
                 start = 0): tuple[first, last: int] =
  ## returns the starting position of `pattern` in `s`. If it does not
  ## match, ``(-1,0)`` is returned.
  var
    rawMatches: array[0..3 - 1, cint]
    res = pcre.Exec(pattern.h, nil, s, len(s).cint, start.cint, 0'i32,
      cast[ptr cint](addr(rawMatches)), 3)
  if res < 0'i32: return (int(res), 0)
  return (int(rawMatches[0]), int(rawMatches[1]-1))
  
proc matchOrFind(s: string, pattern: TRegex, start, flags: cint): cint =
  var rawMatches: array [0..maxSubpatterns * 3 - 1, cint]
  result = pcre.Exec(pattern.h, pattern.e, s, len(s).cint, start, flags,
                    cast[ptr cint](addr(rawMatches)), maxSubpatterns * 3)
  if result >= 0'i32:
    result = rawMatches[1] - rawMatches[0]

proc match*(s: string, pattern: TRegex, matches: var openArray[string],
           start = 0): bool =
  ## returns ``true`` if ``s[start..]`` matches the ``pattern`` and
  ## the captured substrings in the array ``matches``. If it does not
  ## match, nothing is written into ``matches`` and ``false`` is
  ## returned.
  return matchOrFind(s, pattern, matches, start.cint, 
                     pcre.ANCHORED) == cint(s.len - start)

proc match*(s: string, pattern: TRegex, start = 0): bool =
  ## returns ``true`` if ``s[start..]`` matches the ``pattern``.
  return matchOrFind(s, pattern, start.cint, pcre.ANCHORED) == cint(s.len-start)

proc matchLen*(s: string, pattern: TRegex, matches: var openArray[string],
              start = 0): int =
  ## the same as ``match``, but it returns the length of the match,
  ## if there is no match, -1 is returned. Note that a match length
  ## of zero can happen.
  return matchOrFind(s, pattern, matches, start.cint, pcre.ANCHORED)

proc matchLen*(s: string, pattern: TRegex, start = 0): int =
  ## the same as ``match``, but it returns the length of the match,
  ## if there is no match, -1 is returned. Note that a match length
  ## of zero can happen. 
  return matchOrFind(s, pattern, start.cint, pcre.ANCHORED)

proc find*(s: string, pattern: TRegex, matches: var openArray[string],
           start = 0): int =
  ## returns the starting position of ``pattern`` in ``s`` and the captured
  ## substrings in the array ``matches``. If it does not match, nothing
  ## is written into ``matches`` and -1 is returned.
  var
    rawMatches: array[0..maxSubpatterns * 3 - 1, cint]
    res = pcre.Exec(pattern.h, pattern.e, s, len(s).cint, start.cint, 0'i32,
      cast[ptr cint](addr(rawMatches)), maxSubpatterns * 3)
  if res < 0'i32: return res
  for i in 1..int(res)-1:
    var a = rawMatches[i * 2]
    var b = rawMatches[i * 2 + 1]
    if a >= 0'i32: matches[i-1] = substr(s, int(a), int(b)-1)
    else: matches[i-1] = ""
  return rawMatches[0]

proc find*(s: string, pattern: TRegex, start = 0): int =
  ## returns the starting position of ``pattern`` in ``s``. If it does not
  ## match, -1 is returned.
  var
    rawMatches: array[0..3 - 1, cint]
    res = pcre.Exec(pattern.h, nil, s, len(s).cint, start.cint, 0'i32,
      cast[ptr cint](addr(rawMatches)), 3)
  if res < 0'i32: return res
  return rawMatches[0]
  
iterator findAll*(s: string, pattern: TRegex, start = 0): string = 
  ## Yields all matching *substrings* of `s` that match `pattern`.
  ##
  ## Note that since this is an iterator you should not modify the string you
  ## are iterating over: bad things could happen.
  var i = int32(start)
  var rawMatches: array[0..maxSubpatterns * 3 - 1, cint]
  while true:
    let res = pcre.Exec(pattern.h, pattern.e, s, len(s).cint, i, 0'i32,
      cast[ptr cint](addr(rawMatches)), maxSubpatterns * 3)
    if res < 0'i32: break
    let a = rawMatches[0]
    let b = rawMatches[1]
    yield substr(s, int(a), int(b)-1)
    i = b

proc findAll*(s: string, pattern: TRegex, start = 0): seq[string] = 
  ## returns all matching *substrings* of `s` that match `pattern`.
  ## If it does not match, @[] is returned.
  accumulateResult(findAll(s, pattern, start))

when not defined(nimhygiene):
  {.pragma: inject.}

template `=~` *(s: string, pattern: TRegex): expr = 
  ## This calls ``match`` with an implicit declared ``matches`` array that 
  ## can be used in the scope of the ``=~`` call: 
  ## 
  ## .. code-block:: nimrod
  ##
  ##   if line =~ re"\s*(\w+)\s*\=\s*(\w+)": 
  ##     # matches a key=value pair:
  ##     echo("Key: ", matches[0])
  ##     echo("Value: ", matches[1])
  ##   elif line =~ re"\s*(\#.*)":
  ##     # matches a comment
  ##     # note that the implicit ``matches`` array is different from the
  ##     # ``matches`` array of the first branch
  ##     echo("comment: ", matches[0])
  ##   else:
  ##     echo("syntax error")
  ##
  bind maxSubPatterns
  when not definedInScope(matches):
    var matches {.inject.}: array[0..MaxSubpatterns-1, string]
  match(s, pattern, matches)

# ------------------------- more string handling ------------------------------

proc contains*(s: string, pattern: TRegex, start = 0): bool =
  ## same as ``find(s, pattern, start) >= 0``
  return find(s, pattern, start) >= 0

proc contains*(s: string, pattern: TRegex, matches: var openArray[string],
              start = 0): bool =
  ## same as ``find(s, pattern, matches, start) >= 0``
  return find(s, pattern, matches, start) >= 0

proc startsWith*(s: string, prefix: TRegex): bool =
  ## returns true if `s` starts with the pattern `prefix`
  result = matchLen(s, prefix) >= 0

proc endsWith*(s: string, suffix: TRegex): bool =
  ## returns true if `s` ends with the pattern `prefix`
  for i in 0 .. s.len-1:
    if matchLen(s, suffix, i) == s.len - i: return true

proc replace*(s: string, sub: TRegex, by = ""): string =
  ## Replaces `sub` in `s` by the string `by`. Captures cannot be 
  ## accessed in `by`. Examples:
  ##
  ## .. code-block:: nimrod
  ##   "var1=key; var2=key2".replace(re"(\w+)'='(\w+)")
  ##
  ## Results in:
  ##
  ## .. code-block:: nimrod
  ##
  ##   "; "
  result = ""
  var prev = 0
  while true:
    var match = findBounds(s, sub, prev)
    if match.first < 0: break
    add(result, substr(s, prev, match.first-1))
    add(result, by)
    prev = match.last + 1
  add(result, substr(s, prev))
  
proc replacef*(s: string, sub: TRegex, by: string): string =
  ## Replaces `sub` in `s` by the string `by`. Captures can be accessed in `by`
  ## with the notation ``$i`` and ``$#`` (see strutils.`%`). Examples:
  ##
  ## .. code-block:: nimrod
  ## "var1=key; var2=key2".replacef(re"(\w+)'='(\w+)", "$1<-$2$2")
  ##
  ## Results in:
  ##
  ## .. code-block:: nimrod
  ##
  ## "var1<-keykey; val2<-key2key2"
  result = ""
  var caps: array[0..maxSubpatterns-1, string]
  var prev = 0
  while true:
    var match = findBounds(s, sub, caps, prev)
    if match.first < 0: break
    add(result, substr(s, prev, match.first-1))
    addf(result, by, caps)
    prev = match.last + 1
  add(result, substr(s, prev))
  when false:
    result = ""
    var i = 0
    var caps: array[0..maxSubpatterns-1, string]
    while i < s.len:
      var x = matchLen(s, sub, caps, i)
      if x <= 0:
        add(result, s[i])
        inc(i)
      else:
        addf(result, by, caps)
        inc(i, x)
    # substr the rest:
    add(result, substr(s, i))
  
proc parallelReplace*(s: string, subs: openArray[
                      tuple[pattern: TRegex, repl: string]]): string = 
  ## Returns a modified copy of `s` with the substitutions in `subs`
  ## applied in parallel.
  result = ""
  var i = 0
  var caps: array[0..maxSubpatterns-1, string]
  while i < s.len:
    block searchSubs:
      for j in 0..high(subs):
        var x = matchLen(s, subs[j][0], caps, i)
        if x > 0:
          addf(result, subs[j][1], caps)
          inc(i, x)
          break searchSubs
      add(result, s[i])
      inc(i)
  # copy the rest:
  add(result, substr(s, i))  
  
proc transformFile*(infile, outfile: string,
                    subs: openArray[tuple[pattern: TRegex, repl: string]]) =
  ## reads in the file `infile`, performs a parallel replacement (calls
  ## `parallelReplace`) and writes back to `outfile`. Raises ``EIO`` if an
  ## error occurs. This is supposed to be used for quick scripting.
  var x = readFile(infile).string
  writeFile(outfile, x.parallelReplace(subs))
  
iterator split*(s: string, sep: TRegex): string =
  ## Splits the string `s` into substrings.
  ##
  ## Substrings are separated by the regular expression `sep`.
  ## Examples:
  ##
  ## .. code-block:: nimrod
  ##   for word in split("00232this02939is39an22example111", re"\d+"):
  ##     writeln(stdout, word)
  ##
  ## Results in:
  ##
  ## .. code-block:: nimrod
  ##   "this"
  ##   "is"
  ##   "an"
  ##   "example"
  ##
  var
    first = 0
    last = 0
  while last < len(s):
    var x = matchLen(s, sep, last)
    if x > 0: inc(last, x)
    first = last
    while last < len(s):
      inc(last)
      x = matchLen(s, sep, last)
      if x > 0: break
    if first < last:
      yield substr(s, first, last-1)

proc split*(s: string, sep: TRegex): seq[string] =
  ## Splits the string `s` into substrings.
  accumulateResult(split(s, sep))
  
proc escapeRe*(s: string): string = 
  ## escapes `s` so that it is matched verbatim when used as a regular 
  ## expression.
  result = ""
  for c in items(s):
    case c
    of 'a'..'z', 'A'..'Z', '0'..'9', '_':
      result.add(c)
    else: 
      result.add("\\x")
      result.add(toHex(ord(c), 2))
  
const ## common regular expressions
  reIdentifier* = r"\b[a-zA-Z_]+[a-zA-Z_0-9]*\b"  ## describes an identifier
  reNatural* = r"\b\d+\b" ## describes a natural number
  reInteger* = r"\b[-+]?\d+\b" ## describes an integer
  reHex* = r"\b0[xX][0-9a-fA-F]+\b" ## describes a hexadecimal number
  reBinary* = r"\b0[bB][01]+\b" ## describes a binary number (example: 0b11101)
  reOctal* = r"\b0[oO][0-7]+\b" ## describes an octal number (example: 0o777)
  reFloat* = r"\b[-+]?[0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?\b"
    ## describes a floating point number
  reEmail* = r"\b[a-zA-Z0-9!#$%&'*+/=?^_`{|}~\-]+(?:\. &" &
             r"[a-zA-Z0-9!#$%&'*+/=?^_`{|}~-]+)" &
             r"*@(?:[a-zA-Z0-9](?:[a-zA-Z0-9-]*[a-zA-Z0-9])?\.)+" &
             r"(?:[a-zA-Z]{2}|com|org|" &
             r"net|gov|mil|biz|info|mobi|name|aero|jobs|museum)\b"
    ## describes a common email address
  reURL* = r"\b(http(s)?|ftp|gopher|telnet|file|notes|ms\-help):" &
           r"((//)|(\\\\))+[\w\d:#@%/;$()~_?\+\-\=\\\.\&]*\b"
    ## describes an URL

when isMainModule:
  assert match("(a b c)", re"\( .* \)")
  assert match("WHiLe", re("while", {reIgnoreCase}))
  
  assert "0158787".match(re"\d+")
  assert "ABC 0232".match(re"\w+\s+\d+")
  assert "ABC".match(re"\d+ | \w+")

  assert matchLen("key", re(reIdentifier)) == 3

  var pattern = re"[a-z0-9]+\s*=\s*[a-z0-9]+"
  assert matchLen("key1=  cal9", pattern) == 11
  
  assert find("_____abc_______", re"abc") == 5
  
  var matches: array[0..5, string]
  if match("abcdefg", re"c(d)ef(g)", matches, 2): 
    assert matches[0] == "d"
    assert matches[1] == "g"
  else:
    assert false
  
  if "abc" =~ re"(a)bcxyz|(\w+)":
    assert matches[1] == "abc"
  else:
    assert false
    
  assert "var1=key; var2=key2".endsWith(re"\w+=\w+")
  assert("var1=key; var2=key2".replacef(re"(\w+)=(\w+)", "$1<-$2$2") ==
         "var1<-keykey; var2<-key2key2")
  assert("var1=key; var2=key2".replace(re"(\w+)=(\w+)", "$1<-$2$2") ==
         "$1<-$2$2; $1<-$2$2")

  for word in split("00232this02939is39an22example111", re"\d+"):
    writeln(stdout, word)

  for x in findAll("abcdef", re"^{.}", 3):
    assert x == "d"
  for x in findAll("abcdef", re".", 3):
    echo x
