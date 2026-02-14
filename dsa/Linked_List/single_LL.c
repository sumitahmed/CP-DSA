#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

/* Function declarations */
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
struct node *sort_list(struct node *);

int main()
{
    int option;

    do
    {
        printf("\n\n***** MAIN MENU *****");
        printf("\n1. Create a list");
        printf("\n2. Display the list");
        printf("\n3. Insert at beginning");
        printf("\n4. Insert at end");
        printf("\n5. Insert before a value");
        printf("\n6. Insert after a value");
        printf("\n7. Delete from beginning");
        printf("\n8. Delete from end");
        printf("\n9. Delete a given node");
        printf("\n10. Delete after a given node");
        printf("\n11. Delete entire list");
        printf("\n12. Sort the list");
        printf("\n13. Exit");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1: start = create_ll(start); break;
            case 2: start = display(start); break;
            case 3: start = insert_beg(start); break;
            case 4: start = insert_end(start); break;
            case 5: start = insert_before(start); break;
            case 6: start = insert_after(start); break;
            case 7: start = delete_beg(start); break;
            case 8: start = delete_end(start); break;
            case 9: start = delete_node(start); break;
            case 10: start = delete_after(start); break;
            case 11: start = delete_list(start); break;
            case 12: start = sort_list(start); break;
        }
    } while(option != 13);

    return 0;
}

/* Create linked list */
struct node *create_ll(struct node *start)
{
    struct node *new_node, *ptr;
    int num;

    printf("\nEnter -1 to stop");
    printf("\nEnter data: ");
    scanf("%d", &num);

    while(num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        new_node->next = NULL;

        if(start == NULL)
            start = new_node;
        else
        {
            ptr = start;
            while(ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = new_node;
        }

        printf("Enter data: ");
        scanf("%d", &num);
    }
    return start;
}

/* Display list */
struct node *display(struct node *start)
{
    struct node *ptr = start;
    if(start == NULL)
    {
        printf("\nList is empty");
        return start;
    }
    printf("\nLinked List: ");
    while(ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
    return start;
}

/* Insert at beginning */
struct node *insert_beg(struct node *start)
{
    struct node *new_node;
    int num;

    printf("\nEnter data: ");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = start;
    start = new_node;

    return start;
}

/* Insert at end */
struct node *insert_end(struct node *start)
{
    struct node *new_node, *ptr;
    int num;

    printf("\nEnter data: ");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;

    if(start == NULL)
        return new_node;

    ptr = start;
    while(ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = new_node;

    return start;
}

/* Insert before a value */
struct node *insert_before(struct node *start)
{
    struct node *new_node, *ptr, *preptr;
    int num, val;

    if(start == NULL) return start;

    printf("\nEnter data: ");
    scanf("%d", &num);
    printf("Enter value before which to insert: ");
    scanf("%d", &val);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    if(start->data == val)
    {
        new_node->next = start;
        start = new_node;
        return start;
    }

    preptr = start;
    ptr = start->next;

    while(ptr != NULL && ptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    if(ptr != NULL)
    {
        preptr->next = new_node;
        new_node->next = ptr;
    }

    return start;
}

/* Insert after a value */
struct node *insert_after(struct node *start)
{
    struct node *new_node, *ptr;
    int num, val;

    if(start == NULL) return start;

    printf("\nEnter data: ");
    scanf("%d", &num);
    printf("Enter value after which to insert: ");
    scanf("%d", &val);

    ptr = start;
    while(ptr != NULL && ptr->data != val)
        ptr = ptr->next;

    if(ptr != NULL)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        new_node->next = ptr->next;
        ptr->next = new_node;
    }

    return start;
}

/* Delete from beginning */
struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    if(start == NULL) return start;

    ptr = start;
    start = start->next;
    free(ptr);

    return start;
}

/* Delete from end */
struct node *delete_end(struct node *start)
{
    struct node *ptr, *preptr;
    if(start == NULL) return start;

    if(start->next == NULL)
    {
        free(start);
        return NULL;
    }

    preptr = start;
    ptr = start->next;

    while(ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = NULL;
    free(ptr);

    return start;
}

/* Delete a given node */
struct node *delete_node(struct node *start)
{
    struct node *ptr, *preptr;
    int val;

    if(start == NULL) return start;

    printf("\nEnter value to delete: ");
    scanf("%d", &val);

    if(start->data == val)
        return delete_beg(start);

    preptr = start;
    ptr = start->next;

    while(ptr != NULL && ptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    if(ptr != NULL)
    {
        preptr->next = ptr->next;
        free(ptr);
    }

    return start;
}

/* Delete after a given node */
struct node *delete_after(struct node *start)
{
    struct node *ptr, *temp;
    int val;

    if(start == NULL) return start;

    printf("\nEnter value after which to delete: ");
    scanf("%d", &val);

    ptr = start;
    while(ptr != NULL && ptr->data != val)
        ptr = ptr->next;

    if(ptr != NULL && ptr->next != NULL)
    {
        temp = ptr->next;
        ptr->next = temp->next;
        free(temp);
    }

    return start;
}

/* Delete entire list */
struct node *delete_list(struct node *start)
{
    struct node *ptr;
    while(start != NULL)
    {
        ptr = start;
        start = start->next;
        free(ptr);
    }
    printf("\nLinked list deleted");
    return start;
}

/* Sort the list */
struct node *sort_list(struct node *start)
{
    struct node *ptr1, *ptr2;
    int temp;

    if(start == NULL) return start;

    for(ptr1 = start; ptr1->next != NULL; ptr1 = ptr1->next)
    {
        for(ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next)
        {
            if(ptr1->data > ptr2->data)
            {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
        }
    }
    return start;
}
