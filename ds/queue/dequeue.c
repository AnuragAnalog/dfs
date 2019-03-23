#include <stdio.h>
#include <stdlib.h>

/********* FUNCTION DECLARATION *********/
int menu();

/********* DATA-STRUCTUR DEFINITION *********/
typedef struct dequeue
{
   int              info;
   struct dequeue  *link;
} Dequeue;

int llistsize(struct dequeue **head)
{
   int        size = 0;
   Dequeue   *tmp = *head;

   while (tmp != NULL)
   {
      tmp = tmp->link;
      size++;
   }

   return size;
}

int isempty(struct dequeue **head)
{
   return (*head == NULL);
}

void addbeg(int data, struct dequeue **head)
{
   Dequeue      *tmp;

   tmp = (struct dequeue *) malloc(sizeof(struct dequeue));
   tmp->info = data;

   if (*head == NULL)
   {
      *head = tmp;
      tmp->link = NULL;
   }
   else
   {
      tmp->link = *head;
      *head = tmp;
   }

   return ;
}

void addend(int data, struct dequeue **head)
{
   Dequeue     *tmp, *tr;

   tr = *head;

   if (*head == NULL)
   {
      addbeg(data, head);
      return ;
   }

   tmp = (struct dequeue *) malloc(sizeof(struct dequeue));

   while (tr->link != NULL)
   {
      tr = tr->link;
   }

   tmp->info = data;
   tmp->link = NULL;
   tr->link = tmp;

   return ;
}

int delbeg(struct dequeue **head)
{
   int                 hold;
   struct dequeue     *tmp;

   if (isempty(head))
   {
      printf("The Linked list is empty you can't delete any nodes\n");
      return 0;
   }
   else
   {
      tmp = *head;
      hold = tmp->info;
      *head = tmp->link;
      free(tmp);
   }

   return hold;
}

int delend(struct dequeue **head)
{
   int                 hold;
   struct dequeue     *cur, *pre;

   if (isempty(head))
   {
      printf("The Linked list is empty you can't delete any nodes\n");
      return 0;
   }
   else
   {
      cur = *head;
      while (cur->link != NULL)
      {
         pre = cur;
         cur = cur->link;
      }

      hold = cur->info;
      pre->link = NULL;
      free(cur);
   }

   return hold;
}

void display(struct dequeue **head)
{
   struct dequeue     *tmp;

   if (isempty(head))
   {
      printf("It's an empty linked list can't display anything.\n");
      return ;
   }
   else
   {
      tmp = *head;
      printf("Elements of the list are:\n");
      while (tmp != NULL)
      {
         printf("%d ", tmp->info);
         tmp = tmp->link;
      }
      printf("\n");
   }

   return ;
}

void clearqueue(struct dequeue **head)
{
   while (*head != NULL)
   {  
      delbeg(head);
   }
   free(*head);

   return ;
}

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
   int        opt, val;
   struct dequeue *head = NULL;
   //Dequeue   sl;

   while (opt != 6)
   {
      opt = menu();
      system("clear");
      switch (opt)
      {
         case 1:
               printf("Enter the value to be inserted: ");
               scanf("%d", &val);
               addbeg(val, &head);
               printf("Element inserted at beginning.\n");
               break;
         case 2:
               printf("Enter the value to be inserted: ");
               scanf("%d", &val);
               addend(val, &head);
               printf("Element inserted at End\n");
               break;
         case 3:
               val = delbeg(&head);
               printf("%d deleted from beginning.\n", val);
               break;
         case 4:
               val = delend(&head);
               printf("%d deleted from end.\n", val);
               break;
         case 5:
               display(&head);
               break;
         case 6:
               clearqueue(&head);
               printf("Hope you had a good time with my Data-structure :-)\n");
               exit(0);
         default:
               break;
      }
   }

   clearqueue(&head);
   exit(0);
}

/********* FUNCTION DEFINITION *********/
int menu()
{
   int       option;

   printf("----------------------------------\n");
   printf("         Single linked list       \n");
   printf("----------------------------------\n");
   printf("Your operations are: \n");
   printf("1)  Insert at the Beginning of queue.\n");
   printf("2)  Insert at the end of queue.\n");
   printf("3)  Delete at the Beginning of queue.\n");
   printf("4)  Delete at the end of queue.\n");
   printf("5)  Display the queue.\n");
   printf("6) Exit\n");

   printf("Enter your choice: ");
   scanf("%d", &option);

   return option;
}
