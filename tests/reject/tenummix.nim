discard """
  file: "system.nim"
  line: 646
  errormsg: "type mismatch"
"""

type
  TE1 = enum eA, eB
  TE2 = enum eC, eD
  
assert eA != eC
