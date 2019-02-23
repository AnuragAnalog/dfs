#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   STACKSIZE       50

/********* DATA-STRUCTURE DEFINITION *********/
typedef struct stack
{
   int        top;
   int        item[STACKSIZE];
} Stack;

void initializestack(Stack *s)
{
   s->top = -1;
   return ;
}

int isempty(Stack *s)
{
   return s->top == -1;
}

int isfull(Stack *s)
{
   return s->top == STACKSIZE-1;
}

void push(Stack *s, int val)
{
   if (isfull(s))
   {
      printf("The stack is full, you can't push any item until and");
      printf(" unless you pop some items.\n");
      return ;
   }
   else
   {
      s->top = s->top + 1;
      s->item[s->top] = val;
   }

   return ;
}

int pull(Stack *s)
{
   int        hold;

   if (isempty(s))
   {
      printf("The stack is empty, you can't pull any item until and unless ");
      printf("you push some items.\n");
   }
   else
   {
      hold = s->item[s->top];
      s->top = s->top - 1;
   }

   return hold;
}

int stacksize(Stack *s)
{
   return s->top+1;
}

/*void clearstack(Stack *s)
{
   free(s);
   return ;
}*/

/********* MAIN STARTS HERE *********/
int main()
{
   int        i, val;
   Stack      s;

   initializestack(&s);
   for (i = 0; i < 55; i++)
   {
      if (i == 30)
      {
         printf("%d is the stack size.\n", stacksize(&s));
      }
      push(&s, i);
   }

   for (i = 0; i < 55; i++)
   {
      val = pull(&s);
      printf("%d is number.\n", val);
   }

   //clearstack(&s);

   exit(0);
}
