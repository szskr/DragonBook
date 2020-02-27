/*
 * A Rooted Tree
 */
#include "./pcon.h"

#define MAX 10
#define MAX_CHILDREN 10

typedef struct node Node;
struct node { /* left-child, right sibling representation */
  Node *parent;
  Node *child_lm;  /* left most child */
  Node *sibling_rm;  /* right most sibling */
  int id;
};

int
is_root(Node *n)
{
  return (n == (Node *) NULL);
}

int
is_leaf(Node *n)
{
  return (n->child_lm == (Node *) 0);
}

int
is_internal_node(Node *n)
{
  return ((n->parent != n) &&
	  (n->child_lm != 0));
}

void
dump_info(Node *nodes, int i)
{
  printf ("Node(%2d) id:%2d : parent %lu\n", i, nodes[i].id, (&nodes[0] - nodes[i].parent)/sizeof (Node));
}

int
main(int argc, char *argv[])
{
  int n, i, j;
  Node *nodes;
  Node **nodeps;
  
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
    nodes[i].parent = &nodes[i];
  
  nodeps = (Node **) malloc((n-1) * (sizeof (Node *)));
  if (nodeps == (Node **) NULL) {
    fprintf(stderr, "malloc(): error\n");
    exit(1);
  }
 
  for (i = 0; i < n; i++) {
    int id;
    int num_child;
    int child;

    scanf("%d", &id);
    nodes[i].id = id;

    scanf("%d", &num_child);
    printf("HANDLING (%d): num_child = %d\n", id, num_child);
    for (j = 0; j < num_child; j++) {
      scanf("%d", &child);
      printf("  Child = %d Parent = %d\n", child, id);
      nodes[child].parent = &nodes[id];
      nodeps[j] = &nodes[child];
    }

    if (num_child == 0) {
      nodes[i].child_lm = (Node *) NULL;
       } else {
       for (j = 0; j < num_child; j++) {
	nodeps[j]->sibling_rm = &nodes[num_child-1];
      }
      nodes[i].child_lm = nodeps[0];
    }
   }

  for (i = 0; i < n; i++)
    dump_info(nodes, i);
  return (0);
}
