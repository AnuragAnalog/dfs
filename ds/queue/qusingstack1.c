#include <stdio.h>
#include <stdlib.h>

/********* DATA-STRUCTUR DEFINITION *********/
typedef struct stack3
{
   char             info;
   struct stack3    *link;
   struct stack3    *top;
} Lstack;

void push(Lstack *s, char val)
{
   Lstack        *tmp;

   tmp = (struct stack3 *) malloc(sizeof(struct stack3));

   tmp->info = val;
   tmp->link = s->top;
   s->top = tmp;

   return ;
}

char pop(Lstack *s)
{
   char                hold;
   struct stack3       *tmp;

   if (s->top == NULL)
   {
      printf("The stack is empty, you can't pull any item until and unless");
      printf(" you push some items.\n");
      return 0;
   }
   else
   {
      tmp = s->top;
      hold = tmp->info;
      s->top = s->top->link;
      free(tmp);
   }

   return hold;
}

void enqueue(Lstack *s1, Lstack *s2, char val)
{
   char        tmp;

   while (s1->top != NULL)
   {
      tmp = pop(s1);
      push(s2, tmp);
   }

   push(s1, val);

   while (s2->top != NULL)
   {
      tmp = pop(s2);
      push(s1, tmp);
   }

   return ;
}

char dequeue(Lstack *s1)
{
   if (s1->top == NULL)
   {
      printf("Queue is empty, can't serve any item.\n");
      return 0;
   }

   return pop(s1);
}

void clearstack(Lstack *s)
{
   while (s->top != NULL)
   {  
      pop(s);
   }
   free(s->top);

   return ;
}

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int        i = 0;
   char       val;
   Lstack     s1, s2;
   s1.top = NULL, s2.top = NULL;

   for (i = 0; i < 53; i++)
   {
      enqueue(&s1, &s2, i+'0');
   }

   for (i = 0; i < 56; i++)
   {
      val = dequeue(&s1);
      printf("%c is the number.\n", val);
   }

   clearstack(&s1);
   clearstack(&s2);
   exit(0);
}
