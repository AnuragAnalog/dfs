#include <stdio.h>
#include <stdlib.h>

/********* FUNCTION DECLARATION *********/
int menu();

/********* DATA-STRUCTUR DEFINITION *********/
typedef struct scircularll
{
   int              info;
   struct scircularll  *link;
} Scircularll;

int isempty(struct scircularll **last)
{
   return (*last == NULL);
}

int llistsize(struct scircularll **last)
{
   int          size = 1;
   Scircularll  *tmp = (*last)->link;

   if (isempty(last))
   {
      printf("It's an empty list.\n");
      return size-1;
   }
   else
   {
      while (tmp != *last)
      {
         tmp = tmp->link;
         size++;
      }
   }

   return size;
}

void addbeg(int data, struct scircularll **last)
{
   Scircularll      *tmp;

   tmp = (struct scircularll *) malloc(sizeof(struct scircularll));
   tmp->info = data;

   if (*last == NULL)
   {
      *last = tmp;
      tmp->link = tmp;
   }
   else
   {
      tmp->link = (*last)->link;
      (*last)->link = tmp;
   }

   return ;
}

void addend(int data, struct scircularll **last)
{
   Scircularll     *tmp;

   tmp = (struct scircularll *) malloc(sizeof(struct scircularll));
   tmp->info = data;

   if (*last == NULL)
   {
      addbeg(data, last);
      return ;
   }
   else
   {
      tmp->link = (*last)->link;
      (*last)->link = tmp;
      *last = tmp;
   }

   return ;
}

void addafter(int data, int key, struct scircularll **last)
{
   Scircularll     *tmp, *cur;

   if (*last == NULL)
   {
      addbeg(data, last);
      return ;
   }

   cur = (*last)->link;

   while (cur != *last && cur->info != key)
   {
      cur = cur->link;
   }

   if (cur->info == key && cur == *last)
   {
      addend(data, last);
      return ;
   }
   else if (cur == *last)
   {
      printf("%d not found in the list.\n", key);
      return ;
   }
   tmp = (struct scircularll *) malloc(sizeof(struct scircularll));
   tmp->info = data;

   tmp->link = cur->link;
   cur->link = tmp;

   return ;
}

int delbeg(struct scircularll **last)
{
   int                 hold;
   struct scircularll  *tmp;

   if (isempty(last))
   {
      printf("The Linked list is empty you can't delete any nodes\n");
      return 0;
   }
   else
   {
      tmp = (*last)->link;
      hold = tmp->info;
      if (llistsize(last) == 1)
      {
         *last = NULL;
      }
      else
      {
         (*last)->link = tmp->link;
      }
      free(tmp);
   }

   return hold;
}

int delend(struct scircularll **last)
{
   int                  hold;
   struct scircularll   *cur, *pre;

   if (isempty(last))
   {
      printf("The Linked list is empty you can't delete any nodes\n");
      return 0;
   }
   else
   {
      if (llistsize(last) == 1)
      {
         hold = delbeg(last);
         return hold;
      }

      cur = (*last)->link;
      while (cur != *last)
      {
         pre = cur;
         cur = cur->link;
      }

      hold = cur->info;
      pre->link = cur->link;
      *last = pre;
      free(cur);
   }

   return hold;
}

int delafter(int key, struct scircularll **last)
{
   int                  hold;
   struct scircularll   *cur, *pre;

   if (isempty(last))
   {
      printf("The Linked list is empty you can't delete any nodes\n");
      return 0;
   }
   else
   {
      cur = (*last)->link;
      pre = (*last)->link;
      while (cur != *last && cur->info != key)
      {
         pre = cur;
         cur = cur->link;
      }

      if (cur->info != key && cur == *last)
      {
         printf("%d is not found in the list.\n", key);
         return 0;
      }
      else if (cur->info == key && cur == *last)
      {
         hold = delbeg(last);
         printf("%d deleted after %d.\n", hold, key);
         return hold;
      }

      if (pre == cur)
      {
         cur = cur->link;
         hold = cur->info;
         pre->link = cur->link;
      }
      else
      {
         cur = cur->link;
         if (cur == *last)
         {
            hold = delend(last);
            printf("%d deleted after %d.\n", hold, key);
            return hold;
         }
         hold = cur->info;
         pre->link->link = cur->link;
      }
      free(cur);
   }

   printf("%d deleted after %d.\n", hold, key);
   return hold;
}

