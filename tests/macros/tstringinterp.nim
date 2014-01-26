discard """
  file: "tstringinterp.nim"
  output: "Hello Alice, 64 | Hello Bob, 10$"
"""

import macros, parseutils, strutils

proc concat(strings: varargs[string]): string =
  result = newString(0)
  for s in items(strings): result.add(s)

template ProcessInterpolations(e: expr) =
  var s = e[1].strVal
  for f in interpolatedFragments(s):
    case f.kind
    of ikStr:         addString(f.value)
    of ikDollar:      addDollar()
    of ikVar, ikExpr: addExpr(newCall("$", parseExpr(f.value)))

macro formatStyleInterpolation(e: expr): expr =
  let e = callsite()
  var 
    formatString = ""
    arrayNode = newNimNode(nnkBracket)
    idx = 1

  proc addString(s: string) =
    formatString.add(s)

  proc addExpr(e: PNimrodNode) =
    arrayNode.add(e)
    formatString.add("$" & $(idx))
    inc idx

  proc addDollar() =
    formatString.add("$$")
    
  ProcessInterpolations(e)

  result = parseExpr("\"x\" % [y]")
  result[1].strVal = formatString
  result[2] = arrayNode

macro concatStyleInterpolation(e: expr): expr =
  let e = callsite()
  var args: seq[PNimrodNode]
  newSeq(args, 0)

  proc addString(s: string)    = args.add(newStrLitNode(s))
  proc addExpr(e: PNimrodNode) = args.add(e)
  proc addDollar()             = args.add(newStrLitNode"$")

  ProcessInterpolations(e)

  result = newCall("concat", args)

###

proc sum(a, b, c: int): int =
  return (a + b + c)

var 
  alice = "Alice"
  bob = "Bob"
  a = 10
  b = 20
  c = 34

var
  s1 = concatStyleInterpolation"Hello ${alice}, ${sum(a, b, c)}"
  s2 = formatStyleInterpolation"Hello ${bob}, ${sum(alice.len, bob.len, 2)}$$"

write(stdout, s1 & " | " & s2)

