#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* start = NULL;

/* ================= TRAVERSAL ================= */

void traverse() {
    Node* ptr = start;

    if (ptr == NULL) {
        cout << "List is Empty\n";
        return;
    }

    while (ptr != NULL) {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "NULL\n";
}

/* ================= INSERT AT FIRST ================= */

void insertAtFirst(int item) {
    Node* newnode = new Node;

    newnode->data = item;
    newnode->next = start;
    start = newnode;
}

/* ================= INSERT AT LAST ================= */

void insertAtLast(int item) {
    Node* newnode = new Node;
    newnode->data = item;
    newnode->next = NULL;

    if (start == NULL) {
        start = newnode;
        return;
    }

    Node* ptr = start;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = newnode;
}

/* ================= INSERT AFTER VALUE ================= */

void insertAfter(int val, int item) {
    Node* ptr = start;

    while (ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        cout << "Value not found\n";
        return;
    }

    Node* newnode = new Node;
    newnode->data = item;

    newnode->next = ptr->next;
    ptr->next = newnode;
}

/* ================= INSERT BEFORE VALUE ================= */

void insertBefore(int val, int item) {

    if (start == NULL) return;

    Node* newnode = new Node;
    newnode->data = item;

    if (start->data == val) {
        newnode->next = start;
        start = newnode;
        return;
    }

    Node* ptr = start;

    while (ptr->next != NULL && ptr->next->data != val) {
        ptr = ptr->next;
    }

    if (ptr->next == NULL) {
        cout << "Value not found\n";
        delete newnode;
        return;
    }

    newnode->next = ptr->next;
    ptr->next = newnode;
}

/* ================= DELETE FIRST ================= */

void deleteFirst() {

    if (start == NULL) {
        cout << "Underflow\n";
        return;
    }

    Node* ptr = start;
    start = ptr->next;
    delete ptr;
}

/* ================= DELETE LAST ================= */

void deleteLast() {

    if (start == NULL) {
        cout << "Underflow\n";
        return;
    }

    if (start->next == NULL) {
        delete start;
        start = NULL;
        return;
    }

    Node* ptr = start;

    while (ptr->next->next != NULL) {
        ptr = ptr->next;
    }

    delete ptr->next;
    ptr->next = NULL;
}

/* ================= DELETE AFTER VALUE ================= */

void deleteAfter(int val) {

    Node* ptr = start;

    while (ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }

    if (ptr == NULL || ptr->next == NULL) {
        cout << "Deletion not possible\n";
        return;
    }

    Node* temp = ptr->next;
    ptr->next = temp->next;
    delete temp;
}

/* ================= DELETE BY VALUE ================= */

void deleteByValue(int val) {

    if (start == NULL) {
        cout << "Underflow\n";
        return;
    }

    Node* ptr = start;
    Node* preptr = NULL;

    while (ptr != NULL && ptr->data != val) {
        preptr = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        cout << "Value not found\n";
        return;
    }

    if (preptr == NULL)
        start = ptr->next;
    else
        preptr->next = ptr->next;

    delete ptr;
}

/* ================= DELETE BEFORE VALUE ================= */

void deleteBefore(int val) {

    if (start == NULL) return;

    Node* preptr = NULL;
    Node* ptr = start;
    Node* nextptr = start->next;

    while (nextptr != NULL && nextptr->data != val) {
        preptr = ptr;
        ptr = nextptr;
        nextptr = nextptr->next;
    }

    if (nextptr == NULL) {
        cout << "Value not found\n";
        return;
    }

    if (preptr == NULL)
        start = nextptr;
    else
        preptr->next = nextptr;

    delete ptr;
}

/* ================= MENU DRIVER ================= */

int main() {

    int choice, item, val;

    while (true) {

        cout << "\n===== LINKED LIST MENU =====\n";
        cout << "1. Traverse\n";
        cout << "2. Insert at First\n";
        cout << "3. Insert at Last\n";
        cout << "4. Insert After Value\n";
        cout << "5. Insert Before Value\n";
        cout << "6. Delete First\n";
        cout << "7. Delete Last\n";
        cout << "8. Delete After Value\n";
        cout << "9. Delete By Value\n";
        cout << "10. Delete Before Value\n";
        cout << "11. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            traverse();
            break;

        case 2:
            cout << "Enter value: ";
            cin >> item;
            insertAtFirst(item);
            break;

        case 3:
            cout << "Enter value: ";
            cin >> item;
            insertAtLast(item);
            break;

        case 4:
            cout << "Insert after value: ";
            cin >> val;
            cout << "Enter new value: ";
            cin >> item;
            insertAfter(val, item);
            break;

        case 5:
            cout << "Insert before value: ";
            cin >> val;
            cout << "Enter new value: ";
            cin >> item;
            insertBefore(val, item);
            break;

        case 6:
            deleteFirst();
            break;

        case 7:
            deleteLast();
            break;

        case 8:
            cout << "Delete after value: ";
            cin >> val;
            deleteAfter(val);
            break;

        case 9:
            cout << "Delete value: ";
            cin >> val;
            deleteByValue(val);
            break;

        case 10:
            cout << "Delete before value: ";
            cin >> val;
            deleteBefore(val);
            break;

        case 11:
            exit(0);

        default:
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
