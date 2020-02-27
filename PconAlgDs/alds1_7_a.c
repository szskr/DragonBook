/*
 * A Rooted Tree
 */
#include "./pcon.h"

typedef struct node Node;
struct node {         /* left-child, right sibling representation */
  Node *parent;
  Node *child_lm;     /* left most child */
  Node *sibling_imr;  /* sibling immidiately right */
  int id;
};


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
  Node *n = nodes + i;
  char *type;
  int id;

  if (n->parent == n)
    type = "root";
  else if (n->child_lm != (Node *) NULL)
    type = "node";
  else
    type = "leaf";

   printf ("Node :%2d, parent:%2lu, dep:%d, %s, [",
	  i,
	  (n->parent - nodes),
	  depth(n),
	  type);

  if (n->child_lm != (Node *) NULL) {
    Node *c = n->child_lm;
    do {
      printf("%d,", c - nodes);
      c = c->sibling_imr;
    } while (c != c->sibling_imr);
    printf("%d", c - nodes);
   }
  printf("]");
  printf("\n");
}

int
main(int argc, char *argv[])
{
  int n, i, j;
  Node *nodes;
  
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
    int id;
    int num_child;
    int child;
    Node *nchild;
    Node *pchild;
    Node *np = nodes + i;
    
    np->child_lm = (Node *) NULL;
    pchild = (Node *) NULL;
 
    scanf("%d", &id);

    /*
     * Get the number of children
     */
    scanf("%d", &num_child);
    for (j = 0; j < num_child; j++) {
      scanf("%d", &child);
      nchild = nodes + child;
      if (j == 0)
	np->child_lm = nchild;
      nchild->parent = np;
      if (pchild != (Node *) NULL)
	pchild->sibling_imr = nchild;
      nchild->sibling_imr = nchild;
      pchild = nchild;
     }
   }

  printf("\n");
  for (i = 0; i < n; i++)
    dump_info(nodes, i);
  return (0);
}
