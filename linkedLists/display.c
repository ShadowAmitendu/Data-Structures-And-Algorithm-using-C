#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

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