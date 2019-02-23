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

char pull(Lstack *s)
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
   int        i = 0, mid, check = 0;
   char       *palindrome = NULL;
   Lstack     s;

   if (argc != 2)
   {
      printf("Usage: %s <string>\n", argv[0]);
      exit(0);
   }

   palindrome = argv[1];

   if (strlen(palindrome)/2)
   {
      mid = (int) strlen(palindrome)/2;
   }
   else
   {
      mid = strlen(palindrome)/2;
   }

   while (i < mid)
   {
      push(&s, palindrome[i]);
      i++;
   }

   if (strlen(palindrome)%2 == 1)
   {
      for (i = mid+1; i < strlen(palindrome); i++)
      {
         if (pull(&s) != palindrome[i])
         {
            check = 1;
            printf("%s is not a palindrome.\n", palindrome);
            break;
         }
      }
   }
   else
   {
      for (i = mid; i < strlen(palindrome); i++)
      {
         if (pull(&s) != palindrome[i])
         {
            check = 1;
            printf("%s is not a palindrome.\n", palindrome);
            break;
         }
      }
   }

   if (check == 0)
   {
      printf("%s is a palindrome.\n", palindrome);
   }

   clearstack(&s);
   exit(0);
}
