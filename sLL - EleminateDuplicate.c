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

// Function to eliminate duplicate elements
void eliminateDuplicates(struct Node *head)
{
    struct Node *current = head;
    struct Node *index = NULL;
    struct Node *temp = NULL;

    while (current != NULL && current->next != NULL)
    {
        temp = current; // temp is used to track the previous node
        index = current->next;
        while (index != NULL)
        {
            if (current->data == index->data)
            {
                temp->next = index->next; // Skip the duplicate node
                free(index);              // Free the memory of the duplicate node
                index = temp->next;
            }
            else
            {
                temp = index;
                index = index->next;
            }
        }
        current = current->next;
    }
}

// Main function to demonstrate the program
int main()
{
    struct Node *head = NULL;
    int n, data;

    printf("Enter the number of elements to insert in the list: ");
    scanf_s("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf_s("%d", &data);
        insertAtEnd(&head, data);
    }

    printf("Original List: ");
    displayList(head);

    eliminateDuplicates(head);

    printf("List after eliminating duplicates: ");
    displayList(head);

    return 0;
}
