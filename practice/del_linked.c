#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// struct node *head = NULL;

// With global head
void insert_at_begin();
void insert_at_end();

void insert_ptr_begin(struct node **start);
void insert_ptr_end(struct node **start, int data);

#if 0
void insert_at_begin()
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->next = NULL;
    printf("Data to insert at begin: ");
    scanf("%d", &newNode->data);

    if(head == NULL)
        head = newNode;
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void insert_at_end()
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->next = NULL;
    printf("Data to insert at end: ");
    scanf("%d", &newNode->data);
    
    if(head == NULL)
    {     
        head = newNode;
        return;
    }
    else
    {
        struct node *temp=head;
        
        while(temp->next)
            temp = temp->next;
        
        temp->next = newNode;
    }
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
#endif

void insert_ptr_begin(struct node **head)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->next = NULL;

    printf("Enter data to add at front: ");
    scanf("%d", &newNode->data);

    if(*head == NULL)
        *head = newNode;
    else
    {
        newNode->next = *head;
        *head = newNode;
    }
}

void insert_ptr_end(struct node **head, int data)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->next = NULL;

    printf("Entering %d to add at end\n", data);
    newNode->data = data;

    // printf("Enter data to add at end: ");
    // scanf("%d", &newNode->data);

    if(*head == NULL)
        *head = newNode;
    else
    {
        struct node *temp = NULL;
        temp = *head;
        
        while(temp->next)
            temp = temp->next;
        
        temp->next = newNode;
    }
}
void display(struct node *head)
{
    printf("List is: ");

    while(head)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void find_duplicates(struct node **head)
{
    struct node *temp = *head;

    if(*head == NULL)
        return;
    else
    {
        while(temp)
        {
            struct node *cur  = temp;
            struct node *next = cur->next;

            while(next)
            {
                if(temp->data == next->data)
                {
                    // Duplicate found
                    printf("Duplicate data %d found\n", temp->data);

                    // We will delete the next;
                    cur->next = next->next;

                    free(next);

                    next = cur->next;            
                }
                else
                {
                    cur = cur->next;
                    next = next->next;
                }

            }
            temp = temp->next;
        }
    }
}

void reverse(struct node **head)
{
    struct node *current = *head, *prev, *next;
    prev = NULL;

    while(current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void rev_recursive(struct node **p)
{
    if((*p)->next == NULL)
    {
        *head = *p;
        return;
    }
    
    rev_recursive(p->next);
    struct node *q = p->next;
    p->next = q;
    q->next = NULL;
}
int main()
{
    // Code to use the local head and send it to the function
    struct node *head = NULL;


    // for(int j = 0; j < 10000; j++)
        for(int i = 1; i <= 10; i++)
            insert_ptr_end(&head, i);
    
    display(head);

    // reverse(&head);

    rev_recursive(head);

        // find_duplicates(&head);
    display(head);
}




    #if 0
    Below is code to have the global head, which is if zeroed, for now
    //insert_at_begin();
    //insert_at_begin();
    //insert_at_begin();

    insert_at_end();
    insert_at_end();
    insert_at_end();
    display();
    #endif