#include <stdio.h>		/*Has the default */
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *link;
};

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

void displayLList(struct Node *head)
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

int main()
{
	struct Node *head = NULL;

	//	menu();
	//	int choice = choiceByUser();
	insertEnd(&head, 455);
	insertEnd(&head, 45);
	displayLList(head);
	//	countNodes();
}
