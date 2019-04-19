#include <stdio.h>
#include <stdlib.h>

/********* FUNCTION DECLARATION *********/
int menu();

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

void intraver(struct btree *root)
{
   if (root != NULL)
   {
      intraver((root)->left);
      printf("%d ", (root)->info);
      intraver((root)->right);
   }
   
   return ;
}

void pretraver(struct btree *root)
{
   if (root != NULL)
   {
      printf("%d ", (root)->info);
      pretraver((root)->left);
      pretraver((root)->right);
   }
   
   return ;
}

void posttraver(struct btree *root)
{
   if (root != NULL)
   {
      posttraver((root)->left);
      posttraver((root)->right);
      printf("%d ", (root)->info);
   }
   
   return ;
}

void printlevel(struct btree *root, int level, int wid)
{
   int         i;

   if (root == NULL)
   {
      for (i = 0; i < wid; i++)
      {
         printf(" ");
      }
      printf("  ");
   }
   else if (level == 1)
   {
      for (i = 0; i < wid; i++)
      {
         printf(" ");
      }
      if ((root->info)%10 == 0)
      {
         printf("%d ", root->info);
      }
      else
      {
         printf("%d", root->info);
      }
   }
   else
   {
      printlevel(root->left, level-1, wid);
      printlevel(root->right, level-1, wid);
   }

   return ;
}

void display(struct btree *root, int height)
{
   int       i, wid = 4*height;

   for (i = 0; i < height+1; i++)
   {
      printlevel(root, i+1, wid);
      wid = wid/2;
      printf("\n");
   }

   return ;
}

int delnodel(struct btree *root, int key)
{
   int          hold;
   struct btree *tr = root, *cur, *dup;

   while (tr->info != key)
   {
      if (key >= tr->info)
      {
         tr = tr->right;
      }
      else
      {
         tr = tr->left;
      }

      if (tr == NULL)
      {
         printf("Can not delete a non-existing node.\n");
         return 0;
      }
   }

   dup = tr;
   tr = tr->left;

   if (tr->right == NULL)
   {
      hold = dup->info;
      dup->info = tr->info;
      dup->left = tr->left;
      return hold;
   }
   while (tr->right != NULL)
   {
      cur = tr;
      tr = tr->right;
   }

   hold = dup->info;
   dup->info = tr->info;
   cur->right = tr->left;
   return hold;
}

int delnoder(struct btree *root, int key)
{
   int          hold;
   struct btree *tr = root, *cur, *dup;

   while (tr->info != key)
   {
      if (key >= tr->info)
      {
         tr = tr->right;
      }
      else
      {
         tr = tr->left;
      }

      if (tr == NULL)
      {
         printf("Can not delete a non-existing node.\n");
         return 0;
      }
   }

   dup = tr;
   tr = tr->right;

   if (tr->left == NULL)
   {
      hold = dup->info;
      dup->info = tr->info;
      dup->right = tr->right;
      return hold;
   }
   while (tr->left != NULL)
   {
      cur = tr;
      tr = tr->left;
   }

   hold = dup->info;
   dup->info = tr->info;
   cur->left = tr->right;
   return hold;
}

int delleaf(struct btree *root, int key)
{
   int          hold;
   struct btree *tr = root, *cur = root;

   while (tr->info != key)
   {
      cur = tr;
      if (key >= tr->info)
      {
         tr = tr->right;
      }
      else
      {
         tr = tr->left;
      }

      if (tr == NULL)
      {
         printf("Can not delete a non-existing leaf.\n");
         return -1;
      }
   }

   if (tr->left == NULL && tr->right == NULL)
   {
      hold = tr->info;
      if (cur->left == tr)
      {
         cur->left = NULL;
      }
      else
      {
         cur->right = NULL;
      }
      free(tr);
   }
   else
   {
      printf("%d is a internal node can't be deleted.\n", key);
      return -1;
   }

   return hold;
}

int findmax(struct btree *root)
{
   struct btree *tr = root;

   while (tr->right != NULL)
   {
      tr = tr->right;
   }

   return tr->info;
}

void search(struct btree *root, int key)
{
   struct btree *tr = root;

   while (tr->info != key)
   {
      if (key >= tr->info)
      {
         tr = tr->right;
      }
      else
      {
         tr = tr->left;
      }

      if (tr == NULL)
      {
         printf("%d is not a part of the tree.\n", key);
         return ;
      }
   }

   printf("%d is a part of the tree.\n", key);
   return ;
}

void cleartree(struct btree *root)
{
   root = NULL;
   free(root);
   return ;
}

/********* MAIN STARTS HERE *********/ 
int main(void)
{
   int          opt, val, h = 0;
   //struct btree root = NULL;

   while (opt != 12)
   {
      opt = menu();
      system("clear");
      switch (opt)
      {
         case 1:
               printf("Enter the node to be inserted: ");
               scanf("%d", &val);
               h = insert(val, h);
               break;
         case 2:
               printf("*** In-order Traversal ***\n");
               intraver(root);
               break;
         case 3:
               printf("*** Pre-order Traversal ***\n");
               pretraver(root);
               break;
         case 4:
               printf("*** Post-order Traversal ***\n");
               posttraver(root);
               break;
         case 5:
               printf("*** Delete a leaf node ***\n");
               printf("Enter the leaf node to be deleted: ");
               scanf("%d", &val);
               val = delleaf(root, val);
               printf("%d is deleted.\n", val);
               break;
         case 6:
               printf("*** Delete a Internal node with left rotation ***\n");
               printf("Enter the node to be deleted: ");
               scanf("%d", &val);
               delnodel(root, val);
               printf("%d is deleted.\n", val);
               break;
         case 7:
               printf("*** Delete a Internal node with right rotation ***\n");
               printf("Enter the node to be deleted: ");
               scanf("%d", &val);
               delnoder(root, val);
               printf("%d is deleted.\n", val);
               break;
         case 8:
               printf("*** Search for a node ***\n");
               printf("Enter the node to be searched: ");
               scanf("%d", &val);
               search(root, val);
               break;
         case 9:
               printf("*** Maximum elemnet of the tree ***\n");
               val = findmax(root);
               printf("Maximum element is %d\n", val);
               break;
         case 10:
               printf("Height of the tree is %d.\n", h);
               break;
         case 11:
               display(root, h);
               break;
         case 12:
               cleartree(root);
               printf("Hope you had a good time with my Data-structure :-)\n");
               exit(0);
         default:
               break;
      }
   }

   cleartree(root);
   exit(0); 
}

/********* FUNCTION DEFINITION *********/
int menu()
{
   int       option;

   printf("\n----------------------------------\n");
   printf("    Binary Search Tree(BST)       \n");
   printf("----------------------------------\n");
   printf("Your operations are: \n");
   printf("1) Insert a node.\n");
   printf("2) Perform a In-order traversal.\n");
   printf("3) Perform a Pre-order traversal.\n");
   printf("4) Perform a Post-order traversal.\n");
   printf("5) Delete a leaf node.\n");
   printf("6) Delete a Internal node with left rotation.\n");
   printf("7) Delete a Internal node with right rotation.\n");
   printf("8) Search for a node.\n");
   printf("9) Maximum element in tree.\n");
   printf("10) Height of the tree.\n");
   printf("11) Display the tree.\n");
   printf("12) Exit\n");

   printf("Enter your choice: ");
   scanf("%d", &option);

   return option;
}
