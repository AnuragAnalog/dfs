#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/********* DEFINED CONSTANTS *********/
#define   MAX          50

/********* FUNCTION DECLARATION *********/
void oddeven_ascend(int n, int array[]);
void oddeven_decend(int n, int array[]);
void swap(int *a, int *b);

/********* MAIN STARTS HERE ********/
int main()
{
   int        i, n, choice;
   int        array[MAX];

   printf("Enter the no. of elements in table: ");
   scanf("%d", &n);

   printf("Enter the elements in table: \n");
   for (i = 0; i < n; i++)
   {
      printf("Enter the integer: ");
      scanf("%d", &array[i]);
   }

   printf("Select an option: \n");
   printf("1) In ascending order.\n");
   printf("2) In dedcending order.\n");
   scanf("%d", &choice);

   if (choice == 1)
   {
      oddeven_ascend(n, array);
   }
   else if (choice == 2)
   {
      oddeven_decend(n, array);
   }
   else
   {
      printf("INVALID OPTION.\n");
      exit(1);
   }

   printf("Sorted list: \n[");
   for (i = 0; i < n; i++)
   {
      printf("%d, ", array[i]);
   }
   printf("]\n");

   exit(0);
}

/********* FUNCTION DEFINITION *********/
void oddeven_ascend(int n, int array[])
{
   int        i;
   bool       check = 0;

   while (!check)
   {
      check = 1;
      for (i = 1; i < n-1; i += 2)
      {
         if (array[i] > array[i+1])
         {
            swap(&array[i], &array[i+1]);
            check = 0;
         }
      }

      for (i = 0; i < n-1; i += 2)
      {
         if (array[i] > array[i+1])
         {
            swap(&array[i], &array[i+1]);
            check = 0;
         }
      }
   }

   return ;
}

void oddeven_decend(int n, int array[])
{
   int        i;
   bool       check = 0;

   while (!check)
   {
      check = 1;
      for (i = 1; i < n-1; i += 2)
      {
         if (array[i] < array[i+1])
         {
            swap(&array[i], &array[i+1]);
            check = 0;
         }
      }

      for (i = 0; i < n-1; i += 2)
      {
         if (array[i] < array[i+1])
         {
            swap(&array[i], &array[i+1]);
            check = 0;
         }
      }
   }

   return ;
}

void swap(int *a, int *b)
{
   int         tmp;

   tmp = *b;
   *b = *a;
   *a = tmp;

   return ;
}
