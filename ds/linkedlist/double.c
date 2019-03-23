#include <stdio.h>
#include <stdlib.h>

/********* FUNCTION DECLARATION *********/
int menu();

/********* DATA-STRUCTURE DEFINITION *********/
typedef struct doublell
{
   int              info;
   struct doublell  *right;
   struct doublell  *left;
} Doublell;

int llistsize(struct doublell **head)
{
   int        size = 0;
   Doublell   *tmp = *head;

   while (tmp != NULL)
   {
      tmp = tmp->right;
      size++;
   }

   return size;
}

int isempty(struct doublell **head)
{
   return (*head == NULL);
}

void addbeg(int data, struct doublell **head)
{
   Doublell      *tmp;

   tmp = (struct doublell *) malloc(sizeof(struct doublell));
   tmp->info = data;

   if (*head == NULL)
   {
      tmp->right = NULL;
      tmp->left = NULL;
   }
   else
   {
      tmp->right = *head;
      tmp->right->left = tmp;
      tmp->left = NULL;
   }
   *head = tmp;

   return ;
}

void addend(int data, struct doublell **head)
{
   Doublell     *tmp, *tr;

   tr = *head;

   if (*head == NULL)
   {
      addbeg(data, head);
      return ;
   }

   tmp = (struct doublell *) malloc(sizeof(struct doublell));
   tmp->info = data;
   
   while (tr->right != NULL)
   {
      tr = tr->right;
   }

   tmp->right = NULL;
   tr->right = tmp;
   tr->right->left = tr;

   return ;
}

void addafter(int data, struct doublell **head, int key)
{
   struct doublell     *tmp, *tr = *head;

   tmp = (struct doublell *)malloc(sizeof(struct doublell));
  
   if (isempty(head))
   {
      printf("Element not found.\n");
      return ;
   }
   else
   {
      while (tr->info != key)
      {
         tr = tr->right;
         if (tr == NULL)
         {
            break;
         }
      }
      
      if (tr == NULL)
      {
         printf("Element not found.\n");
         return ;
      }
      
      if (tr->right == NULL)
      {
         addend(data, head);
         return ;
      }
      else
      {
         tmp->info = data;
         tmp->left = tr;
         tmp->right = tr->right;
         tr->right->left = tmp;
         tr->right = tmp;
      }
   }
   
   return ;
}

int delbeg(struct doublell **head)
{
   int                 hold;
   struct doublell     *tmp;

   if (isempty(head))
   {
      printf("The Linked list is empty you can't delete any nodes\n");
      return 0;
   }
   else
   {
      tmp = *head;
      hold = tmp->info;
      if (tmp->right == NULL)
      {
         *head = NULL;
      }
      else
      {
         *head = tmp->right;
         tmp->right->left = NULL;
      }
      free(tmp);
   }

   return hold;
}

int delend(struct doublell **head)
{
   int                 hold;
   struct doublell     *tr = *head;

   if (isempty(head))
   {
      printf("The Linked list is empty you can't delete any nodes\n");
      return 0;
   }
   else
   {
      while (tr->right != NULL)
      {
         tr = tr->right;
      }
      
      hold = tr->info;
      tr->left->right = NULL;
      free(tr);
   }

   return hold;
}

int delafter(struct doublell **head, int key)
{
   int                 hold;
   struct doublell     *tmp = *head, *dup;

   if (isempty(head))
   {
      printf("Can't delete any node from empty list.\n");
      return 0;
   }
   else
   {
      while (tmp->info != key)
      {
         tmp = tmp->right;
         if (tmp == NULL)
         {
            break;
         }
      }

      if (tmp == NULL)
      {
         printf("Element not found.\n");
         return 0;
      }

      if (tmp->right == NULL)
      {
         printf("%d is the last element nothing is there to delete.\n", key);
         return 0;
      }
      else
      {
         dup = tmp->right;
         hold = dup->info;
         tmp->right = dup->right;
         dup->right->left = dup->left;
         free(dup);
      }
   }

   return hold;
}

void display(struct doublell **head)
{
   struct doublell     *tmp;

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
         printf("%d<->", tmp->info);
         tmp = tmp->right;
      }
      printf("NULL\n");
   }

   return ;
}

void clearllist(struct doublell **head)
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
   int             opt, val, key;
   struct doublell *head = NULL;

   while (opt != 9)
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
               printf("Enter the key: ");
               scanf("%d", &key);
               addafter(val, &head, key);
               break;
         case 4:
               val = delbeg(&head);
               printf("%d deleted from the begining.\n", val);
               break;
         case 5:
               val = delend(&head);
               printf("%d deleted from the end.\n", val);
               break;
         case 6:
               printf("Enter the key: ");
               scanf("%d", &key);
               val = delafter(&head, key);
               printf("%d deleted after %d.\n", val, key);
               break;
         case 7:
               val = llistsize(&head);
               printf("Size of the list is: %d\n", val);
               break;
         case 8:
               display(&head);
               break;
         case 9:
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
   printf("         Double linked list       \n");
   printf("----------------------------------\n");
   printf("Your operations are: \n");
   printf("1) Insert node at Begining.\n");
   printf("2) Insert node at End.\n");
   printf("3) Insert node after a particular position.\n");
   printf("4) Delete node at Begining.\n");
   printf("5) Delete node at End.\n");
   printf("6) Delete node after a particular position.\n");
   printf("7) List size.\n");
   printf("8) Display List.\n");
   printf("9) Exit\n");

   printf("Enter your choice: ");
   scanf("%d", &option);

   return option;
}
