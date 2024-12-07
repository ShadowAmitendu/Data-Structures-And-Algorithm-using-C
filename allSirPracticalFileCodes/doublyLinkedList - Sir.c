#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} DNode;

// Function to insert a node at a specific position
void insert_at_position(DNode **head, int value, int position)
{
    DNode *new_node = (DNode *)malloc(sizeof(DNode));
    new_node->data = value;

    if (position == 1)
    { // Insert at the beginning if position is 1
        new_node->prev = NULL;
        new_node->next = *head;
        if (*head != NULL)
            (*head)->prev = new_node;
        *head = new_node;
    }
    else
    {
        DNode *temp = *head;
        for (int i = 1; i < position - 1 && temp != NULL; i++) // Traverse to (position-1)
            temp = temp->next;

        if (temp == NULL)
        {
            printf("Position out of range.\n");
            free(new_node);
            return;
        }

        new_node->prev = temp;
        new_node->next = temp->next;

        if (temp->next != NULL)
            temp->next->prev = new_node;

        temp->next = new_node;
    }
}

// Function to delete a node at a specific position
void delete_at_position(DNode **head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty! Deletion not possible.\n");
        return;
    }

    DNode *temp = *head;

    if (position == 1)
    { // Delete the head node if position is 1
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(temp);
    }
    else
    {
        for (int i = 1; i < position && temp != NULL; i++)
            temp = temp->next;

        if (temp == NULL)
        {
            printf("Position out of range.\n");
            return;
        }

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        if (temp->prev != NULL)
            temp->prev->next = temp->next;

        free(temp);
    }
}

// Function to display the list from head to end
void display_list(DNode *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    DNode *temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    DNode *head = NULL;
    int value, position, choice;

    printf("PROGRAM TO IMPLEMENT DOUBLY LINKED LIST\n");
    printf("=======================================\n");
    printf("1. Insert at Nth Position\n");
    printf("2. Delete Nth Node\n");
    printf("3. Display List\n");
    printf("4. Exit\n");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the position to insert: ");
            scanf("%d", &position);
            printf("Enter the data: ");
            scanf("%d", &value);
            insert_at_position(&head, value, position);
            break;
        case 2:
            printf("Enter the position to delete: ");
            scanf("%d", &position);
            delete_at_position(&head, position);
            break;
        case 3:
            display_list(head);
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (1);

    return 0;
}
