#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
}Node;

void display(Node *head)
{
  printf("List is: ");
  while(head)
  {
    printf("%d->", head->data);
    head = head->next;
  }
  printf("NULL\n");
}

void insert_front(Node **head, int data)
{
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if(*head == NULL)
  {
    // Add the new node as head
    *head = newNode; 
    return;
  }
  else
  {
    Node *temp = *head;
    *head = newNode;
    newNode->next = temp;
  }
}

// This can be called as "append".
// Let the list be 1->2->3->NULL, it will add 4 after 3.
void insert_back(Node **head, int data)
{
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  Node *temp = *head;

  // New list
  if(*head == NULL)
  {
    *head = newNode;
    return;
  }
  else
  {
    while(temp->next)
      temp = temp->next;

    temp->next = newNode;
  }
}

void auto_create_list(Node **head, int num)
{
  while(num)
  {
    // Create list like 4->3->2->1->NULL
    // insert_back(head, num--);
    
    // Create list like 1->2->3->4->NULL
    insert_front(head, num--);
  }
  printf("List created auto\n");
}

int main(int argc, char *argv[])
{
  Node *head = NULL;
  int ch = 0;

  do
  {    
    printf("\nAll the menu of linked list:\n");
    printf("Press '1' to create a list automatically\n");
    printf("Press '2' to create a list adding values\n");
    printf("Press '3' to insert to list at the start\n");
    printf("Press '4' to insert to list at the end\n");

    printf("Press '8' to delete the list automatically\n");
    printf("Press '9' to display the list\n");
    printf("Press '0' to Exit\n");

    scanf("%d", &ch);

    switch(ch)
    {
      case 1:
        int num = 0;
        printf("Provide number of elements to create list: ");
        scanf("%d", &num);
        auto_create_list(&head, num);
        break;

      case 9:
        display(head);
        break;

      case 0:
        printf("\nExiting linked list menu\n");
        break;

      default:
        break;
    }
  }while( ch != 0);

  return 0;
}