/*
 * Fig. 2.3
 */

#include "./fcs.h"

#define MAX 10
int A[MAX];

int
main()
{
  int i, n;

  for (n = 0; n < MAX && scanf("%d", &A[n]) != EOF; n++)
    ;
  
  SelectionSort(A, n);

  for (i = 0; i < n; i++)
    printf("%d\n", A[i]);
}
