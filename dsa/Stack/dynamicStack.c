#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push()
{
    int item;
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Stack Overflow\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &item);

    newNode->data = item;
    newNode->next = top;
    top = newNode;
}

void pop()
{
    struct node *ptr;

    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    ptr = top;
    printf("Deleted element: %d\n", ptr->data);

    top = top->next;
    free(ptr);
}

void peek()
{
    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    printf("Top element: %d\n", top->data);
}

void display()
{
    struct node *ptr = top;

    if(top == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack elements:\n");

    while(ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }
}