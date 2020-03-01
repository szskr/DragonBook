/*
 * Shell Sort
 */
#include "./pcon.h"

typedef struct g G;

struct g {
  int *g;
  int size;
  long long cnt;
};

#define MAX 1000000

#if 0
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
#endif

void
insertionSort(int *a, int n, G *g, int idx)
{
  int i;
  int gg = g->g[idx];

  for (i = gg; i < n; i++) {
    int v = a[i];
    int j = i - gg;
    while (j >= 0 && a[j] > v) {
      a[j + gg] = a[j];
      j -= gg;
      g->cnt++;
    }
    a[j + gg] = v;
  }
}
      
void
shellSort(int *a, int n, G *g)
{
  int i;
  
  g->cnt = 0;
  g->size = compute_shell_strides(&g->g, n);

  for (i = g->size - 1; i >= 0; i--)
    insertionSort(a, n, g, i);
}
  
int
main(int argc, char *argv[])
{
  int i;
  int a[MAX], n;
  G g;
  int h = 1;

  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  shellSort(a, n, &g);
  if (g.g == (int *) ERROR) {
    fprintf(stderr, "calloc() error\n");
    exit(1);
  }
    
  for (i = g.size - 1; i >= 0; i--)
    printf("%d ", g.g[i]);

  printf("\n");
  printf("%lld\n", g.cnt);

  for (i = 0; i < n; i++) {
    if (i > 0 && i%10 == 0)
      printf("\n");
    printf("%d ", a[i]);
  }
  
  printf("\n");
}
