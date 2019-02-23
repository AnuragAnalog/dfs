#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
   int        i = 0, j = 0;
   char       *string = NULL, val, *postfix;
   Lstack     s;

   if (argc != 2)
   {
      printf("Usage: %s <postfix>\n", argv[0]);
      exit(0);
   }

   string = argv[1];
   postfix = (char *)calloc(strlen(string), sizeof(char));

   for (i = 0; i < strlen(string); i++)
   {
      if (string[i] >= '0' && string[i] <= '9')
      {
         postfix[j] = string[i];
         j++;
      }
      else if (string[i] == '(')
      {
         push(&s, string[i]);
      }
      else if (string[i] == ')')
      {
         val = pop(&s);
         while (val != '(')
         {
           postfix[j] = val;
           j++;
           val = pop(&s);
         }
      }
      else if (string[i] == '*' || string[i] == '/')
      {
         if (top==NULL||top->info=='('||top->info=='+'||top->info=='-')
         {
            push(&s, string[i]);
         }
         else
         {
            while (top->info=='*'||top->info=='/')
            {
               val = pop(&s);
               postfix[j] = val;
               j++;
               if (top == NULL)
               {
                  break;
               }
            }
            push(&s, string[i]);
         }
      }
      else if (string[i] == '+' || string[i] == '-')
      {
         if (top == NULL || top->info == '(')
         {
            push(&s, string[i]);
         }
         else
         {
            while (top->info=='*'||top->info=='/'||top->info=='+'||top->info=='-')
            {
               val = pop(&s);
               postfix[j] = val;
               j++;
               if (top == NULL)
               {
                  break;
               }
            }
            push(&s, string[i]);
         }
      }
   }

   if (top != NULL)
   {
      while (top != NULL)
      {
         val = pop(&s);
         postfix[j] = val;
         j++;
      }
   }

   printf("%s is the postfix expression of %s.\n", postfix, string);

   clearstack(&s);
   exit(0);
}
