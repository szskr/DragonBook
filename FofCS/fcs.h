/*
 * Foundatation of Computer Science
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>
#include <stdarg.h>

#ifndef _ETYPE_
typedef int ETYPE;
#define _ETYPE_
#endif

int d_flag;

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
void preOrder(Tree);
void inOrder(Tree);
void postOrder(Tree);
bool lookup(ETYPE, Tree);
Tree insert(ETYPE, Tree);
Tree find(ETYPE, Tree);
ETYPE deletemin(Tree *);
void delete(ETYPE, Tree *);


/*
 * Tools
 */
void d_printf(char *, ...);
LIST makeList(int *, int);
