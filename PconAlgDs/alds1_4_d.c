/*
 * Allocation
 */
#include "./pcon.h"

#define MAX 100000

llong
solve(llong *t)
{
  return (0);
}

int
main(int argc, char *argv[])
{
  llong T[MAX];
  llong *tp;
  llong ans;
  int i, n, k;

  scanf("%d %d", &n, &k);

  tp = T;
  for (i = 0; i < n; i++)
    scanf("%lld", tp++);

  ans = solve(T);
  printf("%lld\n", ans);
  return (0);
}
