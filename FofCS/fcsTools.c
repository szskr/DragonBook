/*
 * Simple Tools
 */
#include "./fcs.h"

LIST
makeList(int *a, int n)
{
  LIST head, next, prev;
  int i = 0;

  if (n <= 0)
    return (NULL);

  for (i = 0; i < n; i++) {
    next = (LIST) malloc(sizeof (struct CELL));
    if (next == NULL)
      return (NULL);
    if (i == 0)
      prev = head = next;
    next->element = *a++;
    next->next = NULL;
    if (i != 0) {
      prev->next = next;
      prev = next;
    }
  }
  return (head);
}
