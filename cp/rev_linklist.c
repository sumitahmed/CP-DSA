// Write a C program to reverse a linked list

// Given linked list
// 25 19 14 10 
// Reversed linked list 
// 10 14 19 25

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* reverse(struct Node *start){
    struct Node *curr=start,*prev=NULL,*next;
    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

int main(){
    int n,x;
    struct Node *head=NULL,*tail=NULL,*t;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=x; t->next=NULL;
        if(!head){ head=t; tail=t; }
        else{ tail->next=t; tail=t; }
    }
    head=reverse(head);
    while(head){
        printf("%d ",head->data);
        head=head->next;
    }
    return 0;
}