void display(struct scircularll **last)
{
   struct scircularll     *tmp;

   if (isempty(last))
   {
      printf("It's an empty linked list can't display anything.\n");
      return ;
   }
   else
   {
      tmp = (*last)->link;
      printf("Elements of the list are:\n");
      while (tmp != *last)
      {
         printf("%d->", tmp->info);
         tmp = tmp->link;
      }
      printf("%d->", tmp->info);
      printf("NULL\n");
   }

   return ;
}

void searchlist(int val, struct scircularll **last)
{
   int                 i = 0;
   struct scircularll  *tmp;

   if (isempty(last))
   {
      printf("Nothing is there to search.\n");
      return ;
   }
   else
   {
      tmp = (*last)->link;
      while (tmp != *last)
      {
         if (tmp->info == val)
         {
            printf("%d found at location %d.\n", val, i+1);
            return ;
         }
         i++;
         tmp = tmp->link;
      }
   }

   if (tmp->info == val)
   {
      printf("%d found at location %d.\n", val, i+1);
   }
   else
   {
      printf("%d is not present in the list.\n", val);
   }
   return ;
}

void clearllist(struct scircularll **last)
{
   while (*last != NULL)
   {  
      delbeg(last);
   }
   free(*last);

   return ;
}

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int        loc, opt, val;
   struct scircularll *last = NULL;
   //Scircularll   sl;

   while (opt != 10)
   {
      opt = menu();
      system("clear");
      switch (opt)
      {
         case 1:
               printf("** Insertion at beginning **\n");
               printf("Enter the value to be inserted: ");
               scanf("%d", &val);
               addbeg(val, &last);
               printf("Element inserted at beginning.\n");
               break;
         case 2:
               printf("** Insertion at end**\n");
               printf("Enter the value to be inserted: ");
               scanf("%d", &val);
               addend(val, &last);
               printf("Element inserted at End\n");
               break;
         case 3:
               printf("** Insertion after particular value **\n");
               printf("Enter the value to be inserted: ");
               scanf("%d", &val);
               printf("Enter the key: ");
               scanf("%d", &loc);
               addafter(val, loc, &last);
               break;
         case 4:
               printf("** Deletion at beginning **\n");
               val = delbeg(&last);
               printf("%d deleted from beginning.\n", val);
               break;
         case 5:
               printf("** Deletion at end **\n");
               val = delend(&last);
               printf("%d deleted from end.\n", val);
               break;
         case 6:
               printf("** Deletion after a particular value **\n");
               printf("Enter the key: ");
               scanf("%d", &loc);
               val = delafter(loc, &last);
               break;
         case 7:
               val = llistsize(&last);
               printf("List size is %d\n", val);
               break;
         case 8:
               display(&last);
               break;
         case 9:
               printf("** Searching for element**\n");
               printf("Enter the value to be searched: ");
               scanf("%d", &val);
               searchlist(val, &last);
               break;
         case 10:
               clearllist(&last);
               printf("Hope you had a good time with my Data-structure :-)\n");
               exit(0);
         default:
               break;
      }
   }

   clearllist(&last);
   exit(0);
}

/********* FUNCTION DEFINITION *********/
int menu()
{
   int       option;

   printf("----------------------------------\n");
   printf("        Circular linked list      \n");
   printf("----------------------------------\n");
   printf("Your options are: \n");
   printf("1)  Insert node at Beginning.\n");
   printf("2)  Insert node at End.\n");
   printf("3)  Insert node after a particular position.\n");
   printf("4)  Delete node at Beginning.\n");
   printf("5)  Delete node at End.\n");
   printf("6)  Delete node after a particular position.\n");
   printf("7)  List size.\n");
   printf("8)  Display the list.\n");
   printf("9)  Search for a node.\n");
   printf("10) Exit\n");

   printf("Enter your choice: ");
   scanf("%d", &option);

   return option;
}


