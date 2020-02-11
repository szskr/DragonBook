/*
 * Queue
 */
#include "pcon.h"

#define LEN 100
#define min(_x_, _y_) (_x_ > _y_) ? _y_ : _x_

typedef struct proc Proc;
typedef struct queue Queue;

struct proc {
  char name[LEN];
  int t;
};

struct queue {
  Proc **procs;
  int size;
  int head;
  int tail;
  int cnt;
};

int
isFull(Queue *q)
{
  if (q->cnt == q->size) 
    return (TRUE);
  return (FALSE);
}

int
isEmpty(Queue *q)
{
  if (q->cnt == 0)
    return (TRUE);
  return (FALSE);
}

Queue *
alloc_queue(int size) {
  Queue *q;
  q = (Queue *) calloc (1, sizeof (Queue));
  if (q == (Queue *) NULL) 
    return (q);

  q->procs = (Proc **) calloc (size, sizeof (Proc *));
  if (q->procs == (Proc **) NULL) {
    free(q);
    return ((Queue *) NULL);
  }

  q->size = size;
  q->head = q->tail = 0;
  q->cnt = 0;

  return (q);
}

void
dumpQueue(Queue *q)
{
  printf("dumpQueue():\n");
  printf("\t    size = %d\n", q->size);
  printf("\thead     = %d\n", q->head);
  printf("\ttail     = %d\n", q->tail);
  printf("\tcnt      = %d\n", q->cnt);
}

int
enque(Queue *q, Proc *p)
{
  if (isFull(q)) {
    fprintf(stderr, "enque(): already full\n");
    return (ERROR);
  }
  q->procs[q->tail] = p;
  q->tail = (q->tail + 1) % q->size;
  q->cnt++;
  
  return (OK);
}

Proc *
deque(Queue *q)
{
  Proc *p;

  if (isEmpty(q)) {
    fprintf(stderr, "deque(): empty queue\n");
    return ((Proc *) NULL);
  }

  p = q->procs[q->head];
  q->head = (q->head + 1) % q->size;
  q->cnt--;
  
  return (p);
}

int
main(int argc, char *argv[])
{
  int n;
  int q;
  int elaps = 0;
  int i;
  Queue *queue;
  Proc *p;

  scanf("%d %d", &n, &q);
  queue = alloc_queue(n);
  if (queue == (Queue *) NULL) {
    fprintf(stderr, "main: alloc_queue() error\n");
    exit(1);
  }
  
  for (i = 0; i < n; i++) {
      p = (Proc *) calloc(1, sizeof (Proc));
      if (p == (Proc *) NULL) {
	fprintf(stderr, "main: calloc(Proc) error\n");
	exit(1);
      }
      scanf("%s", p->name);
      scanf("%d", &p->t);
      enque(queue, p);
  }

  while (!isEmpty(queue)) {
    p = deque(queue);
    i = min(q, p->t);
    p->t -= i;
    elaps += i;
    if (p->t > 0)
      enque(queue, p);
    else
      printf("%s %d\n", p->name, elaps);
  }
    
}
