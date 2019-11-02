#include <stdio.h>
#include <stdlib.h>

/********* FUNCTION DECLARATION *********/
void tree(int array[]);

/********* DATA-STRUCTURE DEFINITION *********/
typedef struct btree
{
   int          info;
   struct btree *left;
   struct btree *right;
} Btree;
struct btree *root = NULL;

int insert(int data, int h)
{
   int          i = 0;
   struct btree *cur, *tr = root;
   
   cur = (struct btree *)malloc(sizeof(struct btree));
   cur->info = data;
   cur->left = NULL;
   cur->right = NULL;
   
   if (root == NULL)
   {
      root = cur;
   }
   else
   {
      while (1)
      {
         if (data >= tr->info)
         {
            if (tr->right != NULL)
            {
               tr = tr->right;
            }
            else
            {
               tr->right = cur;
               i++;
               break;
            }
            i++;
         }
         else
         {
            if (tr->left != NULL)
            {
               tr = tr->left;
            }
            else
            {
               tr->left = cur;
               i++;
               break;
            }
            i++;
         }
      }
   }
   
   if (h > i)
   {
      return h;
   }

   return i;
}

int intraver(struct btree *root, int array[], int ind)
{
   if (root != NULL)
   {
      ind = intraver((root)->left, array, ind);
      array[ind] = (root)->info;
      ind = ind + 1;
      ind = intraver((root)->right, array, ind);
   }
   
   return ind;
}

void cleartree(struct btree *root)
{
   if (root != NULL)
   {
      cleartree((root)->left);
      cleartree((root)->right);
      free(root);
   }

   return ;
}

/********* MAIN STARTS HERE *********/ 
int main(void)
{
   int          i, n, h = 0, item, *array;

   printf("Enter the no. of elements: ");
   scanf("%d", &n);

   array = (int *)calloc(n, sizeof(int));

   for (i = 0; i < n; i++)
   {
      printf("Enter the element: ");
      scanf("%d", &item);
      h = insert(item, h);
   }

   tree(array);
   printf("Sorted array:\n[");
   for (i = 0; i < n; i++)
   {
      printf("%d, ", array[i]);
   }
   printf("]\n");

   cleartree(root);
   exit(0); 
}

/********* FUNCTION DEFINITION *********/
void tree(int array[])
{
   int        i = 0;

   i = intraver(root, array, i);
   return ;
}
