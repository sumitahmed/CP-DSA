#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

/* ================= TRAVERSAL ================= */

void traverse() {
    struct node *ptr = start;

    if (ptr == NULL) {
        printf("List is Empty\n");
        return;
    }

    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

/* ================= INSERT AT FIRST ================= */

void insertAtFirst(int item) {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Overflow\n");
        return;
    }

    newnode->data = item;
    newnode->next = start;
    start = newnode;
}

/* ================= INSERT AT LAST ================= */

void insertAtLast(int item) {
    struct node *newnode, *ptr;

    newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Overflow\n");
        return;
    }

    newnode->data = item;
    newnode->next = NULL;

    if (start == NULL) {
        start = newnode;
        return;
    }

    ptr = start;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = newnode;
}

/* ================= INSERT AFTER VALUE ================= */

void insertAfter(int val, int item) {
    struct node *newnode, *ptr;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;

    ptr = start;
    while (ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Value not found\n");
        free(newnode);
        return;
    }

    newnode->next = ptr->next;
    ptr->next = newnode;
}

/* ================= INSERT BEFORE VALUE ================= */

void insertBefore(int val, int item) {
    struct node *newnode, *ptr;

    if (start == NULL) return;

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = item;

    if (start->data == val) {
        newnode->next = start;
        start = newnode;
        return;
    }

    ptr = start;
    while (ptr->next != NULL && ptr->next->data != val) {
        ptr = ptr->next;
    }

    if (ptr->next == NULL) {
        printf("Value not found\n");
        free(newnode);
        return;
    }

    newnode->next = ptr->next;
    ptr->next = newnode;
}

/* ================= DELETE FIRST ================= */

void deleteFirst() {
    struct node *ptr;

    if (start == NULL) {
        printf("Underflow\n");
        return;
    }

    ptr = start;
    start = ptr->next;
    free(ptr);
}

/* ================= DELETE LAST ================= */

void deleteLast() {
    struct node *ptr;

    if (start == NULL) {
        printf("Underflow\n");
        return;
    }

    if (start->next == NULL) {
        free(start);
        start = NULL;
        return;
    }

    ptr = start;
    while (ptr->next->next != NULL) {
        ptr = ptr->next;
    }

    free(ptr->next);
    ptr->next = NULL;
}

/* ================= DELETE AFTER VALUE ================= */

void deleteAfter(int val) {
    struct node *ptr, *temp;

    ptr = start;
    while (ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }

    if (ptr == NULL || ptr->next == NULL) {
        printf("Deletion not possible\n");
        return;
    }

    temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
}

/* ================= DELETE BY VALUE ================= */

void deleteByValue(int val) {
    struct node *ptr, *preptr;

    if (start == NULL) {
        printf("Underflow\n");
        return;
    }

    ptr = start;
    preptr = NULL;

    while (ptr != NULL && ptr->data != val) {
        preptr = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Value not found\n");
        return;
    }

    if (preptr == NULL)
        start = ptr->next;
    else
        preptr->next = ptr->next;

    free(ptr);
}

/* ================= DELETE BEFORE VALUE ================= */

void deleteBefore(int val) {
    struct node *preptr, *ptr, *nextptr;

    if (start == NULL) return;

    preptr = NULL;
    ptr = start;
    nextptr = start->next;

    while (nextptr != NULL && nextptr->data != val) {
        preptr = ptr;
        ptr = nextptr;
        nextptr = nextptr->next;
    }

    if (nextptr == NULL) {
        printf("Value not found\n");
        return;
    }

    if (preptr == NULL)
        start = nextptr;
    else
        preptr->next = nextptr;

    free(ptr);
}

/* ================= MENU DRIVER ================= */

int main() {
    int choice, item, val;

    while (1) {
        printf("\n===== LINKED LIST MENU =====\n");
        printf("1. Traverse\n");
        printf("2. Insert at First\n");
        printf("3. Insert at Last\n");
        printf("4. Insert After Value\n");
        printf("5. Insert Before Value\n");
        printf("6. Delete First\n");
        printf("7. Delete Last\n");
        printf("8. Delete After Value\n");
        printf("9. Delete By Value\n");
        printf("10. Delete Before Value\n");
        printf("11. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            traverse();
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &item);
            insertAtFirst(item);
            break;

        case 3:
            printf("Enter value: ");
            scanf("%d", &item);
            insertAtLast(item);
            break;

        case 4:
            printf("Enter value after which to insert: ");
            scanf("%d", &val);
            printf("Enter new value: ");
            scanf("%d", &item);
            insertAfter(val, item);
            break;

        case 5:
            printf("Enter value before which to insert: ");
            scanf("%d", &val);
            printf("Enter new value: ");
            scanf("%d", &item);
            insertBefore(val, item);
            break;

        case 6:
            deleteFirst();
            break;

        case 7:
            deleteLast();
            break;

        case 8:
            printf("Enter value after which to delete: ");
            scanf("%d", &val);
            deleteAfter(val);
            break;

        case 9:
            printf("Enter value to delete: ");
            scanf("%d", &val);
            deleteByValue(val);
            break;

        case 10:
            printf("Enter value before which to delete: ");
            scanf("%d", &val);
            deleteBefore(val);
            break;

        case 11:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
