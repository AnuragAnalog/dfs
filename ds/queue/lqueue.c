#include <stdio.h>
#include <stdlib.h>

/********* DATA-SRUCTURE DEFINITION *********/
typedef struct lqueue
{
   int           info;
   struct lqueue *link;
} Lqueue;

struct lqueue *front = NULL, *rear = NULL;

int isempty(Lqueue *q)
{
   return ((front == NULL) || (rear == NULL));
}

void enqueue(Lqueue *q, int val)
{
   struct lqueue        *tmp;

   tmp = (struct lqueue *)malloc(sizeof(struct lqueue));

   tmp->info = val;
   tmp->link = NULL;

   if (front == NULL || rear == NULL)
   {
      front = tmp;
   }
   else
   {
      rear->link = tmp;
   }
   rear = tmp;

   return ;
}

int dequeue(Lqueue *q)
{
   int        hold;

   if (isempty(q))
   {
      printf("There are no elements to delete.\n");
      return -1;
   }
   else
   {
      hold = front->info;
      front = front->link;
   }

   return hold;
}

void display(Lqueue *q)
{
   struct lqueue *tmp;

   tmp = (struct lqueue *)malloc(sizeof(struct lqueue));

   tmp = front;
   while (tmp != NULL)
   {
      printf("%d ", tmp->info);
      tmp = tmp->link;
   }
   printf("\n");

   return ;
}

void clearqueue(Lqueue *q)
{
   while (front != NULL)
   {
      dequeue(q);
   }

   free(front);
   free(rear);

   return ;
}

/********* MAIN STARTS HERE *********/
int main(void)
{
   int         i, num;
   Lqueue      q;

   for (i = 0; i < 53; i++)
   {
      enqueue(&q, i);
   }

   display(&q);

   for (i = 0; i < 56; i++)
   {
      num = dequeue(&q);
      printf("%d is the number.\n", num);
   }

   clearqueue(&q);

   exit(0);
}
