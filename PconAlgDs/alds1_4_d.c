/*
 * Allocation
 */
#include "./pcon.h"

#define M_N_PACKAGES 100000  /* max number of packages */
#define M_N_CARS     100000  /* max number of cars */
#define M_WEIGHT     10000   /* max weight of a package */

int
check(llong *t, llong p)
{
  int i;
  
  return (i);
}

llong
solve(llong *t, int n)
{
  llong left = 0;
  llong right = M_N_PACKAGES * M_WEIGHT;  /* MAX total weight of packages */
  llong mid;
  int v;

  while (right - left > 1) {
    mid = (right + left)/2;
    v = check(t, mid);
    if (v >= n)
      right = mid;
    else
      left = mid;
  }
  return (right);
}

int
main(int argc, char *argv[])
{
  llong T[M_N_PACKAGES];
  llong *tp;
  llong ans;
  int i, n, k;

  scanf("%d %d", &n, &k);

  tp = T;
  for (i = 0; i < n; i++)
    scanf("%lld", tp++);

  ans = solve(T, n);
  printf("%lld\n", ans);
  return (0);
}
