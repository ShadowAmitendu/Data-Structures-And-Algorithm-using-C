#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

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