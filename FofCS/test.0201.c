/*
 * Fig. 2.3
 */

#include "./fcs.h"



int
main()
{
  int a[] = {10, 1, 5, 2};
  int b[] = {100, 2, 77, 17, 1};
  LIST l1;
  LIST l2;

  l1 = makeList(a, sizeof (a)/sizeof (int));
  l2 = makeList(b, sizeof (b)/sizeof (int));

  printf("Printing l1\n");
  PrintList(l1);

  printf("\nPrinting l2\n");
  PrintList(l2);
}
