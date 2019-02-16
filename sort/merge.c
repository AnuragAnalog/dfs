#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX          50

/********* FUNCTION DECLARATION *********/
void merge_ascend(int start, int n, int array[]);
void merge_descend(int start, int n, int array[]);
void mergearr_a(int array[], int start, int mid, int end);
void mergearr_d(int array[], int start, int mid, int end);

/********* MAIN STARTS HERE ********/
int main()
{
   int        i, n, choice, start = 0;
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
      merge_ascend(start, n-1, array);
   }
   else if (choice == 2)
   {
      merge_descend(start, n-1, array);
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
void merge_ascend(int start, int n, int array[])
{
   int        mid;

   if (start < n)
   {
      mid = (start+n)/2;

      merge_ascend(start, mid, array);
      merge_ascend(mid+1, n, array);
      mergearr_a(array, start, mid, n);
   }

   return ;
}

void merge_descend(int start, int n, int array[])
{
   int        mid;

   if (start < n)
   {
      mid = (start+n)/2;

      merge_descend(start, mid, array);
      merge_descend(mid+1, n, array);
      mergearr_d(array, start, mid, n);
   }

   return ;
}

void mergearr_a(int array[], int start, int mid, int end)
{
   int        i = start, j = mid+1, k = 0, l;
   int        mergedarray[MAX];

   while (i <= mid+1 && j <= end)
   {
      if (array[i] < array[j])
      {
         mergedarray[k] = array[i];
         i++;
      }
      else
      {
         mergedarray[k] = array[j];
         j++;
      }
      k++;
   }

   if (i == mid+1 && j <= end)
   {
      for (l = j; l < end; l++, k++)
      {
         mergedarray[k] = array[l];
      }
   }
   else
   {
      for (l = i; l < mid+1; l++, k++)
      {
         mergedarray[k] = array[l];
      }
   }

   for (i = start, k = 0; i <= end; i++, k++)
   {
      array[i] = mergedarray[k];
   }
   return ;
}

void mergearr_d(int array[], int start, int mid, int end)
{
   int        i = start, j = mid+1, k = 0, l;
   int        mergedarray[MAX];

   while (i <= mid+1 && j <= end)
   {
      if (array[i] > array[j])
      {
         mergedarray[k] = array[i];
         i++;
      }
      else
      {
         mergedarray[k] = array[j];
         j++;
      }
      k++;
   }

   if (i == mid+1 && j <= end)
   {
      for (l = j; l < end; l++, k++)
      {
         mergedarray[k] = array[l];
      }
   }
   else
   {
      for (l = i; l < mid+1; l++, k++)
      {
         mergedarray[k] = array[l];
      }
   }

   for (i = start, k = 0; i <= end; i++, k++)
   {
      array[i] = mergedarray[k];
   }
   return ;
}
