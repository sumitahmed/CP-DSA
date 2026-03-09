#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *top = NULL;

void push()
{
    int item;
    cout << "Enter element: ";
    cin >> item;

    node *newNode = new node();

    newNode->data = item;
    newNode->next = top;
    top = newNode;
}

void pop()
{
    if(top == NULL)
    {
        cout << "Stack Underflow\n";
        return;
    }

    node *ptr = top;
    cout << "Deleted element: " << ptr->data << endl;

    top = top->next;
    delete ptr;
}

void peek()
{
    if(top == NULL)
    {
        cout << "Stack Underflow\n";
        return;
    }

    cout << "Top element: " << top->data << endl;
}

void display()
{
    node *ptr = top;

    if(top == NULL)
    {
        cout << "Stack is Empty\n";
        return;
    }

    cout << "Stack elements:\n";

    while(ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

int main()
{
    int choice;

    while(true)
    {
        cout << "\n--- STACK MENU ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

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
                return 0;

            default:
                cout << "Invalid Choice\n";
        }
    }
}