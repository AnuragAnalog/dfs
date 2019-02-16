#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX         30

/********* FUNCTION DECLARATION *********/
int linsearch(int n, int table[], int num);

/********* MAIN STARTS HERE *********/
int main()
{
   int         i, n, num, check;
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

   check = linsearch(n, table, num);

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
int linsearch(int n, int table[], int num)
{
   int        i;

   for (i = 0; i < n; i++)
   {
      if (table[i] == num)
      {
         return i+1;
      }
   }

   return -1;
}
