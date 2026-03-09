#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int item)
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = item;
    newnode->next = NULL;

    if (front == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue()
{
    struct node *ptr;

    if (front == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }

    ptr = front;
    printf("Deleted element: %d\n", ptr->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(ptr);
}

void display()
{
    struct node *ptr;

    if (front == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }

    ptr = front;

    printf("Queue elements: ");

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}

int main()
{
    int choice, item;

    while (1)
    {
        printf("\nLINKED QUEUE MENU\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &item);
                enqueue(item);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}