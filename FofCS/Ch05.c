/*
 * Chapter 05: The Tree Data Model
 */
#include "./fcs.h"

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
  if ((*pT) != NULL) {
    if (x < (*pT)->element)
      delete(x, &((*pT)->leftChild));
    else if (x > (*pT)->element)
      delete(x, &((*pT)->rightChild));
  } else {
      if ((*pT)->leftChild == NULL)
	(*pT) = (*pT)->rightChild;
      else if ((*pT)->rightChild == NULL)
	(*pT) = (*pT)->leftChild;
      else
	(*pT)->element = deletemin(&((*pT)->rightChild));
    }
}
