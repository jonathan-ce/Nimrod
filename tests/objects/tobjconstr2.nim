type TFoo{.exportc.} = object
 x:int

var s{.exportc.}: seq[TFoo] = @[]

s.add TFoo(x: 42)

echo s[0].x


# bug #563
type
  Foo =
    object {.inheritable.}
      x: int

  Bar =
    object of Foo
      y: int

var a = Bar(y: 100, x: 200) # works
var b = Bar(x: 100, y: 200) # used to fail
