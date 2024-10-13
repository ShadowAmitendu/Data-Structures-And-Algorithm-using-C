#include <stdio.h>
#include <stdlib.h>

// Define a structure for the Singly Linked List node
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

// Function to insert a node at the end of the list
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at a specific position
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

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position exceeds the length of the list. Node will not be inserted.\n");
        free(newNode);
        return;
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
    *head = (*head)->next;
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
    if (temp->next == NULL)
    {
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
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

    for (int i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position exceeds the length of the list. Node will not be deleted.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to display the list
void displayList(struct Node *head)
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Menu-driven program for Singly Linked List
int main()
{
    struct Node *head = NULL;
    int choice, data, pos;

    while (1)
    {
        printf("PROGRAM TO IMPLEMENT SINGLY LINKED LIST\n");
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
            displayList(head);
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
