/*
 * Day: 10
 * Date: 16/07/23
 * Problem: Create a tree.
 * Approach: Use left and right pointers, which will point to child nodes.
 * Files: d10_tree_create.c
 */

#include <stdio.h>
#include <stdlib.h>

struct tNode
{
  struct tNode *left;
  int data;
  struct tNode *left;
};

void insert_begin(int data)
{
  printf("Insert %d at start of DLL\n", data);

  struct node *newNode = (struct node*)malloc(sizeof(struct node));
  newNode->prev = NULL;
  newNode->next = NULL;
  newNode->data = data;

  if(head == NULL)
  {
    head = newNode;
  }
  else
  {
     newNode->next = head;
     newNode->prev = head->prev;
     head = newNode;
  }
}

void insert_end(int data)
{
  printf("Insert %d at end of DLL\n", data);

  struct node *newNode, *temp = head;

  newNode = (struct node*)malloc(sizeof(struct node));
  newNode->prev = NULL;
  newNode->next = NULL;
  newNode->data = data;

  if(head == NULL)
  {
    head = newNode;
  }
  else
  {
    // Traverse till NULL
    while(temp->next)
    {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
  }
}

void display()
{
  struct node *temp = head;

  printf("The DLL is: NULL<->");

  while(temp)
  {
    printf("%d<->", temp->data);
    temp = temp->next;
  }

  printf("NULL\n");
}

int length()
{
  struct node *temp = head;
  int count = 0;

  printf("The DLL is: NULL<->");

  while(temp)
  {
    count++;
    printf("%d<->", temp->data);
    temp = temp->next;
  }

  printf("NULL\n");
  printf("Len=%d\n", count);

  return count;
}

void insert_pos(int pos, int data)
{
  printf("Inserting %d at pos %d\n", data, pos);

  if(pos > length())
  {
    printf("Inserting pos beyond len\n");
    return;
  }
  else
  {
    if(head == NULL && pos != 1)
    {
      printf("No nodes in DLL\n");
      return;
    }
    else
    {
      struct node *newNode, *temp = head;

      newNode = (struct node*)malloc(sizeof(struct node));
      newNode->prev = NULL;
      newNode->next = NULL;
      newNode->data = data;

      if(pos == 1)
      {
        // First node
        head->next->prev = newNode;
        newNode->next = head;
        head = newNode;
        return;
      }
      else
      {
        int idx = 1;
        while(idx < (pos-1))
        {
          temp = temp->next;
          ++idx;
        } 

        if(temp->next)
        {
          temp->next->prev = newNode;
          newNode->next = temp->next;
        }
        newNode->prev = temp;
        temp->next = newNode;
      }
    } 
  }
}

void delete_pos(int pos)
{
  printf("Deleting pos %d\n", pos);

  if(pos > length())
  {
    printf("Error: Deleting pos beyond len\n");
    return;
  }
  else
  {
    if(head == NULL && pos != 1)
    {
      printf("Error: No nodes in DLL\n");
      return;
    }
    else
    {
      struct node *temp = head;

      if(pos == 1)
      {
        // Delete the first node
        head = temp->next;
        
        // Checks if we have second node or not
        if(head)  
          head->prev = NULL;

        free(temp);
        return;
      }
      else // Any node, doesn't matter
      {
        int idx = 1;
        while(idx++ < pos-1)
          temp = temp->next;

        struct node* delNode = temp->next;
        temp->next = delNode->next;

        if(delNode->next)
          delNode->next->prev = temp;

        free(delNode);
      }
    }
  }
}

struct tNode* createTreeNode(int data)
{
  struct tNode *newNode = (struct tNode*)malloc(sizeof(struct tNode));

  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
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

    struct tNode *root = createTreeNode(1);

    root->left = createTreeNode(2);
    root->right= createTreeNode(3);


    while(i != 15)
    {
      temp = createTreeNode():
      temp->right= createTreeNode();
      temp->left = createTreeNode();


    }

    while(argc != 1)
    {   
      data = atoi(argv[idx]);
      createTreeNode(data);
      ++idx; --argc;
    }
  }

  display();

  printf("\nEnd of the program\n");

  return 0;
}
