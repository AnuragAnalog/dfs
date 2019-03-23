#include <stdio.h>
#include <stdlib.h>

/********* FUNCTION DECLARATION *********/
int menu();

/********* DATA-STRUCTUR DEFINITION *********/
typedef struct singlell
{
   int              info;
   struct singlell  *link;
} Singlell;

int llistsize(struct singlell **head)
{
   int        size = 0;
   Singlell   *tmp = *head;

   while (tmp != NULL)
   {
      tmp = tmp->link;
      size++;
   }

   return size;
}

int isempty(struct singlell **head)
{
   return (*head == NULL);
}

void addbeg(int data, struct singlell **head)
{
   Singlell      *tmp;

   tmp = (struct singlell *) malloc(sizeof(struct singlell));
   tmp->info = data;

   if (*head == NULL)
   {
      *head = tmp;
      tmp->link = NULL;
   }
   else
   {
      tmp->link = *head;
      *head = tmp;
   }

   return ;
}

void addend(int data, struct singlell **head)
{
   Singlell     *tmp, *tr;

   tr = *head;

   if (*head == NULL)
   {
      addbeg(data, head);
      return ;
   }

   tmp = (struct singlell *) malloc(sizeof(struct singlell));

   while (tr->link != NULL)
   {
      tr = tr->link;
   }

   tmp->info = data;
   tmp->link = NULL;
   tr->link = tmp;

   return ;
}

void addat(int data, int loc, struct singlell **head)
{
   int          i;
   Singlell     *tmp, *cur;

   cur = *head;

   if (loc <= 0 || loc > llistsize(head))
   {
      printf("Data cannot be entered at %d\n", loc);
      return ;
   }
   else
   {
      printf("Element inserted at location %d\n", loc);
      if (cur == NULL || loc == 1)
      {
         addbeg(data, head);
         return ;
      }

      tmp = (struct singlell *) malloc(sizeof(struct singlell));
      tmp->info = data;

      for (i = 1; i < loc-1; i++)
      {
         cur = cur->link;
      }

      tmp->link = cur->link;
      cur->link = tmp;
   }

   return ;
}

void addafter(int data, int key, struct singlell **head)
{
   Singlell     *tmp, *cur;

   cur = *head;

   printf("Element inserted after %d\n", key);

   tmp = (struct singlell *) malloc(sizeof(struct singlell));
   tmp->info = data;

   while (cur != NULL && cur->info != key)
   {
      cur = cur->link;
   }

   if (cur == NULL)
   {
      printf("%d is not found in the list.\n", key);
      return ;
   }

   tmp->link = cur->link;
   cur->link = tmp;

   return ;
}

int delbeg(struct singlell **head)
{
   int                 hold;
   struct singlell     *tmp;

   if (isempty(head))
   {
      printf("The Linked list is empty you can't delete any nodes\n");
      return 0;
   }
   else
   {
      tmp = *head;
      hold = tmp->info;
      *head = tmp->link;
      free(tmp);
   }

   return hold;
}

int delend(struct singlell **head)
{
   int                 hold;
   struct singlell     *cur, *pre;

   if (isempty(head))
   {
      printf("The Linked list is empty you can't delete any nodes\n");
      return 0;
   }
   else
   {
      cur = *head;
      while (cur->link != NULL)
      {
         pre = cur;
         cur = cur->link;
      }

      hold = cur->info;
      pre->link = NULL;
      free(cur);
   }

   return hold;
}

int delat(int loc, struct singlell **head)
{
   int                 i, hold;
   struct singlell     *cur, *pre;

   if (isempty(head))
   {
      printf("The Linked list is empty you can't delete any nodes\n");
      return 0;
   }
   else if (loc <= 0 || loc > llistsize(head))
   {
      printf("Data cannot be deleted at %d\n", loc);
      return -1;
   }
   else
   {
      if (loc == 1)
      {
         hold = delbeg(head);
         printf("%d deleted from location %d.\n", hold, loc);
         return hold;
      }
      else
      {
         cur = *head;
         for (i = 1; i < loc; i++)
         {
            pre = cur;
            cur = cur->link;
         }

         hold = cur->info;
         pre->link = cur->link;
         free(cur);
      }
   }

   printf("%d deleted from location %d.\n", hold, loc);
   return hold;
}

