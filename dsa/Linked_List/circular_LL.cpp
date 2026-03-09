#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
};

node* start = NULL;

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

    int choice,item,key;

    while(true) {

        cout<<"\n1.Traverse\n2.Insert Begin\n3.Insert End\n4.Insert After\n5.Insert Before\n";
        cout<<"6.Delete Begin\n7.Delete End\n8.Delete After\n9.Delete By Value\n10.Delete Before\n11.Exit\n";

        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice) {

            case 1: traverse(); break;

            case 2:
                cin>>item;
                insert_begin(item);
                break;

            case 3:
                cin>>item;
                insert_end(item);
                break;

            case 4:
                cin>>key>>item;
                insert_after(key,item);
                break;

            case 5:
                cin>>key>>item;
                insert_before(key,item);
                break;

            case 6: delete_begin(); break;

            case 7: delete_end(); break;

            case 8:
                cin>>key;
                delete_after(key);
                break;

            case 9:
                cin>>key;
                delete_value(key);
                break;

            case 10:
                cin>>key;
                delete_before(key);
                break;

            case 11: return 0;
        }
    }
}

void traverse() {

    if(start==NULL) {
        cout<<"List empty";
        return;
    }

    node* ptr=start;

    do{
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }while(ptr!=start);
}

void insert_begin(int item) {

    node *ptr,*newnode=new node();

    newnode->data=item;

    if(start==NULL) {
        newnode->next=newnode;
        start=newnode;
        return;
    }

    ptr=start;

    while(ptr->next!=start)
        ptr=ptr->next;

    newnode->next=start;
    ptr->next=newnode;
    start=newnode;
}

void insert_end(int item) {

    node *ptr,*newnode=new node();

    newnode->data=item;

    if(start==NULL) {
        newnode->next=newnode;
        start=newnode;
        return;
    }

    ptr=start;

    while(ptr->next!=start)
        ptr=ptr->next;

    ptr->next=newnode;
    newnode->next=start;
}

void insert_after(int key,int item) {

    if(start==NULL) return;

    node* ptr=start;
    node* newnode=new node();
    newnode->data=item;

    do{
        if(ptr->data==key) break;
        ptr=ptr->next;
    }while(ptr!=start);

    if(ptr->data!=key) return;

    newnode->next=ptr->next;
    ptr->next=newnode;
}

void insert_before(int key,int item) {

    node *ptr=start,*preptr=NULL,*newnode=new node(),*last;

    newnode->data=item;

    do{
        if(ptr->data==key) break;
        preptr=ptr;
        ptr=ptr->next;
    }while(ptr!=start);

    if(ptr==start) {

        last=start;

        while(last->next!=start)
            last=last->next;

        newnode->next=start;
        last->next=newnode;
        start=newnode;
    }
    else{
        newnode->next=ptr;
        preptr->next=newnode;
    }
}

void delete_begin() {

    if(start==NULL) return;

    node *ptr=start,*temp=start;

    while(ptr->next!=start)
        ptr=ptr->next;

    if(start->next==start)
        start=NULL;
    else{
        ptr->next=start->next;
        start=start->next;
    }

    delete temp;
}

void delete_end() {

    if(start==NULL) return;

    node *ptr=start,*preptr;

    if(start->next==start) {
        delete start;
        start=NULL;
        return;
    }

    while(ptr->next!=start){
        preptr=ptr;
        ptr=ptr->next;
    }

    preptr->next=start;
    delete ptr;
}

void delete_after(int key) {

    if(start==NULL) return;

    node *ptr=start,*temp;

    do{
        if(ptr->data==key) break;
        ptr=ptr->next;
    }while(ptr!=start);

    temp=ptr->next;

    if(temp==start)
        start=start->next;

    ptr->next=temp->next;

    delete temp;
}

void delete_value(int key) {

    if(start==NULL) return;

    node *ptr=start,*preptr=NULL,*last;

    do{
        if(ptr->data==key) break;
        preptr=ptr;
        ptr=ptr->next;
    }while(ptr!=start);

    if(ptr==start) {

        last=start;

        while(last->next!=start)
            last=last->next;

        last->next=start->next;
        start=start->next;
    }
    else
        preptr->next=ptr->next;

    delete ptr;
}

void delete_before(int key) {

    if(start==NULL) return;

    node *ptr=start,*preptr=NULL,*temp;

    do{
        if(ptr->data==key) break;
        preptr=ptr;
        ptr=ptr->next;
    }while(ptr!=start);

    temp=start;

    while(temp->next!=preptr)
        temp=temp->next;

    temp->next=ptr;

    delete preptr;
}