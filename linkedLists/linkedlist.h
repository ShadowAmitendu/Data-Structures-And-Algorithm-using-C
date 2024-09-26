#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Define the structure for a Node with a 'link' pointer to the next node
struct Node
{
    int data;
    struct Node *link; // This is the pointer to the next node
};

/* Essential and For Efficient use */
#ifndef IS_NULL
#define IS_NULL
int isNull(struct Node *head);
#endif

#ifndef COUNT_NODES
#define COUNT_NODES
int countNodes(struct Node *head);
#endif

/* Display Function */
#ifndef DISPLAY
#define DISPLAY
void display(struct Node *head);
#endif

/* Insert Functions */
#ifndef INSERT_END
#define INSERT_END
void insertEnd(struct Node **head, int data);
#endif

#ifndef INSERT_START
#define INSERT_START
void insertStart(struct Node **head, int data);
#endif

#ifndef INSERT_NTH
#define INSERT_NTH
void insertNth(struct Node **head, int data, int place);
#endif

/* Delete Functions */
#ifndef DELETE_END
#define DELETE_END
void deleteEnd(struct Node **head, int data);
#endif

#ifndef DELETE_START
#define DELETE_START
void deleteStart(struct Node **head, int data);
#endif

#ifndef DELETE_NTH
#define DELETE_NTH
void deleteNth(struct Node **head, int data, int place);
#endif

#endif /* LINKED_LIST_H */
