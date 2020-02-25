/*
 * qsort usage
 */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int
comp_int_A(const void *p1, const void *p2)
{
  int *i1 = (int *)p1;
  int *i2 = (int *)p2;

  return (*i1 - *i2);
}

int
comp_int_D(const void *p1, const void *p2)
{
  int *i1 = (int *)p1;
  int *i2 = (int *)p2;

  return (*i2 - *i1);
}

int
main(int argc, char *argv[])
{
  int *nums;
  int i;
  int n;

  scanf("%d", &n);
  nums = (int *) malloc(n * sizeof (int *));
  if (nums == (int *) NULL) {
    fprintf(stderr, "malloc(): error\n");
    exit (1);
  }

  for (i = 0; i < n; i++)
    scanf("%d", nums + i);

  if (argc == 1)
    qsort(nums, n, sizeof (int), comp_int_A);
  else
    qsort(nums, n, sizeof (int), comp_int_D);

  for (i = 0; i < n; i++)
    printf("%d ", nums[i]);

  printf("\n");
  
}
