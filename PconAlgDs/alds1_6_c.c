/*
 * Quick  Sort
 */
#include "./pcon.h"

int
partition(int *a, int p, int r)
{
  int j;
  int x = a[r];
  int i = p - 1;

  printf("a[%d] = %d\n", r, a[r]);
  
  for (j = p; j < r; j++) {
    if (a[j] <= x) {
      i++;
      swap(int, a[i], a[j]);
    }
  }

  swap(int, a[++i], a[r]);
  
  return (i);
}

int
main(int argc, char *argv[])
{
  int n;
  int *a;
  int i;
  int q;

  scanf("%d", &n);
  
  a = (int *) malloc(n * sizeof (int));
  if (a == (int *) NULL)
    return (1);
  
  for (i = 0; i < n; i++)
    scanf("%d", a+i);

  q = partition(a, 0, n-1);

  for (i = 0; i < n; i++) {
    if (i)
      printf(" ");
    if (i == q)
      printf("[");
    printf("%d", a[i]);
    if (i == q)
      printf("]");
  }
  printf("\n");
  return (0);
}
