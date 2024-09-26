#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

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
void deleteNth(struct Node **head, int data, int place)
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