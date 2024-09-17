#include <stdio.h>	/*Has the Standard Input and Output Functions */
#include <stdlib.h> /*Has the Malloc Function*/

/*Node Structure*/
struct Node
{
	int data;
	struct Node *link;
};

/*Listing the Functions*/
/*For User*/
void menu();
int choice();

/*Essential and For Efficient use*/
int isNull(struct Node *head);
int countNodes(struct Node *head);

/*Display Function*/
void display(struct Node *head);

/*Insert Functions*/
void insertEnd(struct Node **head, int data);
void insertStart(struct Node **head, int data);
void insertNth(struct Node **head, int data, int place);

/*Delete Functions*/
void deleteEnd(struct Node *head);
struct Node *deleteStart(struct Node *head);
void deleteNth(struct Node **head, int place);

/*Main Entry Point of the Program*/
int main()
{
	struct Node *head = NULL;

	// Insert elements at the end
	printf("Inserting at the end:\n");
	insertEnd(&head, 10);
	insertEnd(&head, 20);
	insertEnd(&head, 30);
	insertEnd(&head, 40);
	display(head);
	printf("\n");

	// Insert element at the start
	printf("Inserting at the start:\n");
	insertStart(&head, 5);
	display(head);
	printf("\n");

	// Insert element at position 3
	printf("Inserting at position 3:\n");
	insertNth(&head, 25, 3);
	display(head);
	printf("\n");

	// Display total number of nodes
	printf("Total number of nodes: %d\n", countNodes(head));

	// Delete element from the end
	printf("Deleting from the end:\n");
	deleteEnd(head);
	display(head);
	printf("\n");

	// Delete element from the start
	printf("Deleting from the start:\n");
	head = deleteStart(head);
	display(head);
	printf("\n");

	// Delete element at position 3
	printf("Deleting from position 3:\n");
	deleteNth(&head, 3); // Data is not necessary here for deletion
	display(head);
	printf("\n");

	// Display total number of nodes again
	printf("Total number of nodes after deletion: %d\n", countNodes(head));
}

int isNull(struct Node *head)
{
	return (head == NULL);
}

int countNodes(struct Node *head)
{
	int count = 0;
	struct Node *temp = head;

	if (isNull(head))
	{
		printf("LIST IS EMPTY");
	}
	else
	{
		while (temp != NULL)
		{
			count++;
			temp = temp->link;
		}
	}
	return count;
}

void display(struct Node *head)
{
	struct Node *temp = head;

	if (isNull(head))
	{
		printf("LIST IS EMPTY");
	}
	else
	{
		while (temp != NULL)
		{
			printf("%d -> ", temp->data);
			temp = temp->link;
		}
		printf("NULL!");
	}
}

void insertEnd(struct Node **head, int data)
{
	struct Node *temp = *head;
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

	newNode->data = data;
	newNode->link = NULL;

	if (isNull(*head))
	{
		*head = newNode;
	}
	else
	{
		while (temp->link != NULL)
		{
			temp = temp->link;
		}
		temp->link = newNode;
	}
}
void insertStart(struct Node **head, int data)
{
	struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
	ptr->data = data;
	ptr->link = *head;

	*head = ptr;
}
void insertNth(struct Node **head, int data, int place)
{
	if (isNull(*head))
	{
		printf("LIST IS EMPTY");
	}
	else
	{
		struct Node *temp = *head;
		struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

		ptr->data = data;
		ptr->link = NULL;

		while (place != 2)
		{
			temp = temp->link;
			place--;
		}
		ptr->link = temp->link;
		temp->link = ptr;
	}
}

void deleteEnd(struct Node *head)
{
	if (isNull(head))
	{
		printf("LIST IS EMPTY");
	}
	else
	{
		struct Node *temp = head;
		while (temp->link->link != NULL)
		{
			temp = temp->link;
		}
		free(temp->link);
		temp->link = NULL;
	}
}
struct Node *deleteStart(struct Node *head)
{
	if (isNull(head))
	{
		printf("LIST IS EMPTY");
	}
	else
	{
		struct Node *temp = head;
		head = head->link;
		free(temp);
		temp = NULL;
	}
	return head;
}
void deleteNth(struct Node **head, int place)
{
	struct Node *prev = *head, *cur = *head;
	if (isNull(*head))
	{
		printf("LIST IS EMPTY");
	}
	else if (place == 1)
	{
		*head = cur->link;
		free(cur);
		cur = NULL;
		prev = NULL;
	}
	else
	{

		while (place != 1)
		{
			prev = cur;
			cur = cur->link;
			place--;
		}
		prev->link = cur->link;
		free(cur);
		cur = NULL;
	}
}