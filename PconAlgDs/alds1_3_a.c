/*
 * Stack
 */
#include "./pcon.h"
#define MAX 100

#define S_OK        0
#define S_UNDERFLOW 1
#define S_OVERFLOW  2

typedef struct stack Stack;
struct stack {
  int *s;
  int size;
  int top;
  int status;
};

int *
initialize(Stack *s, int size)
{
  s->s = calloc(size, sizeof(int));
  if (s->s == NULL)
    return ((int *) ERROR);
  s->size = size;
  s->top = 0;
  s->status = S_OK;
  return (s->s);
}

int
isEmpty(Stack *s)
{
  if (s->top == 0)
    return (TRUE);
  return (FALSE);
}

int
isFull(Stack *s)
{
  if (s->top >= s->size)
    return (TRUE);
  return (FALSE);
}

int
push(Stack *s, int val)
{
  if (s->top >= s->size) {
    s->status = S_OVERFLOW;
    return (ERROR);
  }
  s->status = OK;
  s->s[s->top++] = val;
  return (OK);
}

int
pop(Stack *s)
{
  if (s->top == 0) {
    s->status = S_UNDERFLOW;
    return (ERROR);
  }
  s->status = OK;
  return (s->s[--(s->top)]);
}

int
main(int argc, char *argv[])
{
  int a, b, c;
  Stack s;
  char str[MAX];

  initialize(&s, MAX);

  while (scanf("%s", str) != EOF) {
    switch (str[0]) {
    case '+':
    case '-':
    case '*':
      a = pop(&s);
      b = pop(&s);
      if (str[0] == '+')
	c = a + b;
      else if (str[0] == '-')
	c = a - b;
      else
	c = a * b;
      push(&s, c);
      break;
    default:
      push(&s, atoi(str));
      break;
    }
  }
  printf("%d\n", pop(&s));
   
  printf("\n");
}
