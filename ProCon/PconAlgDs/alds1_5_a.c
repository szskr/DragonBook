/*
 * Exhaustive Search
 */
#include "./pcon.h"

int
solve(int i, int m, int *a, int n)
{
  int res;

  if (m < 0 || i >= n)
    return (0);
  
  if (m == 0)
    return (1);
  
  res = solve(i + 1, m - a[i], a, n);
  
  if (res)
    return (res);
  
  res = solve(i + 1, m, a, n);
  
  return (res);
}

int
main(int argc, char *argv[])
{
  int *a;
  int n;
  int i, q, m;

  scanf("%d", &n);
  if (n < 0)
    return (1);

  a = (int *) calloc(1, (n+1) *  sizeof (int));
  if (a == (int *) NULL)
    return (1);

  for (i = 0; i < n; i++)
    scanf("%d", a+i);

  scanf("%d", &q);

  for (i = 0; i < q; i++) {
    scanf("%d", &m);
    if (solve(0, m, a, n))
      printf("yes\n");
    else
      printf("no\n");
  }
}
