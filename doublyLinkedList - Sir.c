// Doubly Linked List
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} Dnode;

void dinsert_beg(Dnode **p, int n)
{
    Dnode *q;
    q = (Dnode *)malloc(sizeof(Dnode));
    q->data = n;
    q->prev = NULL;
    q->next = *p;
    if (*p != NULL)
        (*p)->prev = q;
    *p = q;
}
void dinsert_end(Dnode **p, int n)
{
    Dnode *q, *r = *p;
    q = (Dnode *)malloc(sizeof(Dnode));
    q->data = n;
    q->next = NULL;
    if (*p == NULL)
    {
        q->prev = NULL;
        *p = q;
    }
    else
    {
        while (r->next != NULL)
        {
            r = r->next;
        }
        r->next = q;
        q->prev = r;
    }
}
void dinsert_nth(Dnode **p, int n, int pos)
{
    Dnode *q, *r = *p;
    int i;
    q = (Dnode *)malloc(sizeof(Dnode));
    q->data = n;
    if (pos == 1)
    {
        q->prev = NULL;
        q->next = *p;
        if (*p != NULL)
        {
            (*p)->prev = q;
        }
        *p = q;
    }
    else
    {
        for (i = 0; i < pos - 2; i++)
        {
            r = r->next;
        }
        q->prev = r;
        q->next = r->next;
        if (r->next != NULL)
            r->next->prev = q;
        r->next = q;
    }
}
void ddelete_beg(Dnode **p)
{
    Dnode *r = *p;
    if (*p == NULL)
        printf("Null List! Deletion Not Possible");
    else
    {
        if (r->next != NULL)
        {
            r->next->prev = NULL;
        }
        *p = r->next;
        free(r);
    }
}
void ddelete_end(Dnode **p)
{
    Dnode *r = *p;
    if (*p == NULL)
        printf("Null List! Deletion Not Possible");
    else
    {
        while (r->next != NULL)
        {
            r = r->next;
        }
        r->prev->next = NULL;
        free(r);
    }
}
void ddelete_nth(Dnode **p, int pos)
{
    Dnode *r = *p;
    int i;
    if (*p == NULL)
    {
        printf("Null List! Deletion Not Possible");
    }
    else if (pos == 1)
    {
        if (r->next != NULL)
            r->next->prev = NULL;
        *p = r->next;
        free(r);
    }
    else
    {
        for (i = 0; i < pos - 1; i++)
        {
            r = r->next;
        }
        r->prev->next = r->next;
        r->next->prev = r->prev;
        free(r);
    }
}
void ddisplay(Dnode *p)
{
    Dnode *r = p;
    if (p == NULL)
    {
        printf("Null List");
    }
    else
    {
        while (r->next != NULL)
        {
            printf("%d\t", r->data);
            r = r->next;
        }
        printf("%d", r->data);
    }
}
void ddisplay_reverse(Dnode *p)
{
    Dnode *r = p;
    if (p == NULL)
    {
        printf("Null List");
    }
    else
    {
        while (r->next != NULL)
        {
            r = r->next;
        }
        while (r->prev != NULL)
        {
            printf("%d---", r->data);
            r = r->prev;
        }
        printf("%d", r->data);
    }
}

Dnode *largest(Dnode *p)
{
    Dnode *t = p;
    int max = 0;
    if (p == NULL)
    {
        return (NULL);
    }
    else if (p->next == NULL)
    {
        return (p);
    }
    else
    {
        max = p->data;
        p = p->next;
        while (p->next != NULL)
        {
            if (p->data > max)
            {
                max = p->data;
                t = p;
                p = p->next;
            }
            else
            {
                p = p->next;
            }
        }
    }
    return (t);
}
int main()
{
    Dnode *head = NULL;
    Dnode *large;
    int num, loc, choice, l;
    char opt;
    printf("PROGRAM TO IMPLEMENT DOUBLE LINKED LIST");
    printf("\n=======================================");
    printf("\n1.Create/Appending The List");
    printf("\n2.Insert Node At Beginning");
    printf("\n3.Insert Node At End");
    printf("\n4.Insert Node At Nth Position");
    printf("\n5.Delete First Node");
    printf("\n6.Delete Last Node");
    printf("\n7.Delete Nth Node");
    printf("\n8.Display The List");
    printf("\n9.Reverse Display The List");
    printf("\n10.Exit\n");
    do
    {
        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            do
            {
                printf("Enter The Data : ");
                scanf("%d", &num);
                dinsert_end(&head, num);
                printf("Enter More Data (Y/N)? : ");
                fflush(stdin);
                opt = getchar();
            } while (toupper(opt) != 'N');
            break;
        case 2:
            printf("Enter The Data : ");
            scanf("%d", &num);
            dinsert_beg(&head, num);
            break;
        case 3:
            printf("Enter The Data : ");
            scanf("%d", &num);
            dinsert_end(&head, num);
            break;
        case 4:
            printf("\nEnter The Node Number Before Which New Node Will Be Inserted : ");
            scanf("%d", &loc);
            printf("\nEnter The Data : ");
            scanf("%d", &num);
            dinsert_nth(&head, num, loc);
            break;
        case 5:
            ddelete_beg(&head);
            break;
        case 6:
            ddelete_end(&head);
            break;
        case 7:
            printf("\nEnter The Node Number You Want To Delete : ");
            scanf("%d", &loc);
            ddelete_nth(&head, loc);
            break;
        case 8:
            ddisplay(head);
            break;
        case 9:
            ddisplay_reverse(head);
            break;
        case 10:
            printf("\nQuiting........");
            getch();
            exit(0);
        default:
            printf("Invalid Choice. Please Enter Correct Choice !");
            getch();
        }
    } while (1);
}