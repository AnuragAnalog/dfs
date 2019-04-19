#include <stdio.h>
#include <stdlib.h>

/********* DEFINED CONSTSNATS *********/
#define MAX      100

/********* FUNCTION DECLARATION *********/
int menu();
int left_child(int k);
int right_child(int k);
int parent(int k);
int insert(int heap[], int len, int data);
int delete(int heap[], int len);
void heapify_up(int heap[], int len);
void heapify_down(int heap[], int len);
void heap_s(int heap[], int len);
void display(int heap[], int len);
void swap(int *a, int *b);

/********* MAINS STARTS HERE *********/
int main(void)
{
   int        heap[MAX], len = 0, opt, val;

   while (opt != 5)
   {
      opt = menu();
      system("clear");
      switch (opt)
      {
         case 1:
               printf("*** Insert a node ***\n");
               printf("Enter the node to be inserted: ");
               scanf("%d", &val);
               len = insert(heap, len, val);
               break;
         case 2:
               printf("*** Delete a node ***\n");
               len = delete(heap, len);
               break;
         case 3:
               printf("*** Sorting the heap ***\n");
               heap_s(heap, len);
               break;
         case 4:
               display(heap, len);
               break;
         case 5:
               printf("Hope you had a good time with my data-structure.\n");
               exit(0);
         default:
               break;
      }
   }

   exit(0);
}

/********* FUNCTION DEFINITION *********/
int insert(int heap[], int len, int data)
{
   heap[len] = data;
   if (len == 0)
   {
      return len+1;
   }

   heapify_up(heap, len);
   return len+1;
}

int delete(int heap[], int len)
{
   int        hold, init = 0;

   hold = heap[0];
   heap[0] = heap[len-1];

   heapify_down(heap, init);
   printf("%d is deleted.\n", hold);
   return len-1;
}

void heapify_up(int heap[], int len)
{
   int         p;

   p = parent(len);

   if (p < 0)
   {
      return ;
   }

   if (heap[p] < heap[len])
   {
      swap(&heap[p], &heap[len]);
      heapify_up(heap, p);
   }

   return ;
}

void heapify_down(int heap[], int s)
{
   int        r, l, cmp;

   r = right_child(s);
   l = left_child(s);

   if (heap[r] > heap[l])
   {
      cmp = r;
   }
   else
   {
      cmp = l;
   }

   if (heap[cmp] > heap[s])
   {
      printf("%d %d\n", heap[cmp], heap[s]);
      swap(&heap[cmp], &heap[s]);
      printf("%d %d\n", heap[cmp], heap[s]);
      heapify_down(heap, cmp);
   }

   return ;
}

void heap_s(int heap[], int len)
{
   int        i, val = len;

   for (i = len; i > 0; i--)
   {
      val = delete(heap, val);
   }

   return ;
}

void display(int heap[], int len)
{
   int        i;

   if (len == 0)
   {
      printf("Sorry tree is empty.\n");
      return ;
   }

   for (i = 0; i < len; i++)
   {
      printf("%d ", heap[i]);
   }
   printf("\n");

   return ;
}

int left_child(int k)
{
   return 2*k+1;
}

int right_child(int k)
{
   return 2*k+2;
}

int parent(int k)
{
   return (int) (k-1)/2;
}

void swap(int *a, int *b)
{
   int      tmp;

   tmp = *a;
   *a = *b;
   *b = tmp;

   return ;
}

int menu()
{
   int       option;

   printf("\n--------------------------\n");
   printf("         Binary Heap        \n");
   printf("----------------------------\n");
   printf("Your operations are: \n");
   printf("1) Insert a node.\n");
   printf("2) Delete a node.\n");
   printf("3) Sorting.\n");
   printf("4) Display the tree.\n");
   printf("5) Exit\n");

   printf("Enter your choice: ");
   scanf("%d", &option);

   return option;
}
