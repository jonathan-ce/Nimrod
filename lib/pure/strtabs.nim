#
#
#            Nimrod's Runtime Library
#        (c) Copyright 2012 Andreas Rumpf
#
#    See the file "copying.txt", included in this
#    distribution, for details about the copyright.
#

## The ``strtabs`` module implements an efficient hash table that is a mapping
## from strings to strings. Supports a case-sensitive, case-insensitive and
## style-insensitive mode. An efficient string substitution operator  ``%``
## for the string table is also provided.

import
  os, hashes, strutils

include "system/inclrtl"

type
  TStringTableMode* = enum    ## describes the tables operation mode
    modeCaseSensitive,        ## the table is case sensitive
    modeCaseInsensitive,      ## the table is case insensitive
    modeStyleInsensitive      ## the table is style insensitive
  TKeyValuePair = tuple[key, val: string]
  TKeyValuePairSeq = seq[TKeyValuePair]
  TStringTable* = object of TObject
    counter: int
    data: TKeyValuePairSeq
    mode: TStringTableMode

  PStringTable* = ref TStringTable ## use this type to declare string tables

proc len*(t: PStringTable): int {.rtl, extern: "nst$1".} =
  ## returns the number of keys in `t`.
  result = t.counter

iterator pairs*(t: PStringTable): tuple[key, value: string] =
  ## iterates over every (key, value) pair in the table `t`.
  for h in 0..high(t.data):
    if not isNil(t.data[h].key):
      yield (t.data[h].key, t.data[h].val)

iterator keys*(t: PStringTable): string =
  ## iterates over every key in the table `t`.
  for h in 0..high(t.data):
    if not isNil(t.data[h].key):
      yield t.data[h].key

iterator values*(t: PStringTable): string =
  ## iterates over every value in the table `t`.
  for h in 0..high(t.data):
    if not isNil(t.data[h].key):
      yield t.data[h].val

type
  TFormatFlag* = enum         ## flags for the `%` operator
    useEnvironment,           ## use environment variable if the ``$key``
                              ## is not found in the table
    useEmpty,                 ## use the empty string as a default, thus it
                              ## won't throw an exception if ``$key`` is not
                              ## in the table
    useKey                    ## do not replace ``$key`` if it is not found
                              ## in the table (or in the environment)

# implementation

const
  growthFactor = 2
  startSize = 64

proc myhash(t: PStringTable, key: string): THash =
  case t.mode
  of modeCaseSensitive: result = hashes.hash(key)
  of modeCaseInsensitive: result = hashes.hashIgnoreCase(key)
  of modeStyleInsensitive: result = hashes.hashIgnoreStyle(key)

proc myCmp(t: PStringTable, a, b: string): bool =
  case t.mode
  of modeCaseSensitive: result = cmp(a, b) == 0
  of modeCaseInsensitive: result = cmpIgnoreCase(a, b) == 0
  of modeStyleInsensitive: result = cmpIgnoreStyle(a, b) == 0

proc mustRehash(length, counter: int): bool =
  assert(length > counter)
  result = (length * 2 < counter * 3) or (length - counter < 4)

proc nextTry(h, maxHash: THash): THash {.inline.} =
  result = ((5 * h) + 1) and maxHash

proc rawGet(t: PStringTable, key: string): int =
  var h: THash = myhash(t, key) and high(t.data) # start with real hash value
  while not isNil(t.data[h].key):
    if mycmp(t, t.data[h].key, key):
      return h
    h = nextTry(h, high(t.data))
  result = - 1

proc `[]`*(t: PStringTable, key: string): string {.rtl, extern: "nstGet".} =
  ## retrieves the value at ``t[key]``. If `key` is not in `t`, "" is returned
  ## and no exception is raised. One can check with ``hasKey`` whether the key
  ## exists.
  var index = RawGet(t, key)
  if index >= 0: result = t.data[index].val
  else: result = ""

proc mget*(t: PStringTable, key: string): var string {.
             rtl, extern: "nstTake".} =
  ## retrieves the location at ``t[key]``. If `key` is not in `t`, the
  ## ``EInvalidKey`` exception is raised.
  var index = RawGet(t, key)
  if index >= 0: result = t.data[index].val
  else: raise newException(EInvalidKey, "key does not exist: " & key)

proc hasKey*(t: PStringTable, key: string): bool {.rtl, extern: "nst$1".} =
  ## returns true iff `key` is in the table `t`.
  result = rawGet(t, key) >= 0

