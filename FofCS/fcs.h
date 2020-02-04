/*
 * Foundatation of Computer Science
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct CELL *LIST;
struct CELL {
  int element;
  LIST next;
};

/* Chapter 02 */
void SelectionSort(int *, int);
LIST merge(LIST, LIST);
LIST split(LIST);
LIST MergeSort(LIST);
void PrintList(LIST);


/*
 * Tools
 */
LIST makeList(int *, int);
