/*
 * A Fibonacci Number
 */
#include "./pcon.h"

#define MAX 100
int fibo(int *, int);
int fibo_dyn(int *, int);

int
fibo(int *a, int n)
{
  if (n == 0 || n == 1)
    return (1);

  return (fibo(a, n-1) + fibo(a, n-2));
}

int
fibo_dyn(int *a, int n)
{
  if (n == 0 || n == 1) {
    a[n] = 1;
    return (1);
  }

  if (a[n] != -1)
    return (a[n]);

  a[n] = fibo_dyn(a, n - 1) + fibo_dyn(a, n - 2);
  return (a[n]);
}

int
main(int argc, char *argv[])
{
  int *a;
  int n;
  int f1;
  int i;
  int (*fib)(int *, int);
  
  if (argc == 1)
    d_flag = 0;
  else
    d_flag = 1;

  scanf("%d", &n);

  a = malloc((n + 1) * sizeof (int));
  for (i = 0; i <= n; i++)
    a[i] = -1;

  if (d_flag == 0)
    fib = fibo;
  else
    fib = fibo_dyn;
  
  f1 = fibo_dyn(a, n);
  printf("%s: f1 = %d\n", d_flag ? "dyn ": "rec ", f1);
  
}
