/*
 * Quick  Sort
 */
#include "./pcon.h"

typedef struct Card Card;
struct Card {
  char suit;
  int value;
};

int
C_partition(Card **a, int p, int r)
{
  int j;
  int x = a[r]->value;
  int i = p - 1;

  for (j = p; j < r; ++j) {
    if (a[j]->value <= x) {
      ++i;
      swap(int, a[i]->value, a[j]->value);
    }
  }
  
  ++i;
  swap(int, a[i]->value, a[r]->value);
  
  return (i);
}

void
quicksort(Card **cards, int n, int p, int r)
{
  int q;

  if (p < r) { 
    q = C_partition(cards, p, r);
    quicksort(cards, n, p, q - 1);
    quicksort(cards, n, q + 1, r);
  }
}

int
main(int argc, char *argv[])
{
  int n;
  int i;
  Card **cards;
  char suit;
  int val;
  char s[10];

  if (argc != 1)
    d_flag = 1;
 
  scanf("%d", &n);
  printf("n = %d\n", n);
  
  cards = (Card **) malloc(n * sizeof (Card *));
  if (cards == (Card **) NULL)
    return (1);
  
  for (i = 0; i < n; i++) {
    cards[i] = (Card *) malloc (sizeof (Card));
    if (cards[i] == (Card *) NULL) {
      fprintf(stderr, "malloc() error\n");
      exit (1);
    }
    scanf("%s %d", s, &val);
    cards[i]->suit = s[0];
    cards[i]->value = val;    
  }

  if (d_flag) 
    for (i = 0; i < n; i++)
      printf("Card[%d] = (%c, %d)\n", i, cards[i]->suit, cards[i]->value);

  quicksort(cards, n, 0, n-1);

  if (d_flag) {
    printf("\n");
    for (i = 0; i < n; i++)
      printf("Card[%d] = (%c, %d)\n", i, cards[i]->suit, cards[i]->value);
  }

  return (0);
}
