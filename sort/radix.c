#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTANTS *********/
#define   MAX          250
#define   MAX10        12
#define   NINE         9

/********* STRUCTURE DEFINITION *********/
typedef struct num_index
{
   int        num;
   int        ind[MAX];
} index;

/********* FUNCTION DECLARATION *********/
void intialize(int max, index array[]);
int nodigits(int num);
void digiti(int array[], int tmparr2[], int n, int dig);
void radix_a(int d, int array[], int n);
void radix_d(int d, int array[], int n);
void counting_ascend(int n, int array[], int array2[], int tmparr2[]);
void counting_descend(int n, int array[], int array2[], int tmparr2[]);

/********* MAIN STARTS HERE ********/
int main()
{
   int        i, n, choice, d = 1, j;
   int        array[MAX];

   printf("Enter the no. of elements in table: ");
   scanf("%d", &n);

   printf("Enter the elements in table: \n");
   for (i = 0; i < n; i++)
   {
      printf("Enter the integer: ");
      scanf("%d", &array[i]);

      j = nodigits(array[i]);

      if (d < j)
      {
         d = j;
      }
   }

   printf("Select an option: \n");
   printf("1) In ascending order.\n");
   printf("2) In dedcending order.\n");
   scanf("%d", &choice);

   if (choice == 1)
   {
      radix_a(d, array, n);
   }
   else if (choice == 2)
   {
      radix_d(d, array, n);
   }
   else
   {
      printf("INVALID OPTION.\n");
      exit(1);
   }

   printf("Sorted list:\n[");
   for (i = 0; i < n; i++)
   {
      printf("%d ", array[i]);
   }
   printf("]\n");

   exit(0);
}

/********* FUNCTION DEFINITION *********/
void radix_a(int d, int array[], int n)
{
    int        i = 0;
    int        array2[MAX], tmparr2[MAX];

    while (i < d)
    {
       digiti(array, tmparr2, n, i+1);
       counting_ascend(n, array, array2, tmparr2);
       i++;
    }

    return ;
}

void radix_d(int d, int array[], int n)
{
    int        i = 0;
    int        array2[MAX], tmparr2[MAX];

    while (i < d)
    {
       digiti(array, tmparr2, n, i+1);
       counting_descend(n, array, array2, tmparr2);
       i++;
    }

    return ;
}

void digiti(int array[], int tmparr2[], int n, int dig)
{
   int        i, j, val;

   for (i = 0; i < n; i++)
   {
      val = array[i];
      for (j = 0; j < dig; j++)
      {
         val = val/10;
      }
      tmparr2[i] = val%10;
   }

   return ;
}

int nodigits(int num)
{
   int        i = 0, x = num;

   while (x != 0)
   {
      x = x / 10;
      i++;
   }

   return i;
}

void intialize(int max, index array[])
{
   int        i;

   for (i = 0; i < max; i++)
   {
      array[i].num = 0;
   }

   return ;
}

void counting_ascend(int n, int array[], int array2[], int tmparr2[])
{
   int        i, j, ind, k = 0, l;
   index      tmparray[MAX10];

   intialize(NINE, tmparray);
   for (i = 0; i < n; i++)
   {
      tmparray[tmparr2[i]].num += 1;
      ind = tmparray[tmparr2[i]].num - 1;
      tmparray[tmparr2[i]].ind[ind] = i;
   }

   for (i = 0; i <= NINE; i++)
   {
      if (tmparray[i].num == 0)
      {
         continue;
      }
      else if (tmparray[i].num >= 1)
      {
         for (j = 0; j < tmparray[i].num; j++)
         {
            l = tmparray[i].ind[j];
            array2[k] = array[l];
            k++;
         }
      }
   }

   for (i = 0; i < n; i++)
   {
      array[i] = array2[i];
   }

   return ;
}

void counting_descend(int n, int array[], int array2[], int tmparr2[])
{
   int        i, j, ind, k = 0, l;
   index      tmparray[MAX10];

   intialize(NINE, tmparray);
   for (i = 0; i < n; i++)
   {
      tmparray[tmparr2[i]].num += 1;
      ind = tmparray[tmparr2[i]].num - 1;
      tmparray[tmparr2[i]].ind[ind] = i;
   }

   for (i = 0; i <= NINE; i++)
   {
      if (tmparray[i].num == 0)
      {
         continue;
      }
      else if (tmparray[i].num >= 1)
      {
         for (j = 0; j < tmparray[i].num; j++)
         {
            l = tmparray[i].ind[j];
            array2[k] = array[l];
            k++;
         }
      }
   }

   for (i = n-1; i >= 0; i--)
   {
      array[n-1-i] = array2[i];
   }

   return ;
}