proc rawInsert(t: PStringTable, data: var TKeyValuePairSeq, key, val: string) =
  var h: THash = myhash(t, key) and high(data)
  while not isNil(data[h].key):
    h = nextTry(h, high(data))
  data[h].key = key
  data[h].val = val

proc enlarge(t: PStringTable) =
  var n: TKeyValuePairSeq
  newSeq(n, len(t.data) * growthFactor)
  for i in countup(0, high(t.data)):
    if not isNil(t.data[i].key): RawInsert(t, n, t.data[i].key, t.data[i].val)
  swap(t.data, n)

proc `[]=`*(t: PStringTable, key, val: string) {.rtl, extern: "nstPut".} =
  ## puts a (key, value)-pair into `t`.
  var index = RawGet(t, key)
  if index >= 0:
    t.data[index].val = val
  else:
    if mustRehash(len(t.data), t.counter): Enlarge(t)
    RawInsert(t, t.data, key, val)
    inc(t.counter)

proc raiseFormatException(s: string) =
  var e: ref EInvalidValue
  new(e)
  e.msg = "format string: key not found: " & s
  raise e

proc getValue(t: PStringTable, flags: set[TFormatFlag], key: string): string =
  if hasKey(t, key): return t[key]
  # hm difficult: assume safety in taint mode here. XXX This is dangerous!
  if useEnvironment in flags: result = os.getEnv(key).string
  else: result = ""
  if result.len == 0:
    if useKey in flags: result = '$' & key
    elif not (useEmpty in flags): raiseFormatException(key)

proc newStringTable*(mode: TStringTableMode): PStringTable {.
  rtl, extern: "nst$1".} =
  ## creates a new string table that is empty.
  new(result)
  result.mode = mode
  result.counter = 0
  newSeq(result.data, startSize)

proc newStringTable*(keyValuePairs: varargs[string],
                     mode: TStringTableMode): PStringTable {.
  rtl, extern: "nst$1WithPairs".} =
  ## creates a new string table with given key value pairs.
  ## Example::
  ##   var mytab = newStringTable("key1", "val1", "key2", "val2",
  ##                              modeCaseInsensitive)
  result = newStringTable(mode)
  var i = 0
  while i < high(keyValuePairs):
    result[keyValuePairs[i]] = keyValuePairs[i + 1]
    inc(i, 2)

proc newStringTable*(keyValuePairs: varargs[tuple[key, val: string]],
                     mode: TStringTableMode = modeCaseSensitive): PStringTable {.
  rtl, extern: "nst$1WithTableConstr".} =
  ## creates a new string table with given key value pairs.
  ## Example::
  ##   var mytab = newStringTable({"key1": "val1", "key2": "val2"},
  ##                              modeCaseInsensitive)
  result = newStringTable(mode)
  for key, val in items(keyvaluePairs): result[key] = val

proc `%`*(f: string, t: PStringTable, flags: set[TFormatFlag] = {}): string {.
  rtl, extern: "nstFormat".} =
  ## The `%` operator for string tables.
  const
    PatternChars = {'a'..'z', 'A'..'Z', '0'..'9', '_', '\x80'..'\xFF'}
  result = ""
  var i = 0
  while i < len(f):
    if f[i] == '$':
      case f[i+1]
      of '$':
        add(result, '$')
        inc(i, 2)
      of '{':
        var j = i + 1
        while j < f.len and f[j] != '}': inc(j)
        add(result, getValue(t, flags, substr(f, i+2, j-1)))
        i = j + 1
      of 'a'..'z', 'A'..'Z', '\x80'..'\xFF', '_':
        var j = i + 1
        while j < f.len and f[j] in PatternChars: inc(j)
        add(result, getValue(t, flags, substr(f, i+1, j-1)))
        i = j
      else:
        add(result, f[i])
        inc(i)
    else:
      add(result, f[i])
      inc(i)

proc `$`*(t: PStringTable): string {.rtl, extern: "nstDollar".} =
  ## The `$` operator for string tables.
  if t.len == 0:
    result = "{:}"
  else:
    result = "{"
    for key, val in pairs(t): 
      if result.len > 1: result.add(", ")
      result.add(key)
      result.add(": ")
      result.add(val)
    result.add("}")

when isMainModule:
  var x = {"k": "v", "11": "22", "565": "67"}.newStringTable
  assert x["k"] == "v"
  assert x["11"] == "22"
  assert x["565"] == "67"
  x.mget("11") = "23"
  assert x["11"] == "23"

