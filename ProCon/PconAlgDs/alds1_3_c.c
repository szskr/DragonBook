/*
 * Doubly Linked List
 */
#include "pcon.h"

#define NODE_HEAD 0x01
#define FORWARD   0x01
#define BACKWARD  0x02

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
void remove_node(Node *, Node *);
Node *alloc_node(int);
Node *alloc_head();
void traverse_nodes(Node *, int);
void free_nodes(Node *);
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
  node->next->prev = n;
  node->next = n;
  n->prev = node;
  return (n);
}

void
insert_node(Node *np, Node *n)
{
  n->next = np->next;
  np->next->prev = n;
  np->next = n;
  n->prev = np;
}

Node *
find_key(Node *node, int key)
{
  Node *n = node;
  int cnt = 0;

  do {
    cnt++;
    if (n->key == key && !(n->flags & NODE_HEAD))
      return (n);
    n = n->next;
  } while (!(n->flags & NODE_HEAD));

  /*
   * not found
   */
  return ((Node *) NULL);
}

void
remove_node(Node *head, Node *node)
{
  if (!(head->flags & NODE_HEAD))
    return;
  
  if (node->flags & NODE_HEAD)
    return;

  if (!find_key(head, node->key))
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

  if (n == (Node *) NULL)
      return;
      
  printf("TYPE = %s, ", (n->flags & NODE_HEAD) ? "HEAD" : "KEY ");
  printf("key  = %d\n", n->key);
}

void
traverse_nodes(Node *n, int which)
{
  int cnt = 0;

  printf("TRAVER_NODES(%s):\n", which == FORWARD ? "forward" : "backward");
  while (!(n->flags & NODE_HEAD) || (cnt == 0)) {
    dump_node(n, (char *)NULL);
    if (which == FORWARD)
      n = n->next;
    else
      n = n->prev;
    cnt++;
  }
}

void
free_nodes(Node *head)
{
  Node *n = head;
  Node *next;
  
  while (1) {
    next  = n->next;
    free(n);
    n = next;
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

  node = find_key(head, 12);
  dump_node(node, "twelve");

  traverse_nodes(head, FORWARD);
  traverse_nodes(head, BACKWARD);
  remove_node(head, find_key(head, 11));
  traverse_nodes(head, FORWARD);
  traverse_nodes(head, BACKWARD);

  return (0);
}
