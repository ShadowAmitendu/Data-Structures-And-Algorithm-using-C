#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

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