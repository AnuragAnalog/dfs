#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX       30

/********* FUNCTION DECLARATION *********/
int input_array(int array[]);
int mergearr_a(int n1, int n2, int array1[], int array2[], int mergedarray[]);
int mergearr_d(int n1, int n2, int array1[], int array2[], int mergedarray[]);
void output_array(int n, int array[]);
int sortcheck(int n, int array[]);

/********* MAIN STARTS HERE *********/
int main()
{
   int        n1, n2, sort1, sort2, totn;
   int        array1[MAX], array2[MAX], mergedarray[MAX];

   n1 = input_array(array1);
   n2 = input_array(array2);

   sort1 = sortcheck(n1, array1);
   sort2 = sortcheck(n2, array2);

   switch (sort1*sort2)
   {
      case 1:
             totn = mergearr_a(n1, n2, array1, array2, mergedarray);
             break;
      case 4:
             totn = mergearr_d(n1, n2, array1, array2, mergedarray);
             break;
      default:
             printf("Merging unsorted arrays is beyond the scope of this program.\n");
             exit(1);
   }

   printf("\nSorted array:\n");
   output_array(totn, mergedarray);

   exit(0);
}

/********* FUNCTION DEFINITION *********/
int input_array(int array[])
{
   int        i, nitems;

   printf("\nEnter no. of elements in table: ");
   scanf("%d", &nitems);

   for (i = 0; i < nitems; i++)
   {
      printf("Enter the element: ");
      scanf("%d", &array[i]);
   }

   return nitems;
}

int mergearr_a(int n1, int n2, int array1[], int array2[], int mergedarray[])
{
   int        i = 0, j = 0, k = 0, l;

   while (i != n1 && j != n2)
   {
      if (array1[i] < array2[j])
      {
         mergedarray[k] = array1[i];
         i++, k++;
      }
      else
      {
         mergedarray[k] = array2[j];
         j++, k++;
      }
   }

   if (i == n1 && j != n2)
   {
      for (l = j; l < n2; l++, k++)
      {
         mergedarray[k] = array2[l];
      }
   }
   else
   {
      for (l = i; l < n1; l++, k++)
      {
         mergedarray[k] = array1[l];
      }
   }

   return n1+n2;
}

int mergearr_d(int n1, int n2, int array1[], int array2[], int mergedarray[])
{
   int        i = 0, j = 0, k = 0, l;

   while (i != n1 && j != n2)
   {
      if (array1[i] > array2[j])
      {
         mergedarray[k] = array1[i];
         i++, k++;
      }
      else
      {
         mergedarray[k] = array2[j];
         j++, k++;
      }
   }

   if (i == n1 && j != n2)
   {
      for (l = j; l < n2; l++, k++)
      {
         mergedarray[k] = array2[l];
      }
   }
   else
   {
      for (l = i; l < n1; l++, k++)
      {
         mergedarray[k] = array1[l];
      }
   }

   return n1+n2;
}

void output_array(int n, int array[])
{
   int        i;

   printf("\n{ ");
   for (i = 0; i < n; i++)
   {
      printf("%d, ", array[i]);
   }
   printf("}\n");

   return ;
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
