#include <stdio.h>   /* Has the Standard Input and Output Functions */
#include <stdlib.h>  /* Has the Malloc Function */

/* Node Structure */
struct Node {
    int data;
    struct Node *link;
};

/* Listing the Functions */
/* For User */
void menu();
int choice();

/* Essential and For Efficient use */
int isNull(struct Node *head);
int countNodes(struct Node *head);

/* Display Function */
void display(struct Node *head);

/* Insert Functions */
void insertEnd(struct Node **head, int data);
void insertStart(struct Node **head, int data);
void insertNth(struct Node **head, int data, int place);

/* Delete Functions */
void deleteEnd(struct Node *head);
struct Node *deleteStart(struct Node *head);
void deleteNth(struct Node **head, int place);

/* Main Entry Point of the Program */
int main() {
    struct Node *head = NULL;

    // Insert elements at the end
    printf("Inserting at the end:\n");
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    display(head);
    printf("\n");

    // Insert element at the start
    printf("Inserting at the start:\n");
    insertStart(&head, 5);
    display(head);
    printf("\n");

    // Insert element at position 3
    printf("Inserting at position 3:\n");
    insertNth(&head, 25, 3);
    display(head);
    printf("\n");

    // Display total number of nodes
    printf("Total number of nodes: %d\n", countNodes(head));

    // Delete element from the end
    printf("Deleting from the end:\n");
    deleteEnd(head);
    display(head);
    printf("\n");

    // Delete element from the start
    printf("Deleting from the start:\n");
    head = deleteStart(head);
    display(head);
    printf("\n");

    // Delete element at position 3
    printf("Deleting from position 3:\n");
    deleteNth(&head, 3);
    display(head);
    printf("\n");

    // Display total number of nodes again
    printf("Total number of nodes after deletion: %d\n", countNodes(head));

    return 0;
}

/* Check if the list is empty */
int isNull(struct Node *head) {
    return (head == NULL);
}

/* Count the number of nodes */
int countNodes(struct Node *head) {
    int count = 0;
    struct Node *temp = head;

    if (isNull(head)) {
        printf("LIST IS EMPTY\n");
    } else {
        while (temp != NULL) {
            count++;
            temp = temp->link;
        }
    }
    return count;
}

/* Display the linked list */
void display(struct Node *head) {
    struct Node *temp = head;

    if (isNull(head)) {
        printf("LIST IS EMPTY\n");
    } else {
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->link;
        }
        printf("NULL!\n");
    }
}

/* Insert an element at the end of the list */
void insertEnd(struct Node **head, int data) {
    struct Node *temp = *head;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->link = NULL;

    if (isNull(*head)) {
        *head = newNode;
    } else {
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

/* Insert an element at the start of the list */
void insertStart(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->link = *head;

    *head = newNode;
}

/* Insert an element at the Nth position in the list */
void insertNth(struct Node **head, int data, int place) {
    if (isNull(*head)) {
        printf("LIST IS EMPTY\n");
        return;
    }

    struct Node *temp = *head;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->link = NULL;

    if (place == 1) {
        insertStart(head, data);
        return;
    }

    while (--place > 1 && temp->link != NULL) {
        temp = temp->link;
    }
    
    newNode->link = temp->link;
    temp->link = newNode;
}

/* Delete an element from the end of the list */
void deleteEnd(struct Node *head) {
    if (isNull(head)) {
        printf("LIST IS EMPTY\n");
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    if (temp->link == NULL) {
        free(temp);
        head = NULL;
        return;
    }

    while (temp->link != NULL) {
        prev = temp;
        temp = temp->link;
    }

    free(temp);
    prev->link = NULL;
}

/* Delete the first element from the list */
struct Node *deleteStart(struct Node *head) {
    if (isNull(head)) {
        printf("LIST IS EMPTY\n");
        return NULL;
    }

    struct Node *temp = head;
    head = head->link;
    free(temp);
    return head;
}

/* Delete the Nth element from the list */
void deleteNth(struct Node **head, int place) {
    if (isNull(*head)) {
        printf("LIST IS EMPTY\n");
        return;
    }

    struct Node *temp = *head;

    if (place == 1) {
        *head = temp->link;
        free(temp);
        return;
    }

    struct Node *prev = NULL;
    while (--place && temp != NULL) {
        prev = temp;
        temp = temp->link;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    prev->link = temp->link;
    free(temp);
}
