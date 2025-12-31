#include <stdio.h>

#define size 4

int arr[size], front = -1, rear = -1;

void enqueue(int);
void dequeue();
void display();

int main(){
    int ch, item;

    do{
        printf("\n1. enqueue");
        printf("\n2. dequeue");
        printf("\n3. display");
        printf("\n4. exit\n");

        scanf("%d", &ch);

        switch(ch){
            case 1:
                printf("enter number: ");
                scanf("%d", &item);
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
        }
    }while(ch != 4);

    return 0;
}

void enqueue(int item){
    if(rear == size - 1){
        printf("overflow\n");
    }
    else if(front == -1){
        front = rear = 0;
        arr[rear] = item;
    }
    else{
        rear++;
        arr[rear] = item;
    }
}

void dequeue(){
    if(front == -1 || front > rear){
        printf("underflow\n");
    }
    else{
        printf("dequeued element: %d\n", arr[front]);
        front++;
    }
}

void display(){
    if(front == -1 || front > rear){
        printf("underflow\n");
    }
    else{
        for(int i = front; i <= rear; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}
