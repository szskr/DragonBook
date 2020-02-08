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
 
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
}
