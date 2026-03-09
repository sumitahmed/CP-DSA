#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

void push() {
    int item;

    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &item);

    top = top + 1;
    stack[top] = item;
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }

    printf("Popped element: %d\n", stack[top]);
    top = top - 1;
}

void peek() {
    if (top == -1) {
        printf("Stack is Empty\n");
        return;
    }

    printf("Top element: %d\n", stack[top]);
}

void display() {
    if (top == -1) {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack elements:\n");

    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {

    int choice;

    while (1) {

        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

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
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}