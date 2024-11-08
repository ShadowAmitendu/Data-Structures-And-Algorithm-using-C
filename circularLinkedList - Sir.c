#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} CNode;

// Function to insert a node at the Nth position in the Circular Linked List
void insert_at_position(CNode **head, int value, int position)
{
    CNode *new_node = (CNode *)malloc(sizeof(CNode));
    new_node->data = value;

    if (*head == NULL)
    { // If list is empty, new node becomes the only node
        new_node->next = new_node;
        *head = new_node;
        return;
    }

    if (position == 1)
    { // Insert at the beginning
        CNode *temp = *head;
        while (temp->next != *head) // Traverse to the last node
            temp = temp->next;

        new_node->next = *head;
        temp->next = new_node;
        *head = new_node;
    }
    else
    { // Insert at the specified position
        CNode *temp = *head;
        for (int i = 1; i < position - 1 && temp->next != *head; i++) // Traverse to (position-1)
            temp = temp->next;

        if (temp->next == *head && position > 1)
        {
            printf("Position out of range.\n");
            free(new_node);
            return;
        }

        new_node->next = temp->next;
        temp->next = new_node;
    }
}

// Function to delete a node at the Nth position in the Circular Linked List
void delete_at_position(CNode **head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty! Deletion not possible.\n");
        return;
    }

    CNode *temp = *head;

    if (position == 1)
    { // Delete the head node
        CNode *last = *head;
        while (last->next != *head) // Traverse to the last node
            last = last->next;

        if (*head == (*head)->next)
        { // Only one node in the list
            free(*head);
            *head = NULL;
        }
        else
        {
            last->next = (*head)->next;
            free(*head);
            *head = last->next;
        }
    }
    else
    {                                                         // Delete at the specified position
        for (int i = 1; i < position - 1 && temp->next != *head; i++) // Traverse to (position-1)
            temp = temp->next;

        if (temp->next == *head)
        {
            printf("Position out of range.\n");
            return;
        }

        CNode *to_delete = temp->next;
        temp->next = to_delete->next;
        free(to_delete);
    }
}

// Function to display the Circular Linked List
void display_list(CNode *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    CNode *temp = head;
    do
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main()
{
    CNode *head = NULL;
    int value, position, choice;

    printf("PROGRAM TO IMPLEMENT CIRCULAR LINKED LIST\n");
    printf("=========================================\n");
    printf("1. Insert at Nth Position\n");
    printf("2. Delete Nth Node\n");
    printf("3. Display List\n");
    printf("4. Exit\n");

    do
    {
        printf("\nEnter your choice: ");
        scanf_s("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the position to insert: ");
            scanf_s("%d", &position);
            printf("Enter the data: ");
            scanf_s("%d", &value);
            insert_at_position(&head, value, position);
            break;
        case 2:
            printf("Enter the position to delete: ");
            scanf_s("%d", &position);
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
