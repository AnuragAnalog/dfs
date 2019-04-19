#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/********* FUNCTION DECLARATION *********/
bool isprime(int n);
int bigprime(int n);
int menu();
void linear_prob(int *hash, int data, int m);
void quadratic_prob(int *hash, int data, int m);
void displaytable(int hash[], int n);

/********* MAIN STARTS HERE *********/
int main(void)
{
   int           i, n, m, opt, val, *hash;
   
   printf("Enter the no. of elements: ");
   scanf("%d", &n);
   
   m = bigprime(n);
   printf("No. of buckets are: %d, which is a prime.\n", m);

   hash = (int *)calloc(m, sizeof(int));
   for (i = 0; i < m; i++)
   {
      hash[i] = -1;
   }

   while (opt != 4)
   {
      opt = menu();
      system("clear");
      switch (opt)
      {
         case 1:
               printf("Enter the value to be inserted: ");
               scanf("%d", &val);
               linear_prob(hash, val, m);
               break;
         case 2:
               printf("Enter the value to be inserted: ");
               scanf("%d", &val);
               quadratic_prob(hash, val, m);
               break;
         case 3:
               displaytable(hash, m);
               break;
         case 4:
               printf("Hope you had a good time with my Data-structure :-)\n");
               exit(0);
         default:
               printf("Invalid choice\n");
      }
   }

   exit(0);
}

/********* FUNCTION DEFINITION *********/
int menu()
{
   int       option;

   printf("================================\n");
   printf("            Hashing             \n");
   printf("================================\n");
   printf("Your operations are: \n");
   printf("1)  Insertion through linear probing.\n");
   printf("2)  Insertion through quadratic probing.\n");
   printf("3)  Display the # table\n");
   printf("4)  Exit\n");

   printf("Enter your choice: ");
   scanf("%d", &option);

   return option;
}

void linear_prob(int *hash, int data, int m)
{
   int        i = 0, key;
   
   key = data%m;
   while (hash[key] != -1)
   {
      i = i + 1;
      key = (data+i)%m;
   }
   hash[key] = data;
   
   return ;
}

void quadratic_prob(int *hash, int data, int m)
{
   int        i = 0, key;
   
   key = data%m;
   while (hash[key] != -1)
   {
      i = i + 1;
      key = (data+i*i)%m;
   }
   hash[key] = data;
   
   return ;
}

void displaytable(int hash[], int n)
{
   int        i;

   printf("\n===============================\n");
   printf("           Hash-table          \n");
   printf("===============================\n");
   for (i = 0; i < n; i++)
   {
      if (hash[i] == -1)
      {
         printf("%d\t:\n", i); 
      }
      else
      {
         printf("%d\t: %d\n", i, hash[i]);
      }
   }

   return ;
}

bool isprime(int n)
{
   int         i;

   if (n%2 == 0)
   {
      return false;
   }

   for (i = 3; i < n; i = i + 2)
   {
      if (n%i == 0)
      {
         return false;
      }
   }

   return true;
}

int bigprime(int n)
{
   int         i, p = n;

   for (i = n; i < n+25; i++)
   {
      if (isprime(i))
      {
         p = i;
      }
   }

   return p;
}
