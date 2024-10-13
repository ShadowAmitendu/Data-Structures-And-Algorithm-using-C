#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

typedef struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} DNode;

void insert_at_beginning(DNode **head, int value)
{
    DNode *new_node = (DNode *)malloc(sizeof(DNode));
    new_node->data = value;
    new_node->prev = NULL;
    new_node->next = *head;

    if (*head != NULL)
        (*head)->prev = new_node;

    *head = new_node;
}

void insert_at_end(DNode **head, int value)
{
    DNode *new_node = (DNode *)malloc(sizeof(DNode));
    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
    }
    else
    {
        DNode *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = new_node;
        new_node->prev = temp;
    }
}

void insert_at_position(DNode **head, int value, int position)
{
    DNode *new_node = (DNode *)malloc(sizeof(DNode));
    new_node->data = value;

    if (position == 1)
    {
        new_node->prev = NULL;
        new_node->next = *head;
        if (*head != NULL)
            (*head)->prev = new_node;
        *head = new_node;
    }
    else
    {
        DNode *temp = *head;
        for (int i = 1; i < position - 1 && temp != NULL; i++)
            temp = temp->next;

        new_node->prev = temp;
        new_node->next = temp->next;

        if (temp->next != NULL)
            temp->next->prev = new_node;

        temp->next = new_node;
    }
}

void delete_first(DNode **head)
{
    if (*head == NULL)
    {
        printf("List is empty! Deletion not possible.\n");
        return;
    }

    DNode *temp = *head;
    *head = temp->next;

    if (*head != NULL)
        (*head)->prev = NULL;

    free(temp);
}

void delete_last(DNode **head)
{
    if (*head == NULL)
    {
        printf("List is empty! Deletion not possible.\n");
        return;
    }

    DNode *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        *head = NULL;

    free(temp);
}

void delete_at_position(DNode **head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty! Deletion not possible.\n");
        return;
    }

    DNode *temp = *head;

    if (position == 1)
    {
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

void display_reverse_list(DNode *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    DNode *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

DNode *find_largest(DNode *head)
{
    if (head == NULL)
        return NULL;

    DNode *max_node = head;
    int max_value = head->data;

    DNode *temp = head->next;
    while (temp != NULL)
    {
        if (temp->data > max_value)
        {
            max_value = temp->data;
            max_node = temp;
        }
        temp = temp->next;
    }
    return max_node;
}

int main()
{
    DNode *head = NULL;
    int value, position, choice;
    char continue_choice;

    printf("PROGRAM TO IMPLEMENT DOUBLY LINKED LIST\n");
    printf("=======================================\n");
    printf("1. Append Data to the List\n");
    printf("2. Insert at Beginning\n");
    printf("3. Insert at End\n");
    printf("4. Insert at Nth Position\n");
    printf("5. Delete First Node\n");
    printf("6. Delete Last Node\n");
    printf("7. Delete Nth Node\n");
    printf("8. Display List\n");
    printf("9. Display List in Reverse\n");
    printf("10. Exit\n");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            do
            {
                printf("Enter the data: ");
                scanf("%d", &value);
                insert_at_end(&head, value);
                printf("Enter more data (Y/N)? ");
                fflush(stdin);
                continue_choice = getchar();
            } while (toupper(continue_choice) != 'N');
            break;
        case 2:
            printf("Enter the data: ");
            scanf("%d", &value);
            insert_at_beginning(&head, value);
            break;
        case 3:
            printf("Enter the data: ");
            scanf("%d", &value);
            insert_at_end(&head, value);
            break;
        case 4:
            printf("Enter the position to insert: ");
            scanf("%d", &position);
            printf("Enter the data: ");
            scanf("%d", &value);
            insert_at_position(&head, value, position);
            break;
        case 5:
            delete_first(&head);
            break;
        case 6:
            delete_last(&head);
            break;
        case 7:
            printf("Enter the position to delete: ");
            scanf("%d", &position);
            delete_at_position(&head, position);
            break;
        case 8:
            display_list(head);
            break;
        case 9:
            display_reverse_list(head);
            break;
        case 10:
            printf("Exiting...\n");
            getch();
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
            getch();
        }
    } while (1);

    return 0;
}
