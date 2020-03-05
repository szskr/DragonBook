/*
 * Foundatation of Computer Science
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ETYPE;

typedef struct CELL *LIST;
struct CELL {
  int element;
  LIST next;
};

typedef struct Node *Tree;
struct Node {
  ETYPE element;
  Tree leftChild;
  Tree rightChild;
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
