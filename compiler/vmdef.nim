#
#
#           The Nimrod Compiler
#        (c) Copyright 2013 Andreas Rumpf
#
#    See the file "copying.txt", included in this
#    distribution, for details about the copyright.
#

## This module contains the type definitions for the new evaluation engine.
## An instruction is 1-2 int32s in memory, it is a register based VM.

import ast, passes, msgs, intsets

const
  byteExcess* = 128 # we use excess-K for immediates
  wordExcess* = 32768

type
  TRegister* = range[0..255]
  TDest* = range[-1 .. 255]
  TInstr* = distinct uint32

  TOpcode* = enum
    opcEof,         # end of code
    opcRet,         # return
    opcYldYoid,     # yield with no value
    opcYldVal,      # yield with a value
    
    opcAsgnInt,
    opcAsgnStr,
    opcAsgnFloat,
    opcAsgnRef,
    opcAsgnComplex,

    opcLdArr,  # a = b[c]
    opcWrArr,  # a[b] = c
    opcWrArrRef,
    opcLdObj,  # a = b.c
    opcWrObj,  # a.b = c
    opcWrObjRef,
    opcAddr,
    opcDeref,
    opcWrStrIdx,
    opcLdStrIdx, # a = b[c]
    
    opcAddInt, 
    opcAddImmInt,
    opcSubInt,
    opcSubImmInt,
    opcLenSeq,
    opcLenStr,

    opcIncl, opcExcl, opcCard, opcMulInt, opcDivInt, opcModInt,
    opcAddFloat, opcSubFloat, opcMulFloat, opcDivFloat, opcShrInt, opcShlInt,
    opcBitandInt, opcBitorInt, opcBitxorInt, opcAddu, opcSubu, opcMulu, 
    opcDivu, opcModu, opcEqInt, opcLeInt, opcLtInt, opcEqFloat, 
    opcLeFloat, opcLtFloat, opcLeu, opcLtu, opcEqRef, opcXor, 
    opcNot, opcUnaryMinusInt, opcUnaryMinusFloat, opcBitnotInt, 
    opcEqStr, opcLeStr, opcLtStr, opcEqSet, opcLeSet, opcLtSet,
    opcMulSet, opcPlusSet, opcMinusSet, opcSymdiffSet, opcConcatStr,
    opcContainsSet, opcRepr, opcSetLenStr, opcSetLenSeq,
    opcSwap, opcIsNil, opcOf,
    opcSubStr, opcConv, opcCast, opcQuit, opcReset,
    
    opcAddStrCh,
    opcAddStrStr,
    opcAddSeqElem,
    opcRangeChck,
    
    opcNAdd,
    opcNAddMultiple,
    opcNKind, 
    opcNIntVal, 
    opcNFloatVal, 
    opcNSymbol, 
    opcNIdent,
    opcNGetType,
    opcNStrVal,
    
    opcNSetIntVal,
    opcNSetFloatVal, opcNSetSymbol, opcNSetIdent, opcNSetType, opcNSetStrVal,
    opcNNewNimNode, opcNCopyNimNode, opcNCopyNimTree, opcNDel, opcGenSym,
    
    opcSlurp,
    opcGorge,
    opcParseExprToAst,
    opcParseStmtToAst,
    opcNError,
    opcNWarning,
    opcNHint,
    opcNLineInfo,
    opcEqIdent,
    opcStrToIdent,
    opcIdentToStr,
    
    opcEcho,
    opcIndCall, # dest = call regStart, n; where regStart = fn, arg1, ...
    opcIndCallAsgn, # dest = call regStart, n; where regStart = fn, arg1, ...

    opcRaise,
    opcNChild,
    opcNSetChild,
    opcNBindSym, # opcodes for the AST manipulation following
    opcCallSite,
    opcNewStr,
  
    opcTJmp,  # jump Bx if A != 0
    opcFJmp,  # jump Bx if A == 0
    opcJmp,   # jump Bx
    opcBranch,  # branch for 'case'
    opcTry,
    opcExcept,
    opcFinally,
    opcFinallyEnd,
    opcNew,
    opcNewSeq,
    opcLdNull,    # dest = nullvalue(types[Bx])
    opcLdConst,   # dest = constants[Bx]
    opcAsgnConst, # dest = copy(constants[Bx])
    opcLdGlobal,  # dest = globals[Bx]
    opcLdImmInt,  # dest = immediate value
    opcWrGlobal,
    opcWrGlobalRef,
    opcSetType,   # dest.typ = types[Bx]
    opcTypeTrait

  TBlock* = object
    label*: PSym
    fixups*: seq[TPosition]

  TEvalMode* = enum           ## reason for evaluation
    emRepl,                   ## evaluate because in REPL mode
    emConst,                  ## evaluate for 'const' according to spec
    emOptimize,               ## evaluate for optimization purposes (same as
                              ## emConst?)
    emStatic                  ## evaluate for enforced compile time eval
                              ## ('static' context)

  TSandboxFlag* = enum        ## what the evaluation engine should allow
    allowCast,                ## allow unsafe language feature: 'cast'
    allowFFI,                 ## allow the FFI
    allowInfiniteLoops        ## allow endless loops
  TSandboxFlags* = set[TSandboxFlag]

  TSlotKind* = enum   # We try to re-use slots in a smart way to
                      # minimize allocations; however the VM supports arbitrary
                      # temporary slot usage. This is required for the parameter
                      # passing implementation.
    slotEmpty,        # slot is unused
    slotFixedVar,     # slot is used for a fixed var/result (requires copy then)
    slotFixedLet,     # slot is used for a fixed param/let
    slotTempUnknown,  # slot but type unknown (argument of proc call)
    slotTempInt,      # some temporary int
    slotTempFloat,    # some temporary float
    slotTempStr,      # some temporary string
    slotTempComplex   # some complex temporary (n.sons field is used)

  PProc* = ref object
    blocks*: seq[TBlock]    # blocks; temp data structure
    slots*: array[TRegister, tuple[inUse: bool, kind: TSlotKind]]
    maxSlots*: int
    
  PCtx* = ref TCtx
  TCtx* = object of passes.TPassContext # code gen context
    code*: seq[TInstr]
    debug*: seq[TLineInfo]  # line info for every instruction; kept separate
                            # to not slow down interpretation
    globals*: PNode         # 
    constants*: PNode       # constant data
    types*: seq[PType]      # some instructions reference types (e.g. 'except')
    currentExceptionA*, currentExceptionB*: PNode
    exceptionInstr*: int # index of instruction that raised the exception
    prc*: PProc
    module*: PSym
    callsite*: PNode
    mode*: TEvalMode

  TPosition* = distinct int

  PEvalContext* = PCtx
  
proc newCtx*(module: PSym): PCtx =
  PCtx(code: @[], debug: @[],
    globals: newNode(nkStmtList), constants: newNode(nkStmtList), types: @[],
    prc: PProc(blocks: @[]), module: module)

proc refresh*(c: PCtx, module: PSym) =
  c.module = module
  c.prc = PProc(blocks: @[])

const
  firstABxInstr* = opcTJmp
  largeInstrs* = { # instructions which use 2 int32s instead of 1:
    opcSubstr, opcConv, opcCast, opcNewSeq, opcOf}
  slotSomeTemp* = slotTempUnknown
  relativeJumps* = {opcTJmp, opcFJmp, opcJmp}

template opcode*(x: TInstr): TOpcode {.immediate.} = TOpcode(x.uint32 and 0xff'u32)
template regA*(x: TInstr): TRegister {.immediate.} = TRegister(x.uint32 shr 8'u32 and 0xff'u32)
template regB*(x: TInstr): TRegister {.immediate.} = TRegister(x.uint32 shr 16'u32 and 0xff'u32)
template regC*(x: TInstr): TRegister {.immediate.} = TRegister(x.uint32 shr 24'u32)
template regBx*(x: TInstr): int {.immediate.} = (x.uint32 shr 16'u32).int
