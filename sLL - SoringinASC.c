#include <stdio.h>
#include <stdlib.h>

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

// Function to sort the linked list in ascending order using Bubble Sort
void sortList(struct Node **head)
{
    if (*head == NULL)
        return;
        
    int swapped;
    struct Node *ptr1;
    struct Node *lptr = NULL;

    do
    {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                // Swap data
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1; // Last sorted node
    } while (swapped);
}

// Main function to demonstrate the program
int main()
{
    struct Node *head = NULL;
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

    sortList(&head);

    printf("Sorted List: ");
    displayList(head);

    return 0;
}
