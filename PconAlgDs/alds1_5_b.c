/*
 * Merge Sort
 */
#include "./pcon.h"

# define MAX      500000

void
merge(int *a, int left, int right, int *b, int *cnt)
{
  int l_cnt = (right-left)/2 + 1;
  int r_cnt = (right-left)/2 + 1;
  int r_start = left + l_cnt;
  int i;
  int l, r;
  
  if (((right-left) % 2) == 0)
    r_cnt--;
  
  for (i = 0; i < l_cnt; i++) 
    b[left+i] = a[left+i];

  for (i = 0; i < r_cnt; i++) 
    b[r_start+i] = a[r_start+i];

  l = left;
  r = r_start;
  for (i = left; i <= right; i++) {
    ++*cnt;

    if (l_cnt && r_cnt) {
      if (b[l] > b[r]) {
	a[i] = b[r++];
	r_cnt--;
      } else {
	a[i] = b[l++];
	l_cnt--;
      }
    } else if (l_cnt) {
      a[i] = b[l++];
      l_cnt--;
    } else {
      a[i] = b[r++];
      r_cnt--;
    }
  }
}

void
mergeSort(int *a,  int left, int right, int *b, int *cnt)
{
  int mid;

  if (left < right) {
    mid = (left + right)/2;
    mergeSort(a, left, mid, b, cnt);
    mergeSort(a, mid + 1, right, b, cnt);
    merge(a, left, right, b, cnt);
  }   
}

int
main(int argc, char *argv[])
{
  int *a, *b;
  int n, i, cnt;

  scanf("%d", &n);
  a = (int *) calloc(1, n * sizeof (int));
  b = (int *) calloc(1, n * sizeof (int));
 
  if (a == NULL || b == NULL)
    return (1);

  for (i = 0; i < n; i++)
    scanf("%d", a + i);

  for (i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");

  mergeSort(a, 0, n-1, b, &cnt);

  for (i = 0; i < n; i++)
    printf("%d ", *a++);

  printf("\n%d\n", cnt);

  return (0);
}
