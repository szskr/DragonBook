/*
 * Ch.05 prog.0501
 */

#include "./fcs.h"
#define LEN_CMD 10


void
print(Tree r, char *s)
{
  printf("%s\n", s);
  printf("PreOrder : ");
  preOrder(r);
  
  printf("\n");
  printf("InOrder  : ");
  inOrder(r);
  
  printf("\n");
  printf("PostOrder: ");
  postOrder(r);
  printf("\n");
}

int
main(int argc, char *argv[])
{
  int n, i;
  int element;
  Tree node;
  Tree root = NULL;
  char cmd[LEN_CMD+1];

  if (argc != 1)
    d_flag = 1;
  
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d", &element);
    node = insert(element, root);
    if (i == 0) {
      root = node;
      continue;
    }
  }
  print(root, "Generated a binary tree");

  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%s", cmd);
    if (strcmp(cmd, "insert") == 0) {
      scanf("%d", &element);
      insert(element, root);
    } else if (strcmp(cmd, "delete") == 0) {
      scanf("%d", &element);
      delete(element, &root);
    } else if (strcmp(cmd, "print") == 0)
      print(root, "PRINT COMMAND");
    else {
      fprintf(stderr, "unknown command '%s'\n", cmd);
    }
  } 
}
    
