#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *start = NULL;

void traverse() {
    struct node *ptr = start;

    if(start == NULL) {
        printf("List is empty\n");
        return;
    }

    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void insert_begin(int val) {
    struct node *newnode = malloc(sizeof(struct node));

    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = start;

    if(start != NULL)
        start->prev = newnode;

    start = newnode;
}

void insert_end(int val) {
    struct node *newnode = malloc(sizeof(struct node));
    struct node *ptr = start;

    newnode->data = val;
    newnode->next = NULL;

    if(start == NULL) {
        newnode->prev = NULL;
        start = newnode;
        return;
    }

    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = newnode;
    newnode->prev = ptr;
}

void insert_after(int num, int val) {
    struct node *ptr = start;
    struct node *newnode = malloc(sizeof(struct node));

    while(ptr != NULL && ptr->data != num)
        ptr = ptr->next;

    if(ptr == NULL) {
        printf("Value not found\n");
        return;
    }

    newnode->data = val;
    newnode->next = ptr->next;
    newnode->prev = ptr;

    if(ptr->next != NULL)
        ptr->next->prev = newnode;

    ptr->next = newnode;
}

void insert_before(int num, int val) {
    struct node *ptr = start;
    struct node *newnode = malloc(sizeof(struct node));

    while(ptr != NULL && ptr->data != num)
        ptr = ptr->next;

    if(ptr == NULL) {
        printf("Value not found\n");
        return;
    }

    newnode->data = val;
    newnode->prev = ptr->prev;
    newnode->next = ptr;

    if(ptr->prev != NULL)
        ptr->prev->next = newnode;
    else
        start = newnode;

    ptr->prev = newnode;
}

void delete_begin() {
    struct node *ptr;

    if(start == NULL) return;

    ptr = start;
    start = start->next;

    if(start != NULL)
        start->prev = NULL;

    free(ptr);
}

void delete_end() {
    struct node *ptr = start;

    if(start == NULL) return;

    if(start->next == NULL) {
        free(start);
        start = NULL;
        return;
    }

    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->prev->next = NULL;
    free(ptr);
}

void delete_after(int num) {
    struct node *ptr = start;
    struct node *temp;

    while(ptr != NULL && ptr->data != num)
        ptr = ptr->next;

    if(ptr == NULL || ptr->next == NULL) return;

    temp = ptr->next;

    ptr->next = temp->next;

    if(temp->next != NULL)
        temp->next->prev = ptr;

    free(temp);
}

void delete_before(int num) {
    struct node *ptr = start;
    struct node *temp;

    while(ptr != NULL && ptr->data != num)
        ptr = ptr->next;

    if(ptr == NULL || ptr->prev == NULL) return;

    temp = ptr->prev;

    if(temp->prev != NULL)
        temp->prev->next = ptr;
    else
        start = ptr;

    ptr->prev = temp->prev;

    free(temp);
}

void delete_value(int num) {
    struct node *ptr = start;

    while(ptr != NULL && ptr->data != num)
        ptr = ptr->next;

    if(ptr == NULL) return;

    if(ptr->prev != NULL)
        ptr->prev->next = ptr->next;
    else
        start = ptr->next;

    if(ptr->next != NULL)
        ptr->next->prev = ptr->prev;

    free(ptr);
}

int main() {

    int choice,val,num;

    while(1) {

        printf("\n1 Traverse\n2 Insert Begin\n3 Insert End\n4 Insert After\n5 Insert Before\n");
        printf("6 Delete Begin\n7 Delete End\n8 Delete After\n9 Delete Before\n10 Delete Value\n0 Exit\n");

        scanf("%d",&choice);

        switch(choice) {

            case 1: traverse(); break;

            case 2:
                scanf("%d",&val);
                insert_begin(val);
                break;

            case 3:
                scanf("%d",&val);
                insert_end(val);
                break;

            case 4:
                scanf("%d %d",&num,&val);
                insert_after(num,val);
                break;

            case 5:
                scanf("%d %d",&num,&val);
                insert_before(num,val);
                break;

            case 6:
                delete_begin();
                break;

            case 7:
                delete_end();
                break;

            case 8:
                scanf("%d",&num);
                delete_after(num);
                break;

            case 9:
                scanf("%d",&num);
                delete_before(num);
                break;

            case 10:
                scanf("%d",&num);
                delete_value(num);
                break;

            case 0:
                exit(0);
        }
    }
}