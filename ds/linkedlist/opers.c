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

void reverse(struct singlell **head)
{
   struct singlell     *pre = NULL, *cur = *head, *next;

   if (isempty(head))
   {
      printf("Linked list is empty.\n");
      return ;
   }

   while (cur != NULL)
   {
      next = cur->link;
      cur->link = pre;
      pre = cur;
      cur = next;
   }

   *head = pre;

   return ;
}

void deldupinsort(struct singlell **head)
{
   struct singlell *tmp1, *tmp2, *dup;

   tmp1 = *head;

   while (tmp1 != NULL && tmp1->link != NULL)
   {
      tmp2 = tmp1->link;
      while (tmp1->info == tmp2->info)
      {
         tmp1->link = tmp2->link;
         dup = tmp2;
         tmp2 = tmp2->link;
         free(dup);
         if (tmp2 == NULL)
         {
            break;
         }
      }
      tmp1 = tmp1->link;
   }

   return ;
}

void deldups(struct singlell **head)
{
   struct singlell *tmp1 = *head, *tmp2, *dup;

   while (tmp1 != NULL && tmp1->link != NULL)
   {
      tmp2 = tmp1;
      while (tmp2->link != NULL)
      {
         if (tmp1->info == tmp2->link->info)
         {
            dup = tmp2->link;
            tmp2->link = tmp2->link->link;
            free(dup);
         }
         else
         {
            tmp2 = tmp2->link;
         }
      }
      tmp1 = tmp1->link;
   }

   return ;
}

int deletemax(struct singlell **head)
{
   int              big;
   struct singlell  *pre = *head, *cur = *head, *bign = *head, *dup;

   big = cur->info;
   while (cur != NULL)
   {
      if (big < cur->info)
      {
         bign = pre;
         big = cur->info;
      }
      pre = cur;
      cur = cur->link;
   }

   if (bign == *head)
   {
      delbeg(head);
   }
   else
   {
      dup = bign->link;
      bign->link = bign->link->link;
      free(dup);
   }

   return big;
}

void findmid1(struct singlell **head)
{
   struct singlell *tmp1 = *head, *tmp2 = *head;

   if (isempty(head))
   {
      printf("Ths list is empty.\n");
      return ;
   }

   while (tmp2 != NULL && tmp2->link != NULL)
   {
      tmp1 = tmp1->link;
      tmp2 = tmp2->link->link;
   }

   printf("%d is the middle element.\n", tmp1->info);

   return ;
}

void findmid2(struct singlell **head)
{
   int              count = 0;
   struct singlell  *tmp = *head, *mid = *head;

   if (isempty(head))
   {
      printf("The list is empty.\n");
      return ;
   }

   while (tmp != NULL)
   {
      if (count & 1)
      {
         mid = mid->link;
      }
      ++count;
      tmp = tmp->link;
   }

   if (mid != NULL)
   {
      printf("%d is the middle element.\n", mid->info);
   }

   return ;
}

void sortlist(struct singlell **head)
{
   int             tmp;
   struct singlell *check = *head, *cur;

   if (isempty(head))
   {
      printf("Linked list is empty.\n");
      return ;
   }
      
   while (check != NULL)
   {
      cur = *head;
      while (cur->link != NULL)
      {
         if (cur->info > cur->link->info)
         {
            tmp = cur->info;
            cur->info = cur->link->info;
            cur->link->info = tmp;
         }
         cur = cur->link;
      }
      check = check->link;
   }
   
   return ;
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
   int        opt, val;
   struct singlell *head = NULL;

   while (opt != 10)
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
               printf("List reversed.\n");
               reverse(&head);
               break;
         case 4:
               printf("Removed duplicates from list.\n");
               deldupinsort(&head);
               break;
         case 5:
               printf("Removed duplicates from list.\n");
               deldups(&head);
               break;
         case 6:
               printf("Deleted the maximum element.\n");
               deletemax(&head);
               break;
         case 7:
               findmid1(&head);
               break;
         case 8:
               findmid2(&head);
               break;
         case 9:
               printf("Sorted the list.\n");
               sortlist(&head);
               break;
         case 10:
               display(&head);
               break;
         case 11:
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
   printf("3)  Reverse the linked list.\n");
   printf("4)  Delete Duplicates in sorted list\n");
   printf("5)  Delete Duplicates in unsorted list\n");
   printf("6)  Delete Maximum element.\n");
   printf("7)  Find the middle element.\n");
   printf("8)  Find the middle element 2.o\n");
   printf("9)  Sort the list.\n");
   printf("10) Display the list.\n");
   printf("11) Exit\n");

   printf("Enter your choice: ");
   scanf("%d", &option);

   return option;
}
