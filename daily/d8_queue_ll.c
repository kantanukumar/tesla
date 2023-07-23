/*
 * Day: 8
 * Date: 14/07/23
 * Problem: Create a Q using linked list.
 * Approach: Create linked list and have front and rear pointers.
 * Files: d8_queue_ll.c
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *front = NULL;
struct node *rear  = NULL;

/*
  This also can be reformatted as below:
  struct queue
  {
    struct node *qFront;
    struct node *qRear;
    int qElemCnt;
  };
*/

int elemCnt = 0;

void enQ(int data)
{
  printf("EnQ %d to rear of the list\n", data);

  struct node *newNode = NULL;

  newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = NULL;

  // First element to insert
  if(rear == NULL)
  {
    rear  = newNode;
    front = newNode;
  }
  else
  {
    rear->next = newNode;
    rear = newNode;
  }
  elemCnt++;

  return;
}

int deQ()
{
  int elem = 0;

  if(front == NULL)
  {
    printf("Err: Empty Q - Can't DeQ\n");
    return -1;
  }
  else
  {
    struct node *temp = NULL;

    elem = front->data;
    temp = front;
    front = front->next;
    free(temp);
    --elemCnt;
  }
  return elem;
}

void display()
{
  struct node *temp = front;

  printf("Q is: ");
  while(temp)
  {
    printf("%d->", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

int main(int argc, char *argv[])
{
  // Function body
  if(argc > 1)
  {
    printf("Passed more than one argument, process it\n\n");

    // Process the arguments, those contains the elem

    int idx = 1;
    int data = 0;

    while(argc != 1)
    {
      data = atoi(argv[idx]);
      enQ(data);
      ++idx; --argc;
    }
  }

  display();

  printf("DeQ from Q, elem=%d\n", deQ());
  display();

  printf("\nEnd of the program\n");

  return 0;
}
