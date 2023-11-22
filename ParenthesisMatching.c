#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack{
    int size;
    int top;
    char *S;
};

void push(struct Stack *st,int x){
    if(st->top==st->size-1){
        printf("Stack is full");
    }
    else{
        st->top++;
        st->S[st->top]=x;
    }

}

char pop(struct Stack *st){
    int x=-1;
    if(st->top==-1){
        printf("Stack is empty");
    }
    else{
        x=st->S[st->top];
        st->top--;
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
    if(st.top==st.size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int stacktop(struct Stack st){
    if(!isEmpty(st)){
    return st.S[st.top];

    }
    return -1;
}

void display(struct Stack st){
    for(int i=st.top; i>=0; i--){
        printf("%c", st.S[i]);
    }
    printf("\n");
}



int isBalance(char *exp){
    struct Stack st;
    st.size=strlen(exp);
    st.top=-1;
    st.S = (char *)malloc(sizeof(char) * st.size);

    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='('){
            push(&st,exp[i]);
        }
        else if(exp[i]==')'){
            if(isEmpty(st)){
                return 0;
            }
            pop(&st);
        }
    }
    return isEmpty(st)?1:0;
}

int isBalancedforAll(char *exp){
    struct Stack st;
    int x;
    st.size=strlen(exp);
    st.top=-1;
    st.S = (char *)malloc(sizeof(char) * st.size);

    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='['){
            push(&st,exp[i]);
        }
        else if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
            if(isEmpty(st)){
                return 0;
            }
            x = pop(&st);
            if(exp[i]=='(' && x!=41){
            return 0;
            }
            if(exp[i]=='[' && x!=93){
            return 0;
            }
            if(exp[i]=='{' && x!=125){
            return 0;
            }
        }
    }
    return isEmpty(st)?1:0;
}


int main(){
    char expression1[] = "((a+b)*(c-d))";
    char expression2[] = "{[a + b] * (c - d)}";

    int result1 = isBalance(expression1);
    int result2 = isBalancedforAll(expression2);

    if (result1 == 1) {
        printf("Expression 1 is balanced.\n");
    } else {
        printf("Expression 1 is not balanced.\n");
    }

    if (result2 == 1) {
        printf("Expression 2 is balanced.\n");
    } else {
        printf("Expression 2 is not balanced.\n");
    }
    return 0;
}