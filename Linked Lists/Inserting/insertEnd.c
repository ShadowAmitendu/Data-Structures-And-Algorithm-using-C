#include <stdio.h>
#include <stdlib.h>
#include "insertEnd.h"

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
