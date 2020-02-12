/*
 * Doubly Linked List
 */
#include "pcon.h"

#define NODE_HEAD 0x01

typedef struct node Node;
struct node {
  int key;
  unsigned char flags;
  Node *prev;
  Node *next;
};

Node *insert_key(Node *, int);
void insert_node(Node *, Node *);
Node *find_key(Node *, int);
void remove_node(Node *);
Node *alloc_node(int);
Node *alloc_head();
void traverse_nodes(Node *);
void dump_node(Node *, char *);

Node *
insert_key(Node *node, int key)
{
  Node *n;

  n = (Node *) calloc(1, sizeof (Node));
  if (n == (Node *) NULL)
    return (n);
  n->key = key;
  n->next = node->next;
  node->next = n;
  n->prev = node;
  return (n);
}

void
insert_node(Node *np, Node *n)
{
  n->next = np->next;
  np->next = n;
  n->prev = np;
}

Node *
find_key(Node *node, int key)
{
  Node *n = node;

  do {
    if (n->flags & NODE_HEAD)
      continue;
    if (n->key == key)
      return (n);
    n = n->next;
  } while (!(n->flags & NODE_HEAD));

  /*
   * not found
   */
  return ((Node *) NULL);
}

void
remove_node(Node *node)
{
  if (node->flags & NODE_HEAD)
    return;
  node->prev->next = node->next;
  node->next->prev = node->prev;
}

Node *
alloc_node(int key)
{
  Node *node;
  
  node = (Node *)calloc(1, sizeof (Node));
  if (node == (Node *)NULL)
    return (node);
  node->key = key;
  return (node);
}

Node *
alloc_head()
{
  int key = 0;
  Node *n;
  
  n = alloc_node(key);
  if (n == (Node *) NULL)
    return (n);
  n->flags = NODE_HEAD;
  n->prev = n;
  n->next = n;
  return (n);
}

void
dump_node(Node *n, char *s)
{
  if (s)
    printf("%s\n", s);
  
  printf("TYPE = %s, ", (n->flags & NODE_HEAD) ? "HEAD" : "KEY ");
  printf("key  = %d\n", n->key);
}

void
traverse_nodes(Node *n)
{
  int cnt = 0;

  printf("TRAVER_NODES():\n");
  while (!(n->flags & NODE_HEAD) || (cnt == 0)) {
    dump_node(n, (char *)NULL);
    n = n->next;
    cnt++;
  }
}
  
int
main(int argc, char *argv[])
{
  Node *head;
  Node *node;

  head = alloc_head();
  insert_node(head, alloc_node(10));
  insert_node(head, alloc_node(11));
  insert_node(head, alloc_node(12));

  traverse_nodes(head);

  dump_node(head->prev, "DUMP_PREV_HEAD");
  dump_node(head->next, "DUMP_NEXT_HEAD");
  
  return (1);
}
