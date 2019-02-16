#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********* DEFINED CONSTANTS *********/
#define   MAX          50

/********* FUNCTION DECLARATION *********/
void initialize(int bins[][MAX+2], int n, int k);
void bucket_a(int n, int k, int array[], int bin[][MAX+2]);
void bucket_d(int n, int k, int array[], int bin[][MAX+2]);
int maxi(int n, int array[]);
void bubble_ascend(int n, int array[]);
void bubble_descend(int n, int array[]);
void swap(int *a, int *b);

/********* MAIN STARTS HERE ********/
int main()
{
   int        i, n, choice, k;
   int        array[MAX];
   int        bin[MAX][MAX+2];

   printf("Enter the no. of elements in table: ");
   scanf("%d", &n);

   printf("Enter the elements in table: \n");
   for (i = 0; i < n; i++)
   {
      printf("Enter the integer: ");
      scanf("%d", &array[i]);
   }

   printf("Enter no. of buckets: ");
   scanf("%d", &k);

   printf("Select an option: \n");
   printf("1) In ascending order.\n");
   printf("2) In dedcending order.\n");
   scanf("%d", &choice);

   if (choice == 1)
   {
      bucket_a(n, k, array, bin);
   }
   else if (choice == 2)
   {
      bucket_d(n, k, array, bin);
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
void initialize(int bins[][MAX+2], int n, int k)
{
   int        i, j;

   for (i = 0; i < n; i++)
   {
      for (j = 0; j < k; j++)
      {
         bins[i][j] = 0;
      }
   }

   return ;
}

void bucket_a(int n, int k, int array[], int bin[][MAX+2])
{
   int        i, j, row, col, max, l = 0;

   initialize(bin, n, k);
   max = maxi(n, array);

   for (i = 0; i < n; i++)
   {
      row = (array[i]*k)/max-1, col = bin[row][0];
      bin[row][col+1] = array[i];
      bin[row][0] = bin[row][0] + 1;
   }

   for (i = 0; i < k; i++)
   {
      for (j = 1; j <= bin[i][0]; j++)
      {
         array[l] = bin[i][j];
         l++;
      }
   }

   bubble_ascend(n, array);
   return ;
}

void bucket_d(int n, int k, int array[], int bin[][MAX+2])
{
   int        i, j, row, col, max, l = 0;

   initialize(bin, n, k);
   max = maxi(n, array);

   for (i = 0; i < n; i++)
   {
      row = (array[i]*k)/max-1, col = bin[row][0];
      bin[row][col+1] = array[i];
      bin[row][0] = bin[row][0] + 1;
   }

   for (i = 0; i < k; i++)
   {
      for (j = 1; j <= bin[i][0]; j++)
      {
         array[l] = bin[i][j];
         l++;
      }
   }

   bubble_descend(n, array);
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

   return array[maxind];
}

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

void bubble_descend(int n, int array[])
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

