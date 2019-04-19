#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/********* DATA-SRUCTURE DEFINITION *********/
typedef struct lqueue
{
   int           info;
   struct lqueue *link;
} Lqueue;

bool isempty(struct lqueue **front, struct lqueue **rear)
{
   return ((*front == NULL) || (*rear == NULL));
}

int queuesize(struct lqueue **front)
{
   int             i = 0;
   struct lqueue   *tmp;

   tmp = *front;
   while (tmp != NULL)
   {
      tmp = tmp->link;
      i++;
   }

   return i;
}

void enqueue(int val, struct lqueue **front, struct lqueue **rear)
{
   struct lqueue        *tmp;

   tmp = (struct lqueue *)malloc(sizeof(struct lqueue));

   tmp->info = val;
   tmp->link = NULL;

   if (*front == NULL || *rear == NULL)
   {
      *front = tmp;
   }
   else
   {
      (*rear)->link = tmp;
   }
   *rear = tmp;

   return ;
}

int dequeue(struct lqueue **front, struct lqueue **rear)
{
   int        hold;

   if (isempty(front, rear))
   {
      printf("There are no elements to delete.\n");
      return -1;
   }
   else
   {
      hold = (*front)->info;
      *front = (*front)->link;
   }

   return hold;
}

void clearqueue(struct lqueue **front, struct lqueue **rear)
{
   while (*front != NULL)
   {
      dequeue(front, rear);
   }

   free(*front);
   free(*rear);

   return ;
}

void swapnames(Lqueue **f1, Lqueue **f2, Lqueue **r1, Lqueue **r2)
{
   struct lqueue *tf, *tr;

   tf = *f1;
   *f1 = *f2;
   *f2 = tf;

   tr = *r1;
   *r1 = *r2;
   *r2 = tr;

   return ;
}

void push(Lqueue **f1, Lqueue **r1, int val)
{
   enqueue(val, f1, r1);
   return ;
}

int pop(Lqueue **f1, Lqueue **f2, Lqueue **r1, Lqueue **r2)
{
   int         tmp, i = 0, len = queuesize(f1);

   while (i < len-1)
   {
      tmp = dequeue(f1, r1);
      enqueue(tmp, f2, r2);
      i = i + 1;
   }

   tmp = dequeue(f1, r1);
   swapnames(f1, f2, r1, r2);
   return tmp;
}

/********* MAIN STARTS HERE *********/
int main(void)
{
   int         i, num;
   struct lqueue *f1 = NULL, *r1 = NULL, *f2 = NULL, *r2 = NULL;

   for (i = 0; i < 5; i++)
   {
      push(&f1, &r1, i);
   }

   for (i = 0; i < 5; i++)
   {
      num = pop(&f1, &f2, &r1, &r2);
      printf("%d is the number.\n", num);
   }

   clearqueue(&f1, &r1);
   clearqueue(&f2, &r2);

   exit(0);
}
