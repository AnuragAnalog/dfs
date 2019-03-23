#include <stdio.h>
#include <stdlib.h>

/********* FUNCTION DECLARATION *********/
int menu();

/********* DATA-STRUCTURE DEFINITION *********/
typedef struct dcircular
{
   int               info;
   struct dcircular  *right;
   struct dcircular  *left;
} Dcircular;

int llistsize(struct dcircular **tail)
{
   int         size = 0;
   Dcircular   *tmp = (*tail)->right;

   while (tmp != *tail)
   {
      tmp = tmp->right;
      size++;
   }

   return size++;
}

int isempty(struct dcircular **tail)
{
   return (*tail == NULL);
}

void addbeg(int data, struct dcircular **tail)
{
   Dcircular      *tmp;

   tmp = (struct dcircular *) malloc(sizeof(struct dcircular));
   tmp->info = data;

   if (*tail == NULL)
   {
      tmp->right = tmp;
      tmp->left = tmp;
      *tail = tmp;
   }
   else
   {
      tmp->right = (*tail)->right;
      tmp->right->left = tmp;
      (*tail)->right = tmp;
      tmp->left = *tail;
   }

   return ;
}

void addend(int data, struct dcircular **tail)
{
   Dcircular     *tmp;

   if (*tail == NULL)
   {
      addbeg(data, tail);
      return ;
   }

   tmp = (struct dcircular *) malloc(sizeof(struct dcircular));
   tmp->info = data;
   
   tmp->right = (*tail)->right;
   tmp->right->left = tmp;
   (*tail)->right = tmp;
   tmp->left = *tail;
   *tail = tmp;

   return ;
}

void addafter(int data, struct dcircular **tail, int key)
{
   struct dcircular     *tmp, *tr = (*tail)->right;

   tmp = (struct dcircular *)malloc(sizeof(struct dcircular));
  
   if (isempty(tail))
   {
      printf("Empty list, element not found.\n");
      return ;
   }
   else
   {
      while (tr->info != key)
      {
         tr = tr->right;
         if (tr == *tail)
         {
            break;
         }
      }
      
      if (tr == *tail && tr->info != key)
      {
         printf("Element not found.\n");
         return ;
      }
      else if (tr == *tail && tr->info == key)
      {
         addend(data, tail);
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

int delbeg(struct dcircular **tail)
{
   int                  hold;
   struct dcircular     *tmp = (*tail)->right;

   if (isempty(tail))
   {
      printf("The Linked list is empty you can't delete any nodes\n");
      return 0;
   }
   else
   {
      hold = tmp->info;
      if (tmp->right == tmp)
      {
         *tail = NULL;
      }
      else
      {
         (*tail)->right = tmp->right;
         tmp->right->left = *tail;
      }
      free(tmp);
   }

   return hold;
}

int delend(struct dcircular **tail)
{
   int                  hold;
   struct dcircular     *tr = (*tail)->right;

   if (isempty(tail))
   {
      printf("The Linked list is empty you can't delete any nodes\n");
      return 0;
   }
   else
   {
      while (tr != *tail)
      {
         tr = tr->right;
      }
      
      hold = tr->info;
      tr->left->right = (*tail)->right;
      (*tail)->right->left = (*tail)->left;
      *tail = (*tail)->left;
      free(tr);
   }

   return hold;
}

int delafter(struct dcircular **tail, int key)
{
   int                 hold;
   struct dcircular    *tmp = (*tail)->right, *dup;

   if (isempty(tail))
   {
      printf("Can't delete any node from empty list.\n");
      return 0;
   }
   else
   {
      while (tmp->info != key)
      {
         tmp = tmp->right;
         if (tmp == *tail)
         {
            break;
         }
      }

      if (tmp->info != key && tmp == *tail)
      {
         printf("Element not found.\n");
         return 0;
      }

      if (tmp->info == key && tmp == *tail)
      {
         hold = delbeg(tail);
         return hold;
      }
      else
      {
         if (tmp->right == *tail)
         {
            hold = delend(tail);
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
   }

   return hold;
}

void display(struct dcircular **tail)
{
   struct dcircular     *tmp = (*tail)->right;

   if (isempty(tail))
   {
      printf("It's an empty linked list can't display anything.\n");
      return ;
   }
   else
   {
      printf("Elements of the list are:\n");
      while (tmp != *tail)
      {
         printf("%d<->", tmp->info);
         tmp = tmp->right;
      }
      printf("%d<->", tmp->info);
      printf("NULL\n");
   }

   return ;
}

void clearllist(struct dcircular **tail)
{
   while (*tail != NULL)
   {  
      delbeg(tail);
   }
   free(*tail);

   return ;
}

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int              opt, val, key;
   struct dcircular *tail = NULL;

   while (opt != 9)
   {
      opt = menu();
      system("clear");
      switch (opt)
      {
         case 1:
               printf("Enter the value to be inserted: ");
               scanf("%d", &val);
               addbeg(val, &tail);
               printf("Element inserted at beginning.\n");
               break;
         case 2:
               printf("Enter the value to be inserted: ");
               scanf("%d", &val);
               addend(val, &tail);
               printf("Element inserted at End\n");
               break;
         case 3:
               printf("Enter the value to be inserted: ");
               scanf("%d", &val);
               printf("Enter the key: ");
               scanf("%d", &key);
               addafter(val, &tail, key);
               break;
         case 4:
               val = delbeg(&tail);
               printf("%d deleted from the begining.\n", val);
               break;
         case 5:
               val = delend(&tail);
               printf("%d deleted from the end.\n", val);
               break;
         case 6:
               printf("Enter the key: ");
               scanf("%d", &key);
               val = delafter(&tail, key);
               printf("%d deleted after %d.\n", val, key);
               break;
         case 7:
               val = llistsize(&tail);
               printf("Size of the list is: %d\n", val);
               break;
         case 8:
               display(&tail);
               break;
         case 9:
               clearllist(&tail);
               printf("Hope you had a good time with my Data-structure :-)\n");
               exit(0);
         default:
               break;
      }
   }

   clearllist(&tail);
   exit(0);
}

/********* FUNCTION DEFINITION *********/
int menu()
{
   int       option;

   printf("----------------------------------\n");
   printf("       Doublely linked list       \n");
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
