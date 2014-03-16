discard """
  file: "tstaticparams.nim"
  output: "abracadabra\ntest\n3\n15\n4\n2"
"""

type 
  TFoo[T; Val: static[string]] = object
    data: array[4, T]

  TBar[T; I: static[int]] = object
    data: array[I, T]

  TA1[T; I: static[int]] = array[I, T]
  TA2[T; I: static[int]] = array[0..I, T]
  TA3[T; I: static[int]] = array[I-1, T]

  TObj = object
    x: TA3[int, 3]

proc takeFoo(x: TFoo) =
  echo "abracadabra"
  echo TFoo.Val

var x: TFoo[int, "test"]
takeFoo(x)

var y: TBar[float, 4]
echo high(y.data)

var
  t1: TA1[float, 1]
  t2: TA2[string, 4]
  t3: TA3[int, 10]
  t4: TObj

# example from the manual:
type
  Matrix[M,N: static[int]; T] = array[0..(M*N - 1), T]
    # Note how `Number` is just a type constraint here, while
    # `static[int]` requires us to supply a compile-time int value

  AffineTransform2D[T] = Matrix[3, 3, T]
  AffineTransform3D[T] = Matrix[4, 4, T]

var m: AffineTransform3D[float]
echo high(m)

proc getRows(mtx: Matrix): int =
  result = mtx.M

echo getRows(m)

# issue 997
type TTest[T: static[int], U: static[int]] = array[0..T*U, int]
type TTestSub[N: static[int]] = TTest[1, N]

var z: TTestSub[2]
echo z.high
