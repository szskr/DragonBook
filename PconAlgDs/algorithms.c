/*
 * Personal Collection of Algorithms
 */
#include "pcon.h"

int
compute_shell_strides(int **g, int n)
{
  int size;
  int i;

  /*
   * g(m) = 3*g(m-1) + 1 ==> g(m) = 3*(3**(m-1) - 1)/2 + 1
   *
   * g(m) < n ==> (3**m - 3 + 2) < 2n 
   *          ==> 3**m < 2*n + 1
   *          ==> log(3**m) < log(2*n + 1)
   *          ==> m < log(2*n+1)/log(3)
   */
  size = (int) (log10((double)(2*n+1))/LOG10_3);
  *g = (int *) calloc(size+1, sizeof (int));
  if (*g == 0) {
    fprintf(stderr, "COMPUTE_SHELL_STRIDE(): calloc() error.\n");
    return (ERROR);
  }
  
  (*g)[0] = 1;
  for (i = 1; i < size; i++)
    (*g)[i] = 3*(*g)[i-1] + 1;
  
  /*
   * double check
   */
  if ((*g)[size-1] >= n) {
    fprintf(stderr, "COMPUTE_SHELL_STRIDES(): adjusting size\n");
    (*g)[size-1] = 0;
    size--;
  }
  return (size);
}

int
partition(int *a, int p, int r)
{
  int j;
  int x = a[r];
  int i = p - 1;

  for (j = p; j < r; ++j) {
    if (a[j] <= x) {
      ++i;
      swap(int, a[i], a[j]);
    }
  }
  
  ++i;
  swap(int, a[i], a[r]);
  
  return (i);
}
