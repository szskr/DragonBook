/*
 * Tree Traverse
 */
#include "./pcon.h"

typedef struct node Node;
struct node {
  int id;
  Node *parent;
  Node *left;
  Node *right;
};

void
preOrder(Node *node)
{
  if (node == (Node *) -1)
    return;
  printf("%d ", node->id);
  preOrder(node->left);
  preOrder(node->right);
}

void
inOrder(Node *node)
{
  if (node == (Node *) -1)
    return;
  inOrder(node->left);
  printf("%d ", node->id);
  inOrder(node->right);
}

void
postOrder(Node *node)
{
  if (node == (Node *) -1)
    return;
  postOrder(node->left);
  postOrder(node->right);
  printf("%d ", node->id);
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
    (nodes + id)->id = id;
    
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

  printf("PreOrder:\n");
  preOrder(&nodes[0]);
  printf("\n");
  
  printf("InOrder:\n");
  inOrder(&nodes[0]);
  printf("\n");
  
  printf("PostOrder:\n");
  postOrder(&nodes[0]);
  printf("\n");

  printf("\n");
  return (0);
}
