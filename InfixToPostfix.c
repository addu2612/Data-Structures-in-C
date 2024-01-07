#include <stdio.h>
#include <ctype.h>

char infix[100], postfix[100];
int top = -1;

void push(int *stack, int val) {
    if (top == 99) {
        printf("Stack is full");
    } else {
        stack[++top] = val;
        printf("%d pushed into stack\n", val);
    }
}

int pop(int *stack) {
    if (top == -1) {
        printf("Stack is empty\n");
        return 0; 
    } else {
        int k = stack[top];
        top--;
        return k;
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int priority(char a) {
    if (a == '^' || a == '%') {
        return 3;
    } else if (a == '/' || a == '*') {
        return 2;
    } else if (a == '+' || a == '-') {
        return 1;
    }
    return 0;
}

void infixtopost() {
    int i = 0, j = 0;
    char x, y;
    int stack[100];  

    x = infix[i];
    while (x != '\0') {
        if (isalpha(x) || isdigit(x)) {
            postfix[j] = x;
            j++;
        } else if (x == '(') {
            push(stack, x);
        } else if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '%') {
            while (top != -1 && priority(x) <= priority(stack[top])) {
                y = pop(stack);
                postfix[j] = y;
                j++;
            }
            push(stack, x);
        } else if (x == ')') {
            y = pop(stack);
            while (y != '(') {
                postfix[j] = y;
                j++;
                y = pop(stack);
            }
        } else {
            printf("Expression is not correct");
        }
        i++;
        x = infix[i];
    }
    while (top != -1) {
        y = pop(stack);
        postfix[j] = y;
        j++;
    }
}

int evaluatePostfix(char *postfix) {
    int stack[100];  
    top = -1;
    int i, operand1, operand2, result;
    char ch;

    for (i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];

        if (isdigit(ch)) {
            push(stack, ch - '0');
        } else if (isOperator(ch)) {
            operand2 = pop(stack);
            operand1 = pop(stack);

            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }

            push(stack, result);
        }
    }

    return pop(stack);
}

int main() {
    printf("Enter the infix expression:\n");
    scanf("%s", infix);
    printf("Infix Statement:\n%s\n", infix);
    infixtopost();
    printf("Postfix Statement:\n%s\n", postfix);
    int result = evaluatePostfix(postfix);
    printf("Result of evaluation: %d\n", result);
    return 0;
}
