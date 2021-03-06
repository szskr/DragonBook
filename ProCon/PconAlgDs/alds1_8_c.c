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

Node *
find(Node *root, int key)
{
  Node *node = root;

  while (node != (Node *) NULL) {
    if (node ->key == key)
      return (node);
    if (node ->key > key)
      node = node->left;
    else
      node = node->right;
  }
  
  return (NULL);
}

Node *
find_deletemin(Node *tp)
{
  d_printf("find_deletemin(): called\n");
  
  while (tp && tp->left != NULL)
    tp = tp->left;
  return (tp);
}

void
delete(Node *tp, int key)
{
  Node *node;
  Node *min_node;

  d_printf("Deleting %d\n", key);
  
  if (tp == NULL)
    return;

  if ((node = find(tp, key)) == NULL) {
    d_printf("  DELETING: key not found\n");
    return;
  }

  /*
   * removing node is a leaf
   */
  if ((node->left == NULL) && (node->right == NULL)) {
    d_printf("  DELETING a leaf node\n");
    if (node->parent->left == node)
      node->parent->left = NULL;
    else
      node->parent->right = NULL;
    
    free (node);
    return;
  }

  /*
   * removing node has one child but not both
   */
  if (((node->left == NULL) && (node->right != NULL)) ||
      ((node->right == NULL) && (node->left != NULL))) {
    d_printf("  DELETING a node with one child\n");
    
    if (node->right != NULL) {
      if (node->parent->right == node)
	node->parent->right = node->right;
      else
	node->parent->left = node->right;
      node->right->parent = node->parent;
    } else {
      if (node->parent->right == node)
	node->parent->right = node->left;
      else
	node->parent->left = node->left;
      node->left->parent = node->parent;
    }
    
    free(node);
    return;
  }

  /*
   * removing node has both left and right children
   */
  d_printf("  DELETING a node with both children\n");
  min_node = find_deletemin(node->right);
  d_printf("    minkey = %d\n", min_node->key);
  node->key = min_node->key;

  if (min_node->right == NULL) {
    /*
     * min_node is a leaf
     */
    d_printf("    Deleting min_node which is a leaf\n");
    if (min_node->parent->left == min_node)
      min_node->parent->left = NULL;
    else
      min_node->parent->right = NULL;
    free(min_node);
    return;
  }

  d_printf("    Deleting min_key which is an internal node\n");
  if (min_node->parent->left == min_node) {
    min_node->parent->left = min_node->right;
    min_node->right->parent = min_node->parent;
  } else {
    min_node->parent->right = min_node->right;
    min_node->right->parent = min_node->parent;
  }
  free(min_node);
  return;
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
