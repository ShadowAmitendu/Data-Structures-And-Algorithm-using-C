#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} Dnode;

void dinsert_beg(Dnode **head, int value)
{
    Dnode *new_node = (Dnode *)malloc(sizeof(Dnode));
    new_node->data = value;
    new_node->prev = NULL;
    new_node->next = *head;

    if (*head != NULL)
    {
        (*head)->prev = new_node;
    }
    *head = new_node;
}

void dinsert_end(Dnode **head, int value)
{
    Dnode *new_node = (Dnode *)malloc(sizeof(Dnode));
    Dnode *current = *head;
    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
    }
    else
    {
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
        new_node->prev = current;
    }
}

void dinsert_nth(Dnode **head, int value, int pos)
{
    Dnode *new_node = (Dnode *)malloc(sizeof(Dnode));
    Dnode *current = *head;
    int i;
    new_node->data = value;

    if (pos == 1)
    {
        new_node->prev = NULL;
        new_node->next = *head;
        if (*head != NULL)
        {
            (*head)->prev = new_node;
        }
        *head = new_node;
    }
    else
    {
        for (i = 0; i < pos - 2; i++)
        {
            current = current->next;
        }
        new_node->prev = current;
        new_node->next = current->next;
        if (current->next != NULL)
        {
            current->next->prev = new_node;
        }
        current->next = new_node;
    }
}

void ddelete_beg(Dnode **head)
{
    Dnode *temp = *head;
    if (*head == NULL)
    {
        printf("Null List! Deletion Not Possible");
    }
    else
    {
        if (temp->next != NULL)
        {
            temp->next->prev = NULL;
        }
        *head = temp->next;
        free(temp);
    }
}

void ddelete_end(Dnode **head)
{
    Dnode *current = *head;
    if (*head == NULL)
    {
        printf("Null List! Deletion Not Possible");
    }
    else
    {
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->prev->next = NULL;
        free(current);
    }
}

void ddelete_nth(Dnode **head, int pos)
{
    Dnode *current = *head;
    int i;

    if (*head == NULL)
    {
        printf("Null List! Deletion Not Possible");
    }
    else if (pos == 1)
    {
        if (current->next != NULL)
        {
            current->next->prev = NULL;
        }
        *head = current->next;
        free(current);
    }
    else
    {
        for (i = 0; i < pos - 1; i++)
        {
            current = current->next;
        }
        current->prev->next = current->next;
        if (current->next != NULL)
        {
            current->next->prev = current->prev;
        }
        free(current);
    }
}

void ddisplay(Dnode *head)
{
    Dnode *current = head;
    if (head == NULL)
    {
        printf("Null List");
    }
    else
    {
        while (current->next != NULL)
        {
            printf("%d\t", current->data);
            current = current->next;
        }
        printf("%d", current->data);
    }
}

void ddisplay_reverse(Dnode *head)
{
    Dnode *current = head;
    if (head == NULL)
    {
        printf("Null List");
    }
    else
    {
        while (current->next != NULL)
        {
            current = current->next;
        }
        while (current->prev != NULL)
        {
            printf("%d---", current->data);
            current = current->prev;
        }
        printf("%d", current->data);
    }
}

Dnode *largest(Dnode *head)
{
    Dnode *max_node = head;
    int max_value = 0;
    if (head == NULL)
    {
        return NULL;
    }
    else if (head->next == NULL)
    {
        return head;
    }
    else
    {
        max_value = head->data;
        head = head->next;
        while (head->next != NULL)
        {
            if (head->data > max_value)
            {
                max_value = head->data;
                max_node = head;
            }
            head = head->next;
        }
    }
    return max_node;
}

int main()
{
    Dnode *head = NULL;
    Dnode *largest_node;
    int value, position, choice;
    char more_data;

    printf("PROGRAM TO IMPLEMENT DOUBLE LINKED LIST");
    printf("\n=======================================");
    printf("\n1.Create/Appending The List");
    printf("\n2.Insert Node At Beginning");
    printf("\n3.Insert Node At End");
    printf("\n4.Insert Node At Nth Position");
    printf("\n5.Delete First Node");
    printf("\n6.Delete Last Node");
    printf("\n7.Delete Nth Node");
    printf("\n8.Display The List");
    printf("\n9.Reverse Display The List");
    printf("\n10.Exit\n");

    do
    {
        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            do
            {
                printf("Enter The Data : ");
                scanf("%d", &value);
                dinsert_end(&head, value);
                printf("Enter More Data (Y/N)? : ");
                fflush(stdin);
                more_data = getchar();
            } while (toupper(more_data) != 'N');
            break;
        case 2:
            printf("Enter The Data : ");
            scanf("%d", &value);
            dinsert_beg(&head, value);
            break;
        case 3:
            printf("Enter The Data : ");
            scanf("%d", &value);
            dinsert_end(&head, value);
            break;
        case 4:
            printf("\nEnter The Node Number Before Which New Node Will Be Inserted : ");
            scanf("%d", &position);
            printf("\nEnter The Data : ");
            scanf("%d", &value);
            dinsert_nth(&head, value, position);
            break;
        case 5:
            ddelete_beg(&head);
            break;
        case 6:
            ddelete_end(&head);
            break;
        case 7:
            printf("\nEnter The Node Number You Want To Delete : ");
            scanf("%d", &position);
            ddelete_nth(&head, position);
            break;
        case 8:
            ddisplay(head);
            break;
        case 9:
            ddisplay_reverse(head);
            break;
        case 10:
            printf("\nQuitting........");
            getch();
            exit(0);
        default:
            printf("Invalid Choice. Please Enter Correct Choice !");
            getch();
        }
    } while (1);
}
