#include <stdio.h>
#include <stdlib.h>

// Define a structure for the Circular Linked List node
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the beginning of the list
void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *temp = *head;

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = *head; // Point to itself
    }
    else
    {
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
}

// Function to insert at the end of the list
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *temp = *head;

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = *head;
    }
    else
    {
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to insert at a specific position
void insertAtPosition(struct Node **head, int data, int pos)
{
    if (pos < 1)
    {
        printf("Position should be >= 1\n");
        return;
    }
    if (pos == 1)
    {
        insertAtBeginning(head, data);
        return;
    }

    struct Node *newNode = createNode(data);
    struct Node *temp = *head;

    for (int i = 1; i < pos - 1 && temp->next != *head; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete the first node
void deleteFromBeginning(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = *head;
    struct Node *last = *head;

    if (temp->next == *head)
    {
        free(temp);
        *head = NULL;
        return;
    }

    while (last->next != *head)
    {
        last = last->next;
    }

    *head = temp->next;
    last->next = *head;
    free(temp);
}

// Function to delete the last node
void deleteFromEnd(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = *head;
    struct Node *prev = NULL;

    if (temp->next == *head)
    {
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next != *head)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = *head;
    free(temp);
}

// Function to delete a node at a specific position
void deleteAtPosition(struct Node **head, int pos)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (pos == 1)
    {
        deleteFromBeginning(head);
        return;
    }

    struct Node *temp = *head;
    struct Node *prev = NULL;

    for (int i = 1; i < pos && temp->next != *head; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp->next == *head && prev == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to display the Circular Linked List
void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(HEAD)\n");
}

// Menu-driven program for Circular Linked List
int main()
{
    struct Node *head = NULL;
    int choice, data, pos;

    while (1)
    {
        printf("PROGRAM TO IMPLEMENT CIRCULAR LINKED LIST\n");
        printf("=======================================\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Nth Position\n");
        printf("4. Delete First Node\n");
        printf("5. Delete Last Node\n");
        printf("6. Delete Nth Node\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to insert at the beginning: ");
            scanf("%d", &data);
            insertAtBeginning(&head, data);
            break;
        case 2:
            printf("Enter the data to insert at the end: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;
        case 3:
            printf("Enter the position to insert: ");
            scanf("%d", &pos);
            printf("Enter the data to insert at position %d: ", pos);
            scanf("%d", &data);
            insertAtPosition(&head, data, pos);
            break;
        case 4:
            deleteFromBeginning(&head);
            break;
        case 5:
            deleteFromEnd(&head);
            break;
        case 6:
            printf("Enter the position to delete: ");
            scanf("%d", &pos);
            deleteAtPosition(&head, pos);
            break;
        case 7:
            display(head);
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
        printf("\n");
    }

    return 0;
}
