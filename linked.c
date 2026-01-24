#include <stdio.h>
#include <stdlib.h>

struct node
{
    int element;
    struct node *next;
};

typedef struct node* list;

list head, ptr, t;

void insert(int pos, int v);
void del(int v);
list find(int v);
void print();

int main()
{
    int val, pos, choice = 0;

    head = (list)malloc(sizeof(struct node));
    head->next = NULL;

    while (choice != 5)
    {
        printf("\nLinked List Implementation of List ADT");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Find");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter position and element: ");
                scanf("%d %d", &pos, &val);
                insert(pos, val);
                break;

            case 2:
                printf("Enter element to delete: ");
                scanf("%d", &val);
                del(val);
                break;

            case 3:
                printf("Enter element to find: ");
                scanf("%d", &val);
                t = find(val);
                if (t != NULL)
                    printf("Element found: %d", t->element);
                else
                    printf("Element not found");
                break;

            case 4:
                print();
                break;

            case 5:
                printf("Exiting program...");
                break;

            default:
                printf("Invalid choice");
        }
    }
    return 0;
}

void insert(int pos, int v)
{
    list newnode;
    int i;

    ptr = head;

    newnode = (list)malloc(sizeof(struct node));
    newnode->element = v;
    newnode->next = NULL;

    for (i = 1; i < pos && ptr->next != NULL; i++)
        ptr = ptr->next;

    newnode->next = ptr->next;
    ptr->next = newnode;
}

void del(int v)
{
    list temp;
    ptr = head;

    while (ptr->next != NULL && ptr->next->element != v)
        ptr = ptr->next;

    if (ptr->next == NULL)
    {
        printf("Element not found");
        return;
    }

    temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
}

list find(int v)
{
    ptr = head->next;

    while (ptr != NULL)
    {
        if (ptr->element == v)
            return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

void print()
{
    ptr = head->next;

    if (ptr == NULL)
    {
        printf("List is empty");
        return;
    }

    printf("Elements: ");
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->element);
        ptr = ptr->next;
    }
    printf("NULL");
}