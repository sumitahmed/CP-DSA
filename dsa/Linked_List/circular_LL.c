#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

void traverse();
void insert_begin(int);
void insert_end(int);
void insert_after(int,int);
void insert_before(int,int);
void delete_begin();
void delete_end();
void delete_after(int);
void delete_value(int);
void delete_before(int);

int main() {

    int choice, item, key;

    while(1) {

        printf("\n\n--- CIRCULAR LINKED LIST MENU ---\n");
        printf("1. Traverse\n");
        printf("2. Insert Beginning\n");
        printf("3. Insert End\n");
        printf("4. Insert After\n");
        printf("5. Insert Before\n");
        printf("6. Delete Beginning\n");
        printf("7. Delete End\n");
        printf("8. Delete After\n");
        printf("9. Delete By Value\n");
        printf("10. Delete Before\n");
        printf("11. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice) {

            case 1:
                traverse();
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d",&item);
                insert_begin(item);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d",&item);
                insert_end(item);
                break;

            case 4:
                printf("Enter key: ");
                scanf("%d",&key);
                printf("Enter value: ");
                scanf("%d",&item);
                insert_after(key,item);
                break;

            case 5:
                printf("Enter key: ");
                scanf("%d",&key);
                printf("Enter value: ");
                scanf("%d",&item);
                insert_before(key,item);
                break;

            case 6:
                delete_begin();
                break;

            case 7:
                delete_end();
                break;

            case 8:
                printf("Enter key: ");
                scanf("%d",&key);
                delete_after(key);
                break;

            case 9:
                printf("Enter value to delete: ");
                scanf("%d",&key);
                delete_value(key);
                break;

            case 10:
                printf("Enter key: ");
                scanf("%d",&key);
                delete_before(key);
                break;

            case 11:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}

void traverse() {

    struct node *ptr;

    if(start == NULL) {
        printf("List empty\n");
        return;
    }

    ptr = start;

    do {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    } while(ptr != start);
}

void insert_begin(int item) {

    struct node *ptr,*newnode;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;

    if(start == NULL) {
        newnode->next = newnode;
        start = newnode;
        return;
    }

    ptr = start;

    while(ptr->next != start)
        ptr = ptr->next;

    newnode->next = start;
    ptr->next = newnode;
    start = newnode;
}

void insert_end(int item) {

    struct node *ptr,*newnode;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;

    if(start == NULL) {
        newnode->next = newnode;
        start = newnode;
        return;
    }

    ptr = start;

    while(ptr->next != start)
        ptr = ptr->next;

    ptr->next = newnode;
    newnode->next = start;
}

void insert_after(int key,int item) {

    struct node *ptr,*newnode;

    if(start == NULL) {
        printf("List empty\n");
        return;
    }

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;

    ptr = start;

    do {

        if(ptr->data == key)
            break;

        ptr = ptr->next;

    } while(ptr != start);

    if(ptr->data != key) {
        printf("Key not found\n");
        return;
    }

    newnode->next = ptr->next;
    ptr->next = newnode;
}

void insert_before(int key,int item) {

    struct node *ptr,*preptr,*newnode,*last;

    if(start == NULL) {
        printf("List empty\n");
        return;
    }

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;

    ptr = start;
    preptr = NULL;

    do {

        if(ptr->data == key)
            break;

        preptr = ptr;
        ptr = ptr->next;

    } while(ptr != start);

    if(ptr->data != key) {
        printf("Key not found\n");
        return;
    }

    if(ptr == start) {

        last = start;

        while(last->next != start)
            last = last->next;

        newnode->next = start;
        last->next = newnode;
        start = newnode;
    }
    else {

        newnode->next = ptr;
        preptr->next = newnode;
    }
}

void delete_begin() {

    struct node *ptr,*temp;

    if(start == NULL) {
        printf("Underflow\n");
        return;
    }

    ptr = start;

    while(ptr->next != start)
        ptr = ptr->next;

    temp = start;

    if(start->next == start) {
        start = NULL;
    }
    else {
        ptr->next = start->next;
        start = start->next;
    }

    free(temp);
}

void delete_end() {

    struct node *ptr,*preptr;

    if(start == NULL) {
        printf("Underflow\n");
        return;
    }

    ptr = start;

    if(start->next == start) {
        free(start);
        start = NULL;
        return;
    }

    while(ptr->next != start) {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = start;
    free(ptr);
}

void delete_after(int key) {

    struct node *ptr,*temp;

    if(start == NULL) {
        printf("Underflow\n");
        return;
    }

    ptr = start;

    do {

        if(ptr->data == key)
            break;

        ptr = ptr->next;

    } while(ptr != start);

    if(ptr->data != key) {
        printf("Key not found\n");
        return;
    }

    temp = ptr->next;

    if(temp == start)
        start = start->next;

    ptr->next = temp->next;

    free(temp);
}

void delete_value(int key) {

    struct node *ptr,*preptr,*last;

    if(start == NULL) {
        printf("Underflow\n");
        return;
    }

    ptr = start;
    preptr = NULL;

    do {

        if(ptr->data == key)
            break;

        preptr = ptr;
        ptr = ptr->next;

    } while(ptr != start);

    if(ptr->data != key) {
        printf("Value not found\n");
        return;
    }

    if(ptr == start) {

        last = start;

        while(last->next != start)
            last = last->next;

        last->next = start->next;
        start = start->next;
    }
    else {

        preptr->next = ptr->next;
    }

    free(ptr);
}

void delete_before(int key) {

    struct node *ptr,*preptr,*temp;

    if(start == NULL) {
        printf("Underflow\n");
        return;
    }

    ptr = start;
    preptr = NULL;

    do {

        if(ptr->data == key)
            break;

        preptr = ptr;
        ptr = ptr->next;

    } while(ptr != start);

    if(ptr->data != key) {
        printf("Value not found\n");
        return;
    }

    temp = start;

    while(temp->next != preptr)
        temp = temp->next;

    temp->next = ptr;

    free(preptr);
}