/*
 * Chapter 05: The Tree Data Model
 */
#include "./fcs.h"

void
preOrder(Tree t)
{
  if (t == NULL)
    return;

  printf("%d ", t->element);
  preOrder(t->leftChild);
  preOrder(t->rightChild);
}

void
inOrder(Tree t)
{
  if (t == NULL)
    return;
  inOrder(t->leftChild);
  printf("%d ", t->element);
  inOrder(t->rightChild);
}

void
postOrder(Tree t)
{
  if (t == NULL)
    return;

  postOrder(t->leftChild);
  postOrder(t->rightChild);
  printf("%d ", t->element);
}

bool
lookup(ETYPE x, Tree t)
{
  if (t == NULL)
    return false;
  else if (x == t->element)
    return (true);
  else if (x < t->element)
    return lookup(x, t->leftChild);
  else
    return (lookup(x, t->rightChild));
}

Tree
insert(ETYPE x, Tree t)
{
  if (t == NULL) {
    t = (Tree) malloc(sizeof (struct Node));
    t->element = x;
    t->leftChild = NULL;
    t->rightChild = NULL;
  }
  else if (x < t->element)
    t->leftChild = insert(x, t->leftChild);
  else if (x > t->element)
    t->rightChild = insert(x, t->rightChild);
  return (t);
}

ETYPE
deletemin(Tree *pT)
{
  ETYPE min;

  d_printf(" deletemin(): called: %d\n", (*pT)->element);

  if ((*pT)->leftChild == NULL) {
    min = (*pT)->element;
    (*pT) = (*pT)->rightChild;
    return (min);
  }
  else
    return (deletemin(&((*pT)->leftChild)));
}

void
delete(ETYPE x, Tree *pT)
{
  d_printf("delete(): %d\n", x);
  
  if ((*pT) != NULL) {
    if (x < (*pT)->element)
      delete(x, &((*pT)->leftChild));
    else if (x > (*pT)->element)
      delete(x, &((*pT)->rightChild));
  } else {
    if (d_flag)
      fprintf(stderr, "  delete: node=%d\n", x);
    if ((*pT)->leftChild == NULL)
      (*pT) = (*pT)->rightChild;
    else if ((*pT)->rightChild == NULL)
      (*pT) = (*pT)->leftChild;
    else
      (*pT)->element = deletemin(&((*pT)->rightChild));
    }
}
