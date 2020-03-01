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

void
dump_info(Node *nodes, int i)
{
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
