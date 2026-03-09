#include <iostream>
using namespace std;

#define SIZE 5

int stack[SIZE];
int top = -1;

void push() {
    int item;

    if (top == SIZE - 1) {
        cout << "Stack Overflow\n";
        return;
    }

    cout << "Enter element: ";
    cin >> item;

    top++;
    stack[top] = item;
}

void pop() {

    if (top == -1) {
        cout << "Stack Underflow\n";
        return;
    }

    cout << "Popped element: " << stack[top] << endl;
    top--;
}

void peek() {

    if (top == -1) {
        cout << "Stack is Empty\n";
        return;
    }

    cout << "Top element: " << stack[top] << endl;
}

void display() {

    if (top == -1) {
        cout << "Stack is Empty\n";
        return;
    }

    cout << "Stack elements:\n";

    for (int i = top; i >= 0; i--) {
        cout << stack[i] << endl;
    }
}

int main() {

    int choice;

    while (true) {

        cout << "\n--- STACK MENU ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

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
                cout << "Invalid Choice\n";
        }
    }
}