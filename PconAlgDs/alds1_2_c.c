/*
 * Stable sort
 */
#include "./pcon.h"

#define MAX 36

typedef struct card Card;
struct card {
  char suit;
  int value;
};

void
bubble(Card *c[], int n)
{
  int i;
  int j;

  for (i = 0; i < n; i++)
    for (j = n - 1; j >= i + 1; j--)
      if (c[j]->value < c[j-1]->value)
	swap(Card *, c[j], c[j-1]);
}

void
selection(Card *c[], int n)
{
  int i;
  int j;
  int minj;

  for (i = 0; i < n; i++) {
    minj = i;
    for (j = i; j < n; j++)
      if (c[j]->value < c[minj]->value)
	minj = j;
    swap(Card *, c[i], c[minj]);
  }
}
    
void
print(Card *c[], int n)
{
  int i;

  for (i = 0; i < n; i++)
    printf("%c%d ", c[i]->suit, c[i]->value);
  printf("\n");
}

int
isStable(Card *c1[], Card *c2[], int n)
{
  int i;
  
  for (i = 0; i < n; i++)
    if (c1[i]->suit != c2[i]->suit)
      return (FALSE);
  
  return (TRUE);
}

int
main(int argc, char *argv[])
{
  int n, i, j;
  Card c1[MAX], c2[MAX];
  Card *cp1[MAX], *cp2[MAX];
  
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf(" %c%d", &c1[i].suit, &c1[i].value);
    cp1[i] = &c1[i];
    cp2[i] = &c2[i];
  }

  for (i = 0; i < n; i++) {
    cp2[i]->suit = cp1[i]->suit;
    cp2[i]->value = cp1[i]->value;
  }

  bubble(cp1, n);
  selection(cp2, n);
  
  print(cp1, n);
  print(cp2, n);
  
  if (isStable(cp1, cp2, n))
    printf("Stable\n");
  else
    printf("Not Stable\n");

  return (0);
}

  
    
  
