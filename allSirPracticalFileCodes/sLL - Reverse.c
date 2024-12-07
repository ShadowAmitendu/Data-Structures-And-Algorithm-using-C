#include <stdio.h>
#include <stdlib.h>

// Define a structure for the Singly Linked List node
struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;


// Function to create a new node
node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(node **head, int data)
{
    node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the list
void displayList(node *head)
{
    node *temp = head;
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

// Function to reverse the linked list
void reverseList(node **head)
{
    node *prev = NULL;
    node *current = *head;
    node *next = NULL;

    while (current != NULL)
    {
        next = current->next; // Store next node
        current->next = prev; // Reverse current node's pointer
        prev = current;       // Move pointers one position forward
        current = next;
    }
    *head = prev; // Update head to the new first node
}

// Main function to demonstrate the program
int main()
{
    node *head = NULL;
    int n, data;

    printf("Enter the number of elements to insert in the list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    printf("Original List: ");
    displayList(head);

    reverseList(&head);

    printf("Reversed List: ");
    displayList(head);

    return 0;
}
