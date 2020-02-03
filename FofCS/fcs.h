/*
 * Foundatation of Computer Science
 */
#include <stdio.h>

typedef struct CELL *LIST;
struct CELL {
  int element;
  LIST next;
};

/* Chapter 02 */
void SelectionSort(int *, int);
