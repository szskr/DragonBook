#include <stdio.h>
#include <stdlib.h>

void
foo(int a)
{
  printf("foo(): %d passed\n", a);
}

void
goo()
{
  printf("goo(): called\n");
}

int
hoo(int x, int z)
{
  return (x + z);
}

int
main()
{
  void (*f)();
  void (**ff)();

  ff = (void ((**)())) calloc(1, (sizeof (void (**)())) * 10);

  f = foo;

  (*f)(10);
  ff[0] = foo;
  ff[1] = goo;
  ff[2] = (void (*)()) hoo;

  f = goo;

  (*f)();
  (*ff[1])();
  (*ff[2])();
}
