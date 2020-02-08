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
main(int argc, char *argv[])
{
  int i;
  int a[MAX], n;
  G g;
  int h = 1;
 
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  /*
   * g(n) = 3*g(n-1) + 1 ==> g(n) = 3*(3**(n-1) - 1)/2 + 1
   */
  g.size = (int) (log10((double)(n+1))/LOG10_3);
  g.g = (int *) calloc(g.size+1, sizeof (int));
  g.g[0] = 1;
  for (i = 1; i < g.size; i++)
      g.g[i] = 3*g.g[i-1] + 1;
  
  printf("n = %d, g.size = %d\n", n, g.size);
  for (i = 0; i < g.size; i++)
    printf("%d ", g.g[i]);
  printf("\n");
}

