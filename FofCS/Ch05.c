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

Tree
find(ETYPE x, Tree t)
{
  if (t == NULL)
    return NULL;
  if (x == t->element)
    return (t);
  if (x > t->element)
    return (find(x, t->rightChild));
  return (find(x, t->leftChild));
}

ETYPE
deletemin(Tree *pt)
{
  ETYPE min;

  d_printf(" deletemin(): called: %d\n", (*pt)->element);

  if ((*pt)->leftChild == NULL) {
    min = (*pt)->element;
    (*pt) = (*pt)->rightChild;
    return (min);
  }
  else
    return (deletemin(&((*pt)->leftChild)));
}

void
delete(ETYPE x, Tree *pt)
{
  d_printf("delete(): %d\n", x);

  if (*pt == NULL) {
    d_printf(" delete(): NULL tree passed.");
    return;
  }

  if (x < (*pt)->element)
    delete(x, &((*pt)->leftChild));
  else if (x > (*pt)->element)
    delete(x, &((*pt)->rightChild));
  else {
    if ((*pt)->leftChild == NULL)
      (*pt) = (*pt)->rightChild;
    else if ((*pt)->rightChild == NULL)
      (*pt) = (*pt)->leftChild;
    else
      (*pt)->element = deletemin(&((*pt)->rightChild));
  }
}
 
