#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********* DEFINED CONSTANTS *********/
#define MAX          50

/********* DATA-STRUCTURE DEFINITION *********/
typedef struct queue1
{
   int        front, rear;
   int        items[MAX];
} Queue;

void initialize(Queue *q)
{
   q->front = 0;
   q->rear = -1;
   return ;
}

int isempty(Queue *q)
{
   return q->rear < q->front;
}

int isfull(Queue *q)
{
   return q->rear == MAX-1;
}

void insert(Queue *q, int val)
{
   if (isfull(q))
   {
      printf("Queue is full, can't insert more elements.\n");
      return ;
   }
   else
   {
      q->rear++;
      q->items[q->rear] = val;
   }

   return ;
}

int delete(Queue *q)
{
   int        hold;

   if (isempty(q))
   {
      printf("Queue is empty, can't delete any elements.\n");
      return -1;
   }
   else
   {
      hold = q->items[q->front];
      q->front++;
   }

   return hold;
}

void display(Queue *q)
{
   int        i;

   if (isempty(q))
   {
      printf("Queue is empty, can't display any elements.\n");
      return ;
   }
   else
   {
      for (i = q->front; i <= q->rear; i++)
      {
         printf("%d, ", q->items[i]);
      }
      printf("\n");
   }

   return ;
}

/********* MAIN STARTS HERE *********/
int main()
{
   int       i, val;
   Queue     q;

   initialize(&q);

   for (i = 0; i < 53; i++)
   {
      insert(&q, i);
   }
   display(&q);

   for (i = 0; i < 53; i++)
   {
      val = delete(&q);
      printf("%d is the number.\n", val);
   }

   exit(0);
}
