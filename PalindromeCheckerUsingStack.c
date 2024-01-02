#include<stdio.h>
#include<string.h>

int st[100];
int top=-1;

char pop(){
    char k;
    if(top==-1){
        printf("Stack is empty");
    }
    else{
        k=st[top];
        top--;
    }
    return k;
}

void push(char a){
    if(top==99){
        printf("Stack is full");
    }
    else{
        top++;
        st[top]=a;
    }
}

int checkPalindrome(const char *str){
    int length = strlen(str);
    
    for (int i = 0; i < length; i++) {
        push(str[i]);
    }
    for (int i = 0; i < length; i++) {
        if (str[i] != pop()) {
            return 0;  
        }
    }

    return 1;
}

int main() {
    char a[100];
    printf("Enter a string: ");
    scanf("%s", a);

    if (checkPalindrome(a) == 1) {
        printf("Palindrome\n");
    }
    else {
        printf("Not palindrome\n");
    }

    return 0;
}
