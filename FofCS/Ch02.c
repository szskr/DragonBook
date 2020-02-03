/*
 * Chapter 02 functions
 */

/*
 * Fig 2.2 Iterative selection sort
 */
void
SelectionSort(int a[], int n)
{
  int i, j, small, temp;

  for (i = 0; i < n-1; i++) {
    small = i;
    for (j = i + 1; j < n; j++)
      if (a[j] < a[small])
	small = j;
    temp = a[small];
    a[small] = a[i];
    a[i] = small;
  }
}
