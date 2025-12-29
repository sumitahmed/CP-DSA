// Write a program to check one binary tree is BST or not
// Time 20 min

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* newNode(int a)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = a;
    temp -> next = NULL;
    return temp; 
}
struct node* rev(struct node* head)
{
    struct node *prev = NULL, *curr = head, *next = NULL;
    while(curr != NULL)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void print(struct node* head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
int main()
{
    struct node* head = newNode(25);
    head->next = newNode(19);
    head->next->next = newNode(14);
    head->next->next->next = newNode(10);
    printf("Given linked list\n");
    print(head);
    head = rev(head);
    printf("Reversed linked list\n");
    print(head);

    return 0;
}