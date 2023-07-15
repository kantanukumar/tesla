#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int val;
  struct node *next;
}node;

void add_node(struct node *h, int val)
{
  if(h == NULL)
   return;

  else
  {
    node *temp = NULL;
    temp = h;

    while(temp && temp->next)
    {
      temp = temp->next;
    }

    node *new = NULL;

    new = malloc(sizeof(node));

    new->next = NULL;
    new->val = val;
    temp->next = new;
  }
  return;
}

void print_list(node *h)
{
  while(h)
  {
    printf("%d->", h->val);
    h = h->next;
  }

  printf("NULL\n");

 return;
}

void add_node_at_head(node **head, int val)
{
  node *new = NULL;

  new = (node*) malloc(sizeof(node));
 
  new->next = *head;
  new->val = val;

  *head = new;
 
  return;
}

void reverse_list(node **head)
{
  node *prev = NULL;
  node *cur  = *head;
  node *next = NULL;

  while(cur)
  {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }

  *head = prev;

  return;
}

void find_loop(node **head)
{
  node *t1 = *head;
  node *t2 = (*head)->next;

  while(t1 && t2)
  {
    if(t1 != t2)
    {
      t1 = t1->next;
      t2 = t1->next;
    }
    else
    {
     printf("Loop at %p val=%d\n", t1, t1->val);
     break;
    }
  }
}

int retAddr(void)
{
  // Prints the address of the local variable to say if its up growing
  // or downgrowing stack.
  // If the address is lesser than that of a var in main(),
  // that means the stack grows downwards
  int x;
  printf("Address of x = %p\n", &x);
  return 0;
}

void deleteNode(node **head, int val)
{
  node *t1, *t2;

  t1 = *head;

  if(t1)
  {
    t2 = t1->next;

    if(t1->val == val) // val found at head, Head need to be removed
    {
      *head = t1->next;
      free(t1);
    }
    else
    {
      while(t2)
      {
        if(t2->val == val)
        {
          t1->next = t2->next;
          free(t2);
          break;
        }
        else
        {
          t2 = t2->next;
          t1 = t1->next;
        }
      }
    }
  }
}

void insertNodeBeforeVal(node **head, int val)
{
  node *temp = *head;
  if(val < temp->val)
  {
    node *new = (node*)malloc(sizeof(node));
    new->val = val;
    new->next = *head;
    *head = new;
    return;
  }
  else
  {
    node *next = temp->next; // Head next
    node *prev = NULL;

    while(next && (val > next->val))
    {
      prev = next;
      next = next->next;
    }
    node *new = (node*)malloc(sizeof(node));
    new->val = val;
    new->next = next;
    prev->next = new;
  }
}

int main(int argc, char **argv)
{
  node *head = NULL;

  int itr = 0;
  int i = 1;

  if(argc == 2)
  {
    itr = atoi(argv[1]);

    if(itr < 0)
      itr = 1;
  }
  else
  {
    printf("Invalid arguments number, expecting 2 arguments. Exit\n");
    return -1;
  }

  printf("argc=%d, itr=%d\n", argc, itr);

  while(itr--)
  {
    add_node_at_head(&head, i++);
  }

  print_list(head);

  printf("\n");

  // add more to linked list for loop test
  // itr = 3; i = 1;
  // while(itr--)
  // add_node_at_head(&head, i++);
  // print_list(head);

  printf("\n");

  // delete the node, with value 4
  deleteNode(&head, 4);

  // find_loop(&head);

  reverse_list(&head);
  printf("Print list after reverse: ");
  print_list(head);

  printf("\n");

  insertNodeBeforeVal(&head, 4);
  printf("Print list after insert before: ");
  print_list(head);
#if 0
  int x;
  char *cPtr = "Myname";
  printf("local var e addr =%p\n", &x);
  printf("Value from retAddr=%p\n", retAddr());
  printf("Addr of cPtr=%p\n", &cPtr);
#endif

	return 0;
}
