/*
 * Maximum Profit
 */
#include "./pcon.h"

#define MAX 200000

int
main(int argc, char *argv[])
{
  int i;
  int R[MAX], n;
  int maxv = -1 * MAX;
  int minv;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &R[i]);
  }
  minv = R[0];

  for (i = 0; i < n; i++) {
    maxv = (maxv > R[i] - minv) ? maxv : R[i] - minv;
    minv = (R[i] > minv) ? minv : R[i];
  }

  printf("%d\n", maxv);
}

  
    
  
