/*
 * Fig. 2.3
 */

#include "./fcs.h"



int
main()
{
  int a[] = {10, 1, 5, 2};
  int b[] = {100, 2, 77, 17, 1};
  int c[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  LIST l1;
  LIST l2;
  LIST l3;
  LIST l4;

  l1 = makeList(a, sizeof (a)/sizeof (int));
  l2 = makeList(b, sizeof (b)/sizeof (int));
  l3 = makeList(c, sizeof (c)/sizeof (int));

  printf("Printing l1\n");
  PrintList(l1);

  printf("\nPrinting l2\n");
  PrintList(l2);

  printf("\nPrinting l3\n");
  PrintList(l3);

  l4 = split(l3);
  
  printf("\nSplit\n");
  printf("\nPrinting l3\n");
  
  PrintList(l3);
  printf("\nPrinting l4\n");
  PrintList(l4);
}
