#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX          50

/********* FUNCTION DECLARATION *********/
void bubble_ascend(int n, int array[]);
void bubble_decend(int n, int array[]);
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
      bubble_ascend(n, array);
   }
   else if (choice == 2)
   {
      bubble_decend(n, array);
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
void bubble_ascend(int n, int array[])
{
   int        i, j;

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n-i-1; j++)
      {
         if (array[j] > array[j+1])
         {
            swap(&array[j], &array[j+1]);
         }
      }
   }

   return ;
}

void bubble_decend(int n, int array[])
{
   int        i, j;

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < n-i-1; j++)
      {
         if (array[j] < array[j+1])
         {
            swap(&array[j], &array[j+1]);
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
