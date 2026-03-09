#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue()
{
    int item;

    if (rear == SIZE - 1)
    {
        cout << "Queue Overflow" << endl;
        return;
    }

    cout << "Enter element: ";
    cin >> item;

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
        cout << "Queue Underflow" << endl;
        return;
    }

    cout << "Deleted element: " << queue[front] << endl;
    front = front + 1;
}

void peek()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue Underflow" << endl;
        return;
    }

    cout << "Front element: " << queue[front] << endl;
}

void display()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue Underflow" << endl;
        return;
    }

    cout << "Queue elements: ";

    for (int i = front; i <= rear; i++)
        cout << queue[i] << " ";

    cout << endl;
}

int main()
{
    int choice;

    while (true)
    {
        cout << "\nQUEUE MENU\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

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
            cout << "Invalid choice\n";
        }
    }
}