#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue{
    int rear;
    int front;
    int size;
    int *Q;
};

void create(struct Queue *q,int size){
    
    q->front=q->rear=-1;
    q->size=size;
    q->Q=(int *)malloc(sizeof(int)*q->size);
}


void enqueue(struct Queue *q,int x){
    if(q->rear==q->size-1){
        printf("Queue is full");
    }
    else{
        q->rear++;
        q->Q[q->rear]=x;
    }
}

int dequeue(struct Queue *q){
    int x=-1;
    if(q->front==q->rear){
        printf("Stack is empty");
    }
    else{
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}

void Display(struct Queue q){
    for(int i=q.front+1;i<=q.rear;i++){
        printf("%d",q.Q[i]);
    }
    printf("\n");
    

}

int main(){
    struct Queue q;
    create(&q,6);
    enqueue(&q,1);
    enqueue(&q,3);
    enqueue(&q,2);
    dequeue(&q);
    Display(q);

    return 0;
}