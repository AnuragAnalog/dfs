#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX          50

/********* FUNCTION DECLARATION *********/
void selection_ascend(int n, int array[]);
void selection_decend(int n, int array[]);
int mini(int s, int n, int array[]);
int maxi(int s, int n, int array[]);
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
      selection_ascend(n, array);
   }
   else if (choice == 2)
   {
      selection_decend(n, array);
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
void selection_ascend(int n, int array[])
{
   int        i, index;

   for (i = 0; i < n; i++)
   {
      index = mini(i, n, array);
      swap(&array[i], &array[index]);
   }

   return ;
}

void selection_decend(int n, int array[])
{
   int        i, index;

   for (i = 0; i < n; i++)
   {
      index = maxi(i, n, array);
      swap(&array[i], &array[index]);
   }

   return ;
}

int mini(int s, int n, int array[])
{
   int        i, minind = s;

   for (i = s+1; i < n; i++)
   {
      if (array[minind] > array[i])
      {
         minind = i;
      }
   }

   return minind;
}

int maxi(int s, int n, int array[])
{
   int        i, maxind = s;

   for (i = s+1; i < n; i++)
   {
      if (array[maxind] < array[i])
      {
         maxind = i;
      }
   }

   return maxind;
}

void swap(int *a, int *b)
{
   int         tmp;

   tmp = *b;
   *b = *a;
   *a = tmp;

   return ;
}
