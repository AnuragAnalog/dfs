#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX          50

/********* FUNCTION DECLARATION *********/
void quick_a(int array[], int start, int end);
int partition_a(int array[], int low, int high);
void quick_d(int array[], int start, int end);
int partition_d(int array[], int low, int high);
void swap(int *a, int *b);

/********* MAIN STARTS HERE ********/
int main()
{
   int        i, n, opt, start = 0;
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
   scanf("%d", &opt);

   if (opt == 1)
   {
      quick_a(array, start, n-1);
   }
   else if (opt == 2)
   {
      quick_d(array, start, n-1);
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
void quick_a(int array[], int start, int end)
{
   int        pivot;

   if (end > start)
   {
      pivot = partition_a(array, start, end);
      quick_a(array, start, pivot-1);
      quick_a(array, pivot+1, end);
   }

   return ;
}

int partition_a(int array[], int low, int high)
{
   int      left, right, pivot_item;

   left = low;
   right = high;
   pivot_item = array[low];

   while (left < right)
   {
      while (array[left] <= pivot_item)
      {
         left = left + 1;
      }

      while (array[right] > pivot_item)
      {
         right = right - 1;
      }

      if (left < right)
      {
         swap(&array[left], &array[right]);
      }
   }

   array[low] = array[right];
   array[right] = pivot_item;

   return right;
}

void quick_d(int array[], int start, int end)
{
   int        pivot;

   if (end > start)
   {
      pivot = partition_d(array, start, end);
      quick_d(array, start, pivot-1);
      quick_d(array, pivot+1, end);
   }

   return ;
}

int partition_d(int array[], int low, int high)
{
   int      left, right, pivot_item;

   left = low;
   right = high;
   pivot_item = array[low];

   while (left < right)
   {
      while (array[left] >= pivot_item)
      {
         left = left + 1;
      }

      while (array[right] < pivot_item)
      {
         right = right - 1;
      }

      if (left < right)
      {
         swap(&array[left], &array[right]);
      }
   }

   array[low] = array[right];
   array[right] = pivot_item;

   return right;
}

void swap(int *a, int *b)
{
   int         tmp;

   tmp = *b;
   *b = *a;
   *a = tmp;

   return ;
}
