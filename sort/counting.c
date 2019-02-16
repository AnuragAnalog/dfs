#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX          250

/********* FUNCTION DECLARATION *********/
void intialize(int max, int array[]);
void counting_ascend(int n, int array[], int min, int max);
void counting_descend(int n, int array[], int min, int max);
int maxi(int n, int array[]);
int mini(int n, int array[]);

/********* MAIN STARTS HERE ********/
int main()
{
   int        i, n, choice, min, max;
   int        array[MAX];

   printf("Enter the no. of elements in table: ");
   scanf("%d", &n);

   printf("Enter the elements in table: \n");
   for (i = 0; i < n; i++)
   {
      printf("Enter the integer: ");
      scanf("%d", &array[i]);
   }

   max = maxi(n, array);
   min = mini(n, array);

   printf("Select an option: \n");
   printf("1) In ascending order.\n");
   printf("2) In dedcending order.\n");
   scanf("%d", &choice);

   if (choice == 1)
   {
      counting_ascend(n, array, min, max);
   }
   else if (choice == 2)
   {
      counting_descend(n, array, min, max);
   }
   else
   {
      printf("INVALID OPTION.\n");
      exit(1);
   }

   exit(0);
}

/********* FUNCTION DEFINITION *********/
void intialize(int max, int array[])
{
   int        i;

   for (i = 0; i < max; i++)
   {
      array[i] = 0;
   }

   return ;
}

void counting_ascend(int n, int array[], int min, int max)
{
   int        i, j;
   int        tmparray[MAX];

   intialize(array[max], tmparray);
   for (i = 0; i < n; i++)
   {
      tmparray[array[i]] += 1;
   }

   printf("Sorted array:\n[");
   for (i = 0; i <= array[max]; i++)
   {
      if (tmparray[i] == 0)
      {
         continue;
      }
      else if (tmparray[i] == 1)
      {
         printf("%d, ", i);
      }
      else
      {
         for (j = 0; j < tmparray[i]; j++)
         {
            printf("%d, ", i);
         }
      }
   }
   printf("]\n");

   return ;
}

void counting_descend(int n, int array[], int min, int max)
{
   int        i, j;
   int        tmparray[MAX];

   intialize(array[max], tmparray);
   for (i = 0; i < n; i++)
   {
      tmparray[array[i]] += 1;
   }

   printf("Sorted array:\n[");
   for (i = array[max]; i >= 0; i--)
   {
      if (tmparray[i] == 0)
      {
         continue;
      }
      else if (tmparray[i] == 1)
      {
         printf("%d, ", i);
      }
      else
      {
         for (j = 0; j < tmparray[i]; j++)
         {
            printf("%d, ", i);
         }
      }
   }
   printf("]\n");

   return ;
}

int maxi(int n, int array[])
{
   int        i, maxind = 0;

   for (i = 0; i < n; i++)
   {
      if (array[maxind] < array[i])
      {
         maxind = i;
      }
   }

   return maxind;
}

int mini(int n, int array[])
{
   int        i, minind = 0;

   for (i = 0; i < n; i++)
   {
      if (array[minind] > array[i])
      {
         minind = i;
      }
   }

   return minind;
}

