/*
 * Binary Tree
 */
#include "./pcon.h"

typedef struct node Node;
struct node {     
  Node *parent;
  Node *left;
  Node *right;
};

const char str_root[] = {'r', 'o', 'o', 't', 0};
const char str_node[] = {'n', 'o', 'd', 'e', 0};
const char str_leaf[] = {'l', 'e', 'a', 'f', 0};

#define ROOT 0
#define LEFT 1
#define RIGHT 2

int
amIwhich(Node *node)
{
  if (node->parent == node)
    return (ROOT);
  else if (node == node->parent->right)
    return (RIGHT);
  else
    return (LEFT);
}

int
depth(Node *n)
{
  int d = 0;

  while (n->parent != n) {
    d++;
    n = n->parent;
  };
  return (d);
}

int
height(Node *node)
{
  int left, right, ret;
  
  if ((node == NULL) ||
      (((node->left == (Node *) -1)) && ((node->right == (Node *) -1))))
    return (0);

  left = height(node->left);
  right = height(node->right);

  if (left >= right)
    ret = 1 + left;
  else
    ret = 1 + right;
  
  return (ret);
}

void
dump_info(Node *nodes, int i)
{
  Node *n = nodes + i;
  char *type;
  int sibling = 0;
  int degree = 0;
  int which;

  if (n->parent == n)
    type = (char *) str_root;
  else if ((n->left == (Node *) -1) && (n->right == (Node *) -1))
    type = (char *) str_leaf;
  else
    type = (char *) str_node;

  if (n->left != (Node *)-1)
    ++degree;
  if (n->right != (Node *) -1)
    ++degree;

  if (type == (char *) str_root)
    sibling = -1;
  else {
    which = amIwhich(n);
    if (which == LEFT) {
      if (n->parent->right == (Node *) -1)
	sibling = -1;
      else 
	sibling = (n->parent->right - nodes);
    } else {
      if (n->parent->left == (Node *) -1)
	  sibling = -1;
      else
	sibling = (n->parent->left - nodes);
    }
  }
  
  printf ("Node :%2d, parent:%2lu, sibling: %2d, degree: %d, dep:%d, height:%d, %s",
	  i,
	  (n->parent - nodes),
	  sibling,
	  degree,
	  depth(n),
	  height(n),
	  type);

  printf("\n");
}

int
main(int argc, char *argv[])
{
  int n, i, j;
  Node *nodes;
 int id, l, r;
  
  scanf("%d", &n);
  if (n <= 0) {
    fprintf(stderr, "No Nodes(%d)\n", n);
    exit(1);
  }
  
  nodes = (Node *) calloc(n, sizeof (Node));
  if (nodes == (Node *) NULL) {
    fprintf(stderr, "calloc(): error\n");
    exit(1);
  };

  for (i = 0; i < n; i++)
    (nodes+i)->parent = nodes + i;
  
  for (i = 0; i < n; i++) {
    scanf("%d %d %d", &id, &l, &r);
    
    if (l != -1) { 
      (nodes + id)->left = nodes + l;
      (nodes + l)->parent = nodes + id;
    } else
      (nodes + id)->left = (Node *) -1;

    if (r != -1) {
      (nodes + id)->right = nodes + r;
      (nodes + r)->parent = nodes + id;
    } else
      (nodes + id)->right = (Node *) -1;
  }

  printf("\n");
  for (i = 0; i < n; i++)
    dump_info(nodes, i);
  return (0);
}
