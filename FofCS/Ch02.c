/*
 * Chapter 02 functions
 */
#include "./fcs.h"

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

/*
 * Fig. 2.24 Recursive merge
 */
LIST
merge(LIST list1, LIST list2)
{
  if (list1 == NULL)
    return (list1);
  else if (list2 == NULL)
    return (list1);
  else if (list1->element <= list2->element) {
    list1->next = merge(list1->next, list2);
    return (list1);
  } else {
    list2->next = merge(list1, list2->next);
    return (list2);
  }
}

/*
 * Fig. 2.27 Splitting a list into two equal pieces
 */
LIST
split(LIST list)
{
  LIST pSecondCell;

  if (list == NULL)
    return (NULL);
  else if (list->next == NULL)
    return (NULL);
  else {
    pSecondCell = list->next;
    list->next = pSecondCell->next;
    pSecondCell->next = split(pSecondCell->next);
    return (pSecondCell);
  }
}

void
PrintList(LIST list)
{
  while (list != NULL) {
    printf("%d\n", list->element);
    list = list->next;
  }
}

