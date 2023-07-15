#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node *next;
}*head = NULL;

void insert_end(int data)
{
    printf("inserting %d to back\n", data);

    struct node *newNode, *p;
    p = head;
    newNode = NULL;

    newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    
    // First node
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    else
    {
      while(p->next)
      {
        p = p->next;
      }
      p->next = newNode;
    }
}

void insert_front(int data)
{
  struct node *newNode = NULL, *p;

  p = head;

  newNode = (struct node*)malloc(sizeof(struct node));

  newNode->data = data;
  newNode->next = NULL;

  // First node
  if (head == NULL)
  {
    head = newNode;
    return;
  }
  else
  {
    newNode->next = head;
    head = newNode;
  }
}

void insert_pos(int data, int pos)
{
  struct node *p, *q, *newNode;
  p = head;

  newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = data;

  if(pos == 0)
  {
    head = newNode;
    return;
  }

  int i = 1;
  while(p && i < pos)
  {
    q = p;
    p = p->next;
    i++;
  }

  newNode->next = q->next;
  q->next = newNode;

}

struct node* findKthNode(struct node *first, int pos)
{
  struct node *t1, *t2;
  t1 = first;

  int i = 0;

  if(pos == 0)
    return first;

  while(t1 && i < pos)
  {
    t1 = t1->next;
    i++;
  }

  return t1;
}

int deleteKthNode(struct node **first, int pos)
{
  struct node *t1, *t2;

  t1 = t2 = *first;

  int i = 0;

  if(pos == 0)
  // remove head
  {
    t1 = *first;
    *first = t1->next;
    free(t1);
    return 1;
  }

  while(t1 && i++ < pos)
  {
    t2 = t1; // Save the prev address
    t1 = t1->next;
  }

  if(t2 && t1)
  {
    t2->next = t1->next;
    free(t1);
    return 1;
  }
  else
  {
    return 0; // Pos not found
  }
}

void printList(void)
{
    printf("list is ");

    struct node *p = head;

    while(p)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int isListSorted(struct node *first)
{
#include <limits.h>
  int x = INT_MIN;

  struct node *p = first;

  while(p)
  {
    if(p->data < x)
    {
      return 0;
    }
    else
    {
      x = p->data;
      p = p->next;
    }
  }
  return 1;
}

int removeDuplicates(struct node *first)
{
  struct node *t1 = first;
  struct node *t2 = t1->next;

  int cnt = 0;
  while(t1 && t2)
  {
    if(t1->data != t2->data)
    {
      t1 = t2;
      t2 = t2->next;
    }
    else
    {
      t1 = t2->next;
      free(t2);
      if(t1)
      {
        t2 = t1->next;
        cnt++;
      }
    }
  }
  return cnt;
}

int main(int argc, char *argv[])
{
    struct node *p;
    int pos = 0;

    for(int i = 1; i < 8; i++)
    {
        insert_end(i);
    }
    insert_end(7);
    printList();

    // insert_end(-1);


    if(argc == 2)
      pos = atoi(argv[1]);

    insert_pos(2, atoi(argv[1]));
    printList();

    //struct node *kthNode = findKthNode(head, atoi(argv[1]));
    //printf("Data at %dth node = %d\n", atoi(argv[1]), kthNode->data);

    // printf("\nDelete node %d %s\n", pos, deleteKthNode(&head, pos) ? "Success" : "Fail");
    
    // printList();
    //
    printf("Sorted: %s\n", isListSorted(head)? "True" :"False");

   // if(!isListSorted(p))
   //   sortList(p);

    printf("Remove %d duplicates\n", removeDuplicates(head));

    printList();

    return 0;
}

