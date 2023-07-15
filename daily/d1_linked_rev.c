/*
 * Day: 1
 * Date: 7/07/23
 * Problem: Create a linked list and reverse it.
 * Approach: Use global head to create a list.
 * Files: d1_linked_rev.c
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *head = NULL;

void insert_start(int data)
{
  printf("Insert %d to start of the list\n", data);

  struct node *newNode = NULL, *temp = head;
  newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = NULL;

  if(head == NULL)
    head = newNode;
  else
  {
    newNode->next = head;
    head = newNode;
  }

  return;
}

void display()
{
  struct node *temp = head;

  printf("List is: ");
  while(temp)
  {
    printf("%d->", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

void reverse()
{
  struct node *prev = NULL, *curr = head, *next = NULL;

  printf("Reversing linked list. . .\n");

  while(curr)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  head = prev;
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
      insert_start(data);
      ++idx; --argc;
    }
  }

  display();

  reverse();
  display();

  printf("\nEnd of the program\n");

  return 0;
}
