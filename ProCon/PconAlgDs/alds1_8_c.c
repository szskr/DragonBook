/*
 * Tree Traverse
 */
#include "./pcon.h"
#define CMD_LEN 10
#define INSERT  1
#define PRINT   2
#define FIND    3
#define DELETE  4

typedef struct node Node;
struct node {
  int key;
  Node *parent;
  Node *left;
  Node *right;
};

void
preOrder(Node *node)
{
  if (node == (Node *) NULL)
    return;
  printf("%2d ", node->key);
  preOrder(node->left);
  preOrder(node->right);
}

void
inOrder(Node *node)
{
  if (node == (Node *) NULL)
    return;

  inOrder(node->left);
  printf("%2d ", node->key);
  inOrder(node->right);
}

void
postOrder(Node *node)
{
  if (node == (Node *) NULL)
    return;

  postOrder(node->left);
  postOrder(node->right);
  printf("%2d ", node->key);
}
  
void
print(Node *root)
{
  printf("pre : ");
  preOrder(root);
  printf("\n");

  printf("in  : ");
  inOrder(root);
  printf("\n");

  printf("post: ");
  postOrder(root);
  printf("\n");
}

int
find(Node *root, int key)
{
  Node *node = root;

  while (node != (Node *) NULL) {
    if (node ->key == key)
      return (1);
    if (node ->key > key)
      node = node->left;
    else
      node = node->right;
  }
  
  return (0);
}

void
delete(Node *root, int key)
{
  printf("DELETE %d\n", key);
}

int
main(int argc, char *argv[])
{
  int n, i, key;
  Node *node = (Node *) NULL;
  Node *root;
  Node *nd, *prev;
  char command[CMD_LEN + 1];
  int id, l, r;
  int cmd;

  if (argc != 1)
    d_flag = 1;

  scanf("%d", &n);
  if (n <= 0) {
    fprintf(stderr, "No Nodes(%d)\n", n);
    exit(1);
  }

  for (i = 0; i < n; i++) {
    scanf("%s", command);
    if (strcmp(command, "insert") == 0)
      cmd = INSERT;
    else if (strcmp(command, "find") == 0)
      cmd = FIND;
    else if (strcmp(command, "delete") == 0)
      cmd = DELETE;
    else
      cmd = PRINT;
    
    if (cmd == PRINT) {
      print(root);
      continue;
    }
    
    scanf("%d", &key);

    if (cmd == FIND) {
      if (find(root, key))
	printf("YES: %d\n", key);
      else
	printf("NO : %d\n", key);
      continue;
    }

    if (cmd == DELETE) {
      delete(root, key);
      continue;
    }
    
    node = (Node *) calloc(1, sizeof (Node));
    if (node == (Node *) NULL) {
      fprintf(stderr, "calloc(): error\n");
      exit(1);
    }

    node->key = key;
    if (i == 0) {
      root = node;
      node->parent = node;
      continue;
    }
    
    prev = nd = root;
    while (nd) {
      prev = nd;
      if (nd->key >= key)
	nd = nd->left;
      else
	nd = nd->right;
    }
    
    node->parent = prev;
    if (prev->key >= key)
      prev->left = node;
    else
      prev->right = node;
  }

  return (0);
}
