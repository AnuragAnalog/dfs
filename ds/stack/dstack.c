#include <stdio.h>
#include <stdlib.h>

/********* DATA-STRUCTURE DEFINITION *********/
typedef struct stack
{
   int        top;
   int        *item;
} Stack;

void initializestack(Stack *s, int size)
{
   s->item = realloc(s->item, size*sizeof(int));
   s->top = -1;
   return ;
}

int isempty(Stack *s)
{
   return s->top == -1;
}

void push(Stack *s, int val, int size)
{
   if (size == 0)
   {
      s->item = realloc(s->item, size*sizeof(int));
      size = 9;
   }

   s->top = s->top + 1;
   s->item[s->top] = val;
   size = size - 1;

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

/*void clearstack(Stack *s)
{
   free(s);
   return ;
}*/

/********* MAIN STARTS HERE *********/
int main()
{
   int        i, val, size = 9;
   Stack      s;

   initializestack(&s, size);
   for (i = 0; i < 55; i++)
   {
      push(&s, i, size);
   }

   for (i = 0; i < 55; i++)
   {
      val = pull(&s);
      printf("%d is number.\n", val);
   }

   //clearstack(&s);

   exit(0);
}
