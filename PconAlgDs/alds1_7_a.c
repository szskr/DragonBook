/*
 * A Rooted Tree
 */
#include "./pcon.h"

#define MAX 10
#define MAX_CHILDREN 10

typedef struct node Node;
struct node {
  int id;
  Node *parent;
  int num_children;
  Node **childern;
};

int
is_root(Node *n)
{
  return (n == n->parent);
}

int
is_leaf(Node *n)
{
  return (n->num_children == 0);
}

int
is_internal_node(Node *n)
{
  return ((n->parent != n) &&
	  (n->num_children != 0));
}

Node *
alloc_node()
{
  Node *node;

  node = (Node *) calloc(1, sizeof (Node));
  return (node);
}

Node **
alloc_children(Node *node)
{
  Node **children;

  children = (Node **) calloc(MAX_CHILDREN, sizeof (Node *));
  return (children);
}

int
main(int argc, char *argv[])
{
  int n, i, j;
  Node *root;
  
  scanf("%d", &n);
  root = alloc_node();
  if (root == (Node *)NULL) {
    fprintf(stderr, "alloc(): error\n");
    return (1);
  }

  for (i = 0; i < n; i++) {
  }
  
  return (0);
}
