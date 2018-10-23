#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};


void add_node(struct node **head, int data)
{
	if(head == NULL)
	{
		printf("List is empty... Adding it as first node\n");

		*head = (struct node*) malloc(sizeof(struct node));

		*head->data = data;
		*head->next = NULL;

    printf("Node with data=%d added to list\n", data);
	}

}

int main(int argc, char** argv)
{
	printf("Single ll\n");

	struct node *head = NULL;
	int data = 0;

	do
	{
		printf("Add node\n");

		printf("Enter data: "); scanf("%d\n", &data);

		add_node(&head, data);

		printf("press q to exit\n");
	}while(getchar() != 'q');

}

