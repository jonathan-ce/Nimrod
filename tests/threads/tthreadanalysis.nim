discard """
  outputsub: "101"
  msg: "Warning: write to foreign heap"
  line: 37
  cmd: "nimrod cc --hints:on --threads:on $# $#"
"""

import os

var
  thr: array [0..5, TThread[tuple[a, b: int]]]

proc doNothing() = discard

type
  PNode = ref TNode
  TNode = object {.pure.}
    le, ri: PNode
    data: string

var
  root: PNode

proc buildTree(depth: int): PNode =
  if depth == 3: return nil
  new(result)
  result.le = buildTree(depth-1)
  result.ri = buildTree(depth-1)
  result.data = $depth

proc echoLeTree(n: PNode) =
  var it: PNode
  it = nil
  it = n
  while it != nil:
    echo it.data
    it = it.le

proc threadFunc(interval: tuple[a, b: int]) {.thread.} = 
  doNothing()
  for i in interval.a..interval.b: 
    var r = buildTree(i)
    echoLeTree(r) # for local data
  echoLeTree(root) # and the same for foreign data :-)

proc main =
  root = buildTree(5)
  for i in 0..high(thr):
    createThread(thr[i], threadFunc, (i*3, i*3+2))
  joinThreads(thr)

main()