int delafter(int key, struct singlell **head)
{
   int                 hold;
   struct singlell     *cur, *pre;

   if (isempty(head))
   {
      printf("The Linked list is empty you can't delete any nodes\n");
      return 0;
   }
   else
   {
      cur = *head;
      while (cur != NULL && cur->info != key)
      {
         cur = cur->link;
      }

      if (cur == NULL)
      {
         printf("%d not found in the list.\n", key);
         return 0;
      }
      else if (cur->link == NULL)
      {
         printf("Nothing is there after %d to delete.\n", key);
         return 0;
      }
      pre = cur;
      cur = cur->link;
      hold = cur->info;
      pre->link = cur->link;
      free(cur);
   }

   printf("%d deleted after %d.\n", hold, key);
   return hold;
}

void display(struct singlell **head)
{
   struct singlell     *tmp;

   if (isempty(head))
   {
      printf("It's an empty linked list can't display anything.\n");
      return ;
   }
   else
   {
      tmp = *head;
      printf("Elements of the list are:\n");
      while (tmp != NULL)
      {
         printf("%d->", tmp->info);
         tmp = tmp->link;
      }
      printf("NULL\n");
   }

   return ;
}

void searchlist(int val, struct singlell **head)
{
   int               i = 0;
   struct singlell   *tmp;

   if (isempty(head))
   {
      printf("Nothing is there to search.\n");
      return ;
   }
   else
   {
      tmp = *head;
      while (tmp != NULL)
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

   printf("%d is not present in the list.\n", val);
   return ;
}

void clearllist(struct singlell **head)
{
   while (*head != NULL)
   {  
      delbeg(head);
   }
   free(*head);

   return ;
}

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int        loc, opt, val;
   struct singlell *head = NULL;
   //Singlell   sl;

   while (opt != 11)
   {
      opt = menu();
      system("clear");
      switch (opt)
      {
         case 1:
               printf("Enter the value to be inserted: ");
               scanf("%d", &val);
               addbeg(val, &head);
               printf("Element inserted at beginning.\n");
               break;
         case 2:
               printf("Enter the value to be inserted: ");
               scanf("%d", &val);
               addend(val, &head);
               printf("Element inserted at End\n");
               break;
         case 3:
               printf("Enter the value to be inserted: ");
               scanf("%d", &val);
               printf("Add at location: ");
               scanf("%d", &loc);
               addat(val, loc, &head);
               break;
         case 4:
               printf("Enter the value to be inserted: ");
               scanf("%d", &val);
               printf("Enter the key: ");
               scanf("%d", &loc);
               addafter(val, loc, &head);
               break;
         case 5:
               val = delbeg(&head);
               printf("%d deleted from beginning.\n", val);
               break;
         case 6:
               val = delend(&head);
               printf("%d deleted from end.\n", val);
               break;
         case 7:
               printf("Delete at the location: ");
               scanf("%d", &loc);
               delat(loc, &head);
               break;
         case 8:
               printf("Enter the key: ");
               scanf("%d", &loc);
               delafter(loc, &head);
               break;
         case 9:
               display(&head);
               break;
         case 10:
               val = llistsize(&head);
               printf("Size of the list is %d.\n", val);
               break;
         case 11:
               printf("Enter the value to be searched: ");
               scanf("%d", &val);
               searchlist(val, &head);
               break;
         case 12:
               clearllist(&head);
               printf("Hope you had a good time with my Data-structure :-)\n");
               exit(0);
         default:
               break;
      }
   }

   clearllist(&head);
   exit(0);
}

/********* FUNCTION DEFINITION *********/
int menu()
{
   int       option;

   printf("----------------------------------\n");
   printf("         Single linked list       \n");
   printf("----------------------------------\n");
   printf("Your operations are: \n");
   printf("1)  Insert node at Beginning.\n");
   printf("2)  Insert node at End.\n");
   printf("3)  Insert node at a particular position.\n");
   printf("4)  Insert node after a particular position.\n");
   printf("5)  Delete node at Beginning.\n");
   printf("6)  Delete node at End.\n");
   printf("7)  Delete node at a particular position.\n");
   printf("8)  Delete node after a particular position.\n");
   printf("9)  Display the list.\n");
   printf("10) List size.\n");
   printf("11) Search for a node.\n");
   printf("12) Exit\n");

   printf("Enter your choice: ");
   scanf("%d", &option);

   return option;
}
