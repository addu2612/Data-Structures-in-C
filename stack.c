#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int size;
    char top;
    int *S;
};

void create(struct Stack *st){
    printf("Enter size");
    scanf("%d",&st->size);
    st->top=-1;
    st->S=(int *)malloc(st->size *sizeof(int));
}

void display(struct Stack st){
    int i;
    for(i=st.top;i>=0;i--){
        printf("%d",st.S[i]);
        printf("\n");
    }
}

void push(struct Stack *st,int x){
    if(st->top==st->size-1){
        printf("Stack overflow");
    }
    else{
        st->top++;
        st->S[st->top]=x;
    }
}

char pop(struct Stack *st){
    char x=-1;
    if(st->top==-1){
        printf("Stack underflow");
    }
    else{
        x=st->S[st->top];
        st->top--;
    }
    return x;
}

int peek(struct Stack st,int index){
    int x=-1;
    if(st.top-index+1<0){
        printf("Invalid position");    
    }
    else{
        x=st.S[st.top-index+1];
    }
    return x;
}

int isEmpty(struct Stack st){
    if(st.top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct Stack st){
    if(!isEmpty(st)){
        return st.S[st.top];
    }
    else{
        return -1;
    }
}
int stackTop(struct Stack st)
{
    if(!isEmpty(st)){
        return st.S[st.top];
    }
    return -1;
}


int main(){
    struct Stack st;
    create(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    display(st);
    printf("%d",peek(st,2));
    return 0;
}