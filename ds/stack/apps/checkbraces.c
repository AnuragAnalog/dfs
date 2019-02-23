#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/********* DATA-STRUCTUR DEFINITION *********/
typedef struct stack3
{
   char             info;
   struct stack3    *link;
} Lstack;
struct stack3 *top = NULL;

void push(Lstack *s, char val)
{
   Lstack        *tmp;

   tmp = (struct stack3 *) malloc(sizeof(struct stack3));

   tmp->info = val;
   tmp->link = top;
   top = tmp;

   return ;
}

char pop(Lstack *s)
{
   char                hold;
   struct stack3       *tmp;

   if (top == NULL)
   {
      printf("The stack is empty, you can't pull any item until and unless");
      printf(" you push some items.\n");
      return 0;
   }
   else
   {
      tmp = top;
      hold = tmp->info;
      top = top->link;
      free(tmp);
   }

   return hold;
}

void display(Lstack *s)
{
   struct stack3     *tmp;

   if (top == NULL)
   {
      printf("It's an empty stack can't display anything.\n");
      return ;
   }
   else
   {
      while (tmp != NULL)
      {
         printf("%c", tmp->info);
         tmp = tmp->link;
      }
      printf("\n");
   }

   return ;
}

void clearstack(Lstack *s)
{
   while (top != NULL)
   {  
      pop(s);
   }
   free(top);

   return ;
}

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int        i = 0;
   char       *string = NULL, val;
   bool       cond1, cond2, cond3;
   Lstack     s;

   if (argc != 2)
   {
      printf("Usage: %s <string>\n", argv[0]);
      exit(0);
   }

   string = argv[1];

   while (string[i] != '\0')
   {
      if (string[i] == '(' || string[i] == '[' || string[i] == '{')
      {
         push(&s, string[i]);
      }
      else if (string[i] == ')' || string[i] == ']' || string[i] == '}')
      {
         if (top == NULL)
         {
            printf("The Braces in equation are not balanced,");
            printf(" close braces are more.\n");
            exit(1);
         }

         val = pop(&s);
         cond1 = (val == '(' && string[i] == ')');
         cond2 = (val == '[' && string[i] == ']');
         cond3 = (val == '{' && string[i] == '}');

         if (cond1 || cond2 || cond3)
         {
            i++;
            continue;
         }
         else
         {
            printf("The Brackets in equation are not balanced.\n");
            exit(2);
         }
      }
      i++;
   }

   if (top != NULL)
   {
      printf("The Braces in equation are not balanced, open braces are more\n");
      exit(3);
   }
   else
   {
      printf("The Brackets in equation are balanced.\n");
   }

   clearstack(&s);
   exit(0);
}
