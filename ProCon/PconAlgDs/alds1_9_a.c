/*
 * A Complete Binary Tree
 */
#include "./pcon.h"

#define MAX 250

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

int
main(int argc, char *argv[])
{
  int a[MAX+1];
  int h;
  int i, num;
  int id;

  if (argc != 1)
    d_flag = 1;

  scanf("%d", &h);

  for (i = 0; i < h; i++) {
    scanf("%d", &num);
    a[i] = num;
  }

  for (i = 0; i < h; i++) {
    int p, l, r;
    id = i + 1;
    printf("node %2d: key= %2d, ", id, a[i]);
    if ((p = parent(id)) >= 1)
      printf("parent key= %d, ", a[p-1]);
    if ((l = left(id)) <= h)
      printf("left key= %d, ", a[l-1]);
    if ((r = right(id)) <= h)
      printf("right key= %d, ", a[r-1]);
    printf("\n");
  }

}
