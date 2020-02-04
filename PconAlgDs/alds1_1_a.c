/*
 * Insertion sort
 */
#include "./pcon.h"

#define MAX 1000

void
trace(int *a, int n)
{
  int i;
  for (i = 0; i < n; i++) {
    if (i > 0)
      printf(" ");
    printf("%d", a[i]);
  }
  printf("\n");
}

void
insertionSort(int *a, int n)
{
  int j, i, v;
  for (i = 0; i < n; i++) {
    v = a[i];
    j = i - 1;
    while (j >= 0 && a[j] > v) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    trace(a, n);
  }
}

int
main(int argc, char *argv[])
{
  int n, i, j;
  int a[100];
  
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  insertionSort(a, n);

  return (0);
}

  
    
  
