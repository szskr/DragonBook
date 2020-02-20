/*
 * combinations
 */

#include <stdio.h>
#include <stdlib.h>

void
rec(int s, int n, int *b)
{
  int i;
  
  if (s == n) {
    for (i = 0; i < n; i++)
      printf("%d ", b[i]);
    printf("\n");
    return;
  }
  
  rec(s+1, n, b);
  b[s] = 1;
  rec(s+1, n, b);
  b[s] = 0;
}

void
print_pat(int n, int *b)
{
  int i;

  for (i = 0; i < n; i++)
    b[i] = 0;

  rec(0, n, b);

  printf("back from rec()'s\n");
  for (i = 0; i < n; i++)
    printf("%d ", b[i]);
  printf("\n");
}

int
main(int argc, char *argv[])
{
  int n;
  int *b;

  if (argc == 1)
    n = 3;
  else
    n = atoi(argv[1]);
  
  b = (int *) calloc (1, n * sizeof (int));
  
  print_pat(n, b);
}
