#include <stdio.h>
#include <stdlib.h>

/********* DATA-STRUCTUR DEFINITION *********/
typedef struct stack3
{
   int              info;
   struct stack3    *link;
} Lstack;
struct stack3 *top = NULL;

void push(Lstack *s, int val)
{
   Lstack        *tmp;

   tmp = (struct stack3 *) malloc(sizeof(struct stack3));

   tmp->info = val;
   tmp->link = top;
   top = tmp;

   return ;
}

int pop(Lstack *s)
{
   int                hold;
   struct stack3      *tmp;

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
   int        i, op1, op2, final;
   char       *string = NULL;
   Lstack     s;

   if (argc != 2)
   {
      printf("Usage: %s <postfix expression>\n", argv[0]);
      exit(0);
   }

   string = argv[1];

   for (i = 0; string[i] != '\0'; i++)
   {
      if (string[i] >= '0' && string[i] <= '9')
      {
         push(&s, string[i]-'0');
      }
      else if (string[i]=='+'||string[i]=='-'||string[i]=='*'||string[i]=='/')
      {
         op2 = pop(&s);
         op1 = pop(&s);

         if (string[i] == '+')
         {
            final = op1 + op2;
         }
         else if (string[i] == '-')
         {
            final = op1 - op2;
         }
         else if (string[i] == '*')
         {
            final = op1 * op2;
         }
         else if (string[i] == '/')
         {
            final = op1 / op2;
         }
         push(&s, final);
      }
   }

   final = pop(&s);

   printf("Value of %s is %d.\n", string, final);

   clearstack(&s);
   exit(0);
}
