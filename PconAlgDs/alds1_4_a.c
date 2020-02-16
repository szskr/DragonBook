/*
 * Linear Search
 */
#include "./pcon.h"

#define A_SIZE 10000

int search(int *, int , int);

int
search(int *a, int n, int key)
{
  int i = 0;
  a[n] = key;

  while (a[i] != key)
    ++i;

  return (i = n);
}

int
main(int argc, char *argv[])
{
  int i, n, a[A_SIZE + 1];
  int key, q;
  int sum = 0;

  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &key);
    if (search(a, n, key))
      sum++;
  }
    
    printf("%d\n", sum);
}
