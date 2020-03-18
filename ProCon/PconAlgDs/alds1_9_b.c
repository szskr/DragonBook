/*
 * Maximum Heap
 */
#include "./pcon.h"

#define MAX 500000

int
parent(int id)
{
  return (id/2);
}

int
left(int id)
{
  return (2*id);
}

int
right(int id)
{
  return (2*id + 1);
}

void
maxHeapfy(int *a, int h, int i)
{
  int l, r, largest;

  l = 2 * i;
  r = 2 * i + 1;

  if (l <= h && a[l] > a[i])
    largest = l;
  else
    largest = i;

  if (r <= h && a[r] > a[largest])
    largest = r;

  if (largest != i) {
    swap(int, a[i], a[largest]);
    maxHeapfy(a, h, largest);
  }
}

int
main(int argc, char *argv[])
{
  int a[MAX+1];
  int h;
  int i, num;

  if (argc != 1)
    d_flag = 1;

  scanf("%d", &h);

  /*
   * Waste the first entry: a[0].
   */
  for (i = 1; i <= h; i++) {
    scanf("%d", &num);
    a[i] = num;
  }

  for (i = h/2; i >= 1; i--)
    maxHeapfy(a, h, i);

  for (i = 1; i <= h; i++)
    printf("%d ", a[i]);

  printf("\n");  
}
