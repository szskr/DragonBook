/*
 * Binary Search
 */
#include "./pcon.h"

#define A_SIZE 10000

int binarySearch(int *, int, int);

int
binarySearch(int *a, int n, int key)
{
  int left = 0;
  int right = n;
  int mid;

  while (left < right) {
    mid = (left + right)/2;
    if (key == a[mid])
      return (1);

    if (key > a[mid])
      left = mid + 1;
    else
      right = mid;
  }
  return (0);
}

int
main(int argc, char *argv[])
{
  int a[A_SIZE];
  int i, key, n, q;
  int sum = 0;

  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &key);
    if (binarySearch(a, n, key))
      sum++;
  }
    
    printf("%d\n", sum);
}
