/*
 * This is a template to create the daily challenge.
 * Need to put the day name, date and problem in below format.
 *
 * This file has to be copied and renamed before starting a challenge.
 * If multiple files are required, it has to follow the same notation
 * as this file.
 *
 * If accepting more than one challenge, then create file in dn_m_problem.c format.
 *
 * Any improvements need to be all files has to be done here, so that
 * it will be applicable to all files.
 * 
 * Day: 3
 * Date: 9/07/23
 * Problem: Create a circular linked list.
 * Approach: Use global head to create a list.
 * Files: d3_problem.c
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *head = NULL;

void insert_end(int data)
{
  printf("Insert %d at end of the circular LL\n", data);

  struct node *newNode, *temp = head;

  newNode = (struct node*) malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = newNode; // Circular

  if(head == NULL)
  {
    head = newNode;
  }
  else
  {
    while(temp->next != head)
      temp = temp->next;

    // temp->next is head, we need to add that node to temp.
    temp->next = newNode;
    newNode->next = head;
  }
}

void insert_start(int data)
{
  printf("Insert %d at start of the circular LL\n", data);

  struct node *newNode, *temp = head;

  newNode = (struct node*) malloc(sizeof(struct node));
  newNode->data = data;

  if(head == NULL)
  {
    head = newNode;
    newNode->next = newNode; // Circular
  }
  else
  {
    while(temp->next != head)
      temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
    head = newNode;
  }
}

void display(void)
{
  printf("Circular link list is: ");

  struct node *temp = head;

  do
  {
    printf("%d->", temp->data);
    temp = temp->next;
  }while(temp != head);

  printf("head\n");
}

int main(int argc, char *argv[])
{
  // Function body
  if(argc > 1)
  {
    printf("Passed more than one argument, process it\n\n");

    // Process the arguments, those contains the node value

    int idx = 1;
    int data = 0;

    while(argc != 1)
    {   
      data = atoi(argv[idx]);
      // insert_end(data);
      insert_start(data);
      ++idx; --argc;
    }   
  }

  display();

  printf("\nEnd of the program\n");

  return 0;
}
