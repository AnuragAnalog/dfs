#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX          50

/********* FUNCTION DECLARATION *********/
void insertion_ascend(int n, int array[]);
void insertion_decend(int n, int array[]);
void ciltable(int end, int start, int array[]);

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
      insertion_ascend(n, array);
   }
   else if (choice == 2)
   {
      insertion_decend(n, array);
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
void insertion_ascend(int n, int array[])
{
   int        i, j, ind;

   for (i = 0; i < n; i++)
   {
      ind = i+1;
      for (j = 0; j < i+1; j++)
      {
          if (array[ind] < array[j])
          {
             ciltable(ind, j, array);
          }
      }
   }

   return ;
}

void insertion_decend(int n, int array[])
{
   int        i, j, ind;

   for (i = 0; i < n; i++)
   {
      ind = i+1;
      for (j = 0; j < i+1; j++)
      {
          if (array[ind] > array[j])
          {
             ciltable(ind, j, array);
          }
      }
   }

   return ;
}

void ciltable(int end, int start, int array[])
{
   int        i, key;

   key = array[end];
   for (i = end; i > start; i--)
   {
      array[i] = array[i-1];
   }
   array[start] = key;

   return ;
}
