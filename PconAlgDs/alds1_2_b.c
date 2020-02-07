/*
 * Selection Sort
 */
#include "./pcon.h"

#define MAX 100

/*
 * Simple minded sorting
 */
int
selectionSort1(int *a, int n)
{
  int i;
  int j;
  int sw = 0;

  for (i = 0; i < n; i++) {
     for (j = i; j < n; j++) {
       if (a[i] > a[j]) {
	 swap(int, a[i], a[j]);
	 sw++;
       }
     }
  }
  return (sw);
}

int
selectionSort(int *a, int n)
{
  int i;
  int j;
  int sw = 0;
  int minj;

  for (i = 0; i < n - 1; i++) {
    minj = i;
    for (j = i; j < n; j++) {
      if (a[j] < a[minj])
	minj = j;
    }
    swap(int, a[i], a[minj]);
    if (i != minj)
      sw++;
  }
  return (sw);
}
	  
int
main(int argc, char *argv[])
{
  int i;
  int a[MAX], n;
  int b[MAX];
  int sw;
 
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  for (i = 0; i < n; i++)
    b[i] = a[i];
  
  sw = selectionSort1(a, n);
  for (i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n%d\n", sw);

  sw = selectionSort(b, n);
  for (i = 0; i < n; i++)
    printf("%d ", b[i]);
  printf("\n%d\n", sw);
}

