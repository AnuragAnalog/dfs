#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX         30

/********* FUNCTION DECLARATION *********/
int binsearch_a(int n, int table[], int num);
int binsearch_d(int n, int table[], int num);
int sortcheck(int n, int array[]);

/********* MAIN STARTS HERE *********/
int main()
{
   int         i, n, num, check, sort;
   int         table[MAX];

   printf("Enter the maximum no. of elemnets in table: ");
   scanf("%d", &n);

   for (i = 0; i < n; i++)
   {
      printf("Enter the element: ");
      scanf("%d", &table[i]);
   }

   printf("Enter the no. to be serached: ");
   scanf("%d", &num);

   sort = sortcheck(n, table);

   switch (sort)
   {
      case 1:
             check = binsearch_a(n, table, num);
             break;
      case 2:
             check = binsearch_d(n, table, num);
             break;
      case 3:
             printf("%d cannot be searched in this unsorted array, ", num);
             printf("better try using linear-search algorithm.\n");
             exit(1);
   }

   if (check == -1)
   {
      printf("%d not found in the array\n", num);
   }
   else
   {
      printf("%d is the location of %d in array.\n", check, num);
   }

   exit(0);
}

/********* FUNCTION DEFINITION *********/
int binsearch_a(int n, int table[], int num)
{
   int        i = 0, j = n-1, m;

   while (i < j)
   {
      m = ((i+j)/2);
      if (table[m] > num)
      {
         j = m+1;
      }
      else if (table[m] < num)
      {
         i = m;
      }
      else
      {
         return m+1;
      }
   }

   return -1;
}

int binsearch_d(int n, int table[], int num)
{
   int        i = 0, j = n-1, m;

   while (i < j)
   {
      m = ((i+j)/2);
      if (table[m] < num)
      {
         j = m+1;
      }
      else if (table[m] > num)
      {
         i = m;
      }
      else
      {
         return m+1;
      }
   }

   return -1;
}

int sortcheck(int n, int array[])
{
   int         i, check = 1;

   for (i = 0; i < n-1; i++)
   {
      if (array[i] > array[i+1])
      {
         check = 0;
         break;
      }
   }

   if (check == 1)
   {
      return 1;
   }

   check = 1;
   for (i = 0; i < n-1; i++)
   {
      if (array[i] < array[i+1])
      {
         check = 0;
         break;
      }
   }

   if (check == 1)
   {
      return 2;
   }

   return 3;
}
