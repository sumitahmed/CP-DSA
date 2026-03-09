#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *front = NULL;
node *rear = NULL;

void enqueue(int item)
{
    node *newnode = new node;

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
    node *ptr;

    if (front == NULL)
    {
        cout << "Queue Underflow" << endl;
        return;
    }

    ptr = front;
    cout << "Deleted element: " << ptr->data << endl;

    front = front->next;

    if (front == NULL)
        rear = NULL;

    delete ptr;
}

void display()
{
    node *ptr;

    if (front == NULL)
    {
        cout << "Queue Underflow" << endl;
        return;
    }

    ptr = front;

    cout << "Queue elements: ";

    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }

    cout << endl;
}

int main()
{
    int choice, item;

    while (true)
    {
        cout << "\nLINKED QUEUE MENU\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter element: ";
                cin >> item;
                enqueue(item);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}