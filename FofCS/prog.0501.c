/*
 * Ch.05 prog.0501
 */

#include "./fcs.h"

void
print(Tree r, char *s)
{
  printf("%s\n", s);
  printf("PreOrder: ");
  preOrder(r);
  printf("\n");
}

int
main(int argc, char *argv[])
{
  int n, i;
  int element;
  Tree node;
  Tree root = NULL;
  
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
}
    
