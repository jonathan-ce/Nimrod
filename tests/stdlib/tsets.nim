discard """
  output: '''true'''
"""

import sets
var
  a = initSet[int]()
  b = initSet[int]()

for i in 0..5: a.incl(i)
for i in 1..6: b.incl(i)

echo map(a, proc(x: int): int = x + 1) == b
