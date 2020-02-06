/*
 * Bubble Sort
 */
#include "./pcon.h"

#define MAX 100

int
bubbleSort(int *a, int n)
{
  int sw = 0;
  int flag = 1;
  int i;
  int j;

  for (i = 0; flag; i++) {
    flag = 0;
    for (j = n - 1; j >= i + 1; j--) {
      if (a[j] < a[j-1]) {
	swap(int, a[j], a[i]);
	flag = 1;
	sw++;
      }
    }
  }
  return (sw);
}
	

int
main(int argc, char *argv[])
{
  int n;
  int i;
  int a[100];
  int sw;
  
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  sw = bubbleSort(a, n);

  for (i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n%d\n", sw);

  return (0);
}

  
    
  
