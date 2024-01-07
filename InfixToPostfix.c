#include <stdio.h>
#include <ctype.h>

char st[100];
char infix[100], postfix[100];
int top = -1;

void push(char a)
{
    if (top == 99)
    {
        printf("Stack is full");
    }
    else
    {
        st[++top] = a;
        printf("%c pushed into stack\n", a);
    }
}

char pop()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return '\0';
    }
    else
    {
        char k = st[top];
        top--;
        return k;
    }
}

int priority(char a)
{
    if (a == '^' || a == '%')
    {
        return 3;
    }
    else if (a == '/' || a == '*')
    {
        return 2;
    }
    else if (a == '+' || a == '-')
    {
        return 1;
    }
    return 0;
}

void infixtopost()
{
    int i = 0, j = 0;
    char x, y;

    x = infix[i];
    while (x != '\0')
    {
        if (isalpha(x) || isdigit(x))
        {
            postfix[j] = x;
            j++;
        }

        else if (x == '(')
        {
            push(x);
        }
        else if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '%')
        {
            while (top != -1 && priority(x) <= priority(st[top]))
            {
                y = pop();
                postfix[j] = y;
                j++;
            }
            push(x);
        }
        else if (x == ')')
        {
            y = pop();
            while (y != '(')
            {
                postfix[j] = y;
                j++;
                y = pop();
            }
        }
        else
        {
            printf("Expression is not correct");
        }
        i++;
        x = infix[i];
    }
    while (top != -1)
    {
        y = pop();
        postfix[j] = y;
        j++;
    }
}

int main()
{
    printf("Enter the infix expression:\n");
    scanf("%s", infix);
    printf("Infix Statement:\n%s\n", infix);
    infixtopost();
    printf("Postfix Statement:\n%s\n", postfix);
    return 0;
}
