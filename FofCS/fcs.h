/*
 * Foundatation of Computer Science
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef _ETYPE_
typedef int ETYPE;
#define _ETYPE_
#endif

typedef struct CELL * LIST;
struct CELL {
  int element;
  LIST next;
};

typedef struct Node * Tree;
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

/* Chapter 05 */
bool lookup(ETYPE, Tree);
Tree insert(ETYPE, Tree);
ETYPE deletemin(Tree *);
void delete(ETYPE, Tree *);


/*
 * Tools
 */
LIST makeList(int *, int);
