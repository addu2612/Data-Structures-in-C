//WAP in C to implement Polynomial Addition and Subtraction using Linked List

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff, power;
    struct node *next;
} *start1, *start2, *start3;
struct node *create(struct node *start)
{
    int n, c, p;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        struct node *nn, *temp;
        nn = (struct node *)malloc(sizeof(struct node));
        printf("Enter the coefficient and power respectively:\n");
        scanf("%d\t%d", &c, &p);
        nn->coeff = c;
        nn->power = p;
        if (start == NULL)
        {
        }
        else
        {
            temp = start;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = nn;
        }
    }
    return start;
}
void addnode(int c, int p)
{
    struct node *nn, *temp;
    nn = (struct node *)malloc(sizeof(struct node));
    nn->coeff = c;
    nn->power = p;
    if (start3 == NULL)
    {
        start3 = nn;
    }
    else
    {
        temp = start3;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;
    }
}
void polynomial_add()
{
    int n, c, p;
    struct node *t1 = start1;
    struct node *t2 = start2;
    while (t1 != NULL && t2 != NULL)
    {
        if (t1->power == t2->power)
        {
            c = t1->coeff + t2->coeff;
            p = t1->power;
            addnode(c, p);
            t1 = t1->next;
            t2 = t2->next;
        }
        else if (t1->power > t2->power)
        {
            addnode(t1->coeff, t1->power);
            t1 = t1->next;
        }
        else
        {
            addnode(t2->coeff, t2->power);
            t2 = t2->next;
        }
    }
    if (t1 == NULL)
    {
        while (t2 != NULL)
        {
            addnode(t2->coeff, t2->power);
            t2 = t2->next;
        }
    }
    if (t2 == NULL)
    {
        while (t1 != NULL)
        {
            addnode(t1->coeff, t1->power);
            t1 = t1->next;
        }
    }
}
void display(struct node *start)
{
    struct node *temp;
    temp = start;
    while (temp->next != NULL)
    {
        printf("(%d)x^(%d) + ", temp->coeff, temp->power);
        temp = temp->next;
    }
    printf("(%d)x^(%d)\n", temp->coeff, temp->power);
}
int main()
{
    start1 = create(start1);
    start2 = create(start2);
    printf("The first polynomial is:");
    display(start1);
    printf("The second polynomial is:");
    display(start2);
    polynomial_add();
    printf("The polynomial addition is:\n");
    display(start3);
}