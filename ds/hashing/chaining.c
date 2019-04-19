#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/********* DATA-STRUCTURE DEFINITION *********/
typedef struct singlell
{  
   int              info;
   struct singlell  *link;
} Singlell;

/********* FUNCTION DECLARATION *********/
bool isprime(int n);
int bigprime(int n);
int menu();
void insertitem(struct singlell *arr[], int data, int m);
void deleteitem(struct singlell *arr[], int key);
void displaytable(struct singlell *arr[], int n);

/********* DATA-STRUCTURE OPERATIONS *********/
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

void addend(int data, struct singlell **head)
{
   Singlell     *tmp, *tr;

   tr = *head;

   tmp = (struct singlell *) malloc(sizeof(struct singlell));
   tmp->info = data;
   if (*head == NULL)
   {
      *head = tmp;
      tmp->link = NULL;
      return ;
   }

   while (tr->link != NULL)
   {
      tr = tr->link;
   }

   tmp->link = NULL;
   tr->link = tmp;

   return ;
}

void display(struct singlell **head)
{
   struct singlell     *tmp;

   if (isempty(head))
   {
      printf("->NULL\n");
      return ;
   }
   else
   {
      tmp = *head;
      while (tmp != NULL)
      {
         printf("%d->", tmp->info);
         tmp = tmp->link;
      }
      printf("NULL\n");
   }

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

/********* MAIN STARTS HERE *********/
int main(void)
{
   int                i, n, m, opt, val;
   struct singlell    *arr[1];

   printf("Enter the no. of elements in table: ");
   scanf("%d", &n);

   m = bigprime(n);
   printf("No. of buckets are: %d, which is a prime.\n", m);

   *arr = (struct singlell *)calloc(m, sizeof(struct singlell));
   for (i = 0; i < m; i++)
   {
      arr[i] = NULL;
   }

   while (opt != 4)
   {
      opt = menu();
      system("clear");
      switch (opt)
      {
         case 1:
               printf("Enter the value to be inserted: ");
               scanf("%d", &val);
               insertitem(arr, val, m);
               break;
         case 2:
               printf("Enter the key to be deleted: ");
               scanf("%d", &val);
               deleteitem(arr, val);
               break;
         case 3:
               displaytable(arr, m);
               break;
         case 4:
               printf("Hope you had a good time with my Data-structure :-)\n");
               exit(0);
         default:
               printf("Invalid choice\n");
      }
   }

   exit(0);
}

/********* FUNCTION DEFINITION *********/
int menu()
{
   int       option;

   printf("================================\n");
   printf("             Hashing            \n");
   printf("================================\n");
   printf("Your operations are: \n");
   printf("1)  Insert an Item.\n");
   printf("2)  Delete an Item.\n");
   printf("3)  Display the # table\n");
   printf("4)  Exit\n");

   printf("Enter your choice: ");
   scanf("%d", &option);

   return option;
}

void insertitem(struct singlell *arr[], int data, int m)
{
   int        key;

   key = data%m;
   addend(data, &arr[key]);

   return ;
}

void deleteitem(struct singlell *arr[], int key)
{
   int      hold;

   hold = delbeg(&arr[key]);
   printf("The number deleted is: %d\n", hold);
   return ;
}

void displaytable(struct singlell *arr[], int n)
{
   int        i;

   printf("\n===============================\n");
   printf("           Hash-table          \n");
   printf("===============================\n");
   for (i = 0; i < n; i++)
   {
      printf("%d:\t", i);
      display(&arr[i]);
   }

   return ;
}

bool isprime(int n)
{
   int         i;

   if (n%2 == 0)
   {
      return false;
   }

   for (i = 3; i < n; i = i + 2)
   {
      if (n%i == 0)
      {
         return false;
      }
   }

   return true;
}

int bigprime(int n)
{
   int         i, p = n;

   for (i = n; i < n+25; i++)
   {
      if (isprime(i))
      {
         p = i;
      }
   }

   return p;
}
