/*
 * Shell Sort
 */
#include "./pcon.h"

typedef struct goo G;

struct goo {
  int *g;
  int size;
};

#define MAX 1000000
long long cnt;

int
compute_goo(int **g, int n)
{
  int size;
  int i;

  /*
   * g(n) = 3*g(n-1) + 1 ==> g(n) = 3*(3**(n-1) - 1)/2 + 1
   */
  size = (int) (log10((double)(2*n+1))/LOG10_3);
  *g = (int *) calloc(size+1, sizeof (int));
  if (*g == 0)
    return (0);
  
  (*g)[0] = 1;
  for (i = 1; i < size; i++)
    (*g)[i] = 3*(*g)[i-1] + 1;

  return (size+1);
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

  g.size = compute_goo(&(g.g), n);
  
  printf("n = %d, g.size = %d\n", n, g.size);
  for (i = 0; i < g.size; i++)
    printf("%d ", g.g[i]);
  printf("\n");
}

