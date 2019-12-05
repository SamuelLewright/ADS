//Samuel Lewright

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10000

int charArray[MAX];
int itemCount = 0;
int count = 0;


bool isEmpty() {
   return itemCount == 0;
}

bool isFull() {
   return itemCount == MAX;
}

int size() {
   return itemCount;
}  

struct node{
    char *randomString;
    struct node *next;
}
typedef struct node node;

void enqueue(char * string, struct node ** front, struct node ** rear) 
{
   struct node *newNode = (struct node*)malloc(sizeof(node));
   newNode->randomString=string;
   newNode->next=NULL;
   if(front == NULL)
   {
       *front=*rear=newNode;
   }
   else
   {
       *rear=newNode->next;
       *rear=newNode;
   }
}

char *dequeue(struct node ** front, struct node ** rear) 
{
    struct node * tempNode;
    if(*front != NULL)
    {
        struct node *frontNode=front;
        *front = tempNode -> next;
        return frontNode -> randomString;
    }
    else
    {
        return NULL;
    }
}

char *randomString(size_t length)
{
   static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";
   char* rand_String = NULL;

   if(length)
   {
      rand_String = malloc(sizeof(char) * (length + 1));

      if(rand_String != NULL)
      {
         int i;
         for(i = 0; i < length; i++)
         {
            int randy = rand() % (int)(sizeof(charset)-1);
            rand_String[i] = charset[randy];
         }

         rand_String[length] = '\0';
      }
   }
   return rand_String;
}

int main() 
{
    
   *front=NULL , *rear=NULL;

   //first 10 enqueues
   int i;
   for(i = 0; i < 10; i++)
   {
      char* string;
      string = randomString(1000000);
      enqueue(string, &front, &rear);
      //printf("\n%s" , string);
      free(string);
   }
   int j;
   for(j = 0; j < 100000; j++)
   {
       char* string;
       string = randomString(1000000);
       enqueue(string, &front, &rear);
       dequeue(&front, &rear);
       count++;
       free(string);
   }
   int s;
   for(s = 0; s < 12; s++)
   {
       dequeue(&front, &rear);
       count++;
   }
   printf("%d dequeues" , count);
}
