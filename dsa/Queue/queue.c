#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue()
{
    int item;

    if (rear == SIZE - 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &item);

    if (front == -1 || front > rear)
        front = rear = 0;
    else
        rear = rear + 1;

    queue[rear] = item;
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);
    front = front + 1;
}

void peek()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("Front element: %d\n", queue[front]);
}

void display()
{
    int i;

    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("Queue elements: ");

    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    printf("\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\nQUEUE MENU\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}