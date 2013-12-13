#
#
#            Nimrod's Runtime Library
#        (c) Copyright 2012 Nimrod Contributors
#
#    See the file "copying.txt", included in this
#    distribution, for details about the copyright.
#

## :Author: Zahary Karadjov
##
## This module implements the standard unit testing facilities such as
## suites, fixtures and test cases as well as facilities for combinatorial 
## and randomzied test case generation (not yet available) 
## and object mocking (not yet available)
##
## It is loosely based on C++'s boost.test and Haskell's QuickTest

import
  macros

when defined(stdout):
  import os

when not defined(ECMAScript):
  import terminal

type
  TTestStatus* = enum OK, FAILED
  TOutputLevel* = enum PRINT_ALL, PRINT_FAILURES, PRINT_NONE

var 
  # XXX: These better be thread-local
  AbortOnError*: bool
  OutputLevel*: TOutputLevel
  ColorOutput*: bool
  
  checkpoints: seq[string] = @[]

template TestSetupIMPL*: stmt {.immediate, dirty.} = nil
template TestTeardownIMPL*: stmt {.immediate, dirty.} = nil

proc shouldRun(testName: string): bool =
  result = true

template suite*(name: expr, body: stmt): stmt {.immediate, dirty.} =
  block:
    template setup*(setupBody: stmt): stmt {.immediate, dirty.} =
      template TestSetupIMPL: stmt {.immediate, dirty.} = setupBody

    template teardown*(teardownBody: stmt): stmt {.immediate, dirty.} =
      template TestTeardownIMPL: stmt {.immediate, dirty.} = teardownBody

    body

proc testDone(name: string, s: TTestStatus) =
  if s == FAILED:
    program_result += 1

  if OutputLevel != PRINT_NONE and (OutputLevel == PRINT_ALL or s == FAILED):
    template rawPrint() = echo("[", $s, "] ", name, "\n")
    when not defined(ECMAScript):
      if ColorOutput and not defined(ECMAScript):
        var color = (if s == OK: fgGreen else: fgRed)
        styledEcho styleBright, color, "[", $s, "] ", fgWhite, name, "\n"
      else:
        rawPrint()
    else:
      rawPrint()
  
template test*(name: expr, body: stmt): stmt {.immediate, dirty.} =
  bind shouldRun, checkpoints, testDone

  if shouldRun(name):
    checkpoints = @[]
    var TestStatusIMPL {.inject.} = OK
    
    try:
      TestSetupIMPL()
      body

    except:
      checkpoint("Unhandled exception: " & getCurrentExceptionMsg())
      fail()

    finally:
      TestTeardownIMPL()
      testDone name, TestStatusIMPL

proc checkpoint*(msg: string) =
  checkpoints.add(msg)
  # TODO: add support for something like SCOPED_TRACE from Google Test

template fail* =
  bind checkpoints
  for msg in items(checkpoints):
    echo msg

  when not defined(ECMAScript):
    if AbortOnError: quit(1)
 
  when defined(TestStatusIMPL):
    TestStatusIMPL = FAILED
  else:
    program_result += 1

  checkpoints = @[]

macro check*(conditions: stmt): stmt {.immediate.} =
  let checked = callsite()[1]
  
  var
    argsAsgns = newNimNode(nnkStmtList)
    argsPrintOuts = newNimNode(nnkStmtList)
    counter = 0

  template asgn(a, value: expr): stmt =
    var a = value # XXX: we need "var: var" here in order to
                  # preserve the semantics of var params
  
  template print(name, value: expr): stmt =
    when compiles(string($value)):
      checkpoint(name & " was " & $value)

  proc inspectArgs(exp: PNimrodNode) =
    for i in 1 .. <exp.len:
      if exp[i].kind notin nnkLiterals:
        inc counter
        var arg = newIdentNode(":p" & ($counter))
        var argStr = exp[i].toStrLit
        if exp[i].kind in nnkCallKinds: inspectArgs(exp[i])
        argsAsgns.add getAst(asgn(arg, exp[i]))
        argsPrintOuts.add getAst(print(argStr, arg))
        exp[i] = arg

  case checked.kind
  of nnkCallKinds:
    template rewrite(call, lineInfoLit: expr, callLit: string,
                     argAssgs, argPrintOuts: stmt): stmt =
      block:
        argAssgs
        if not call:
          checkpoint(lineInfoLit & ": Check failed: " & callLit)
          argPrintOuts
          fail()
      
    var checkedStr = checked.toStrLit
    inspectArgs(checked)
    result = getAst(rewrite(checked, checked.lineinfo, checkedStr, argsAsgns, argsPrintOuts))

  of nnkStmtList:
    result = newNimNode(nnkStmtList)
    for i in countup(0, checked.len - 1):
      if checked[i].kind != nnkCommentStmt:
        result.add(newCall(!"check", checked[i]))

  else:
    template rewrite(Exp, lineInfoLit: expr, expLit: string): stmt =
      if not Exp:
        checkpoint(lineInfoLit & ": Check failed: " & expLit)
        fail()

    result = getAst(rewrite(checked, checked.lineinfo, checked.toStrLit))

template require*(conditions: stmt): stmt {.immediate, dirty.} =
  block:
    const AbortOnError {.inject.} = true
    check conditions

macro expect*(exceptions: varargs[expr], body: stmt): stmt {.immediate.} =
  let exp = callsite()
  template expectBody(errorTypes, lineInfoLit: expr,
                      body: stmt): PNimrodNode {.dirty.} =
    try:
      body
      checkpoint(lineInfoLit & ": Expect Failed, no exception was thrown.")
      fail()
    except errorTypes:
      nil

  var body = exp[exp.len - 1]

  var errorTypes = newNimNode(nnkBracket)
  for i in countup(1, exp.len - 2):
    errorTypes.add(exp[i])

  result = getAst(expectBody(errorTypes, exp.lineinfo, body))


when defined(stdout):
  ## Reading settings
  var envOutLvl = os.getEnv("NIMTEST_OUTPUT_LVL").string

  AbortOnError = existsEnv("NIMTEST_ABORT_ON_ERROR")
  ColorOutput  = not existsEnv("NIMTEST_NO_COLOR")

else:
  var envOutLvl = "" # TODO
  ColorOutput  = false

if envOutLvl.len > 0:
  for opt in countup(low(TOutputLevel), high(TOutputLevel)):
    if $opt == envOutLvl:
      OutputLevel = opt
      break
