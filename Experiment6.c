// To implement Double Ended queue.

#include <stdio.h>
#include <stdlib.h>
int front = -1;
int rear = -1;
int size = 5;
int queue[5];

void insert_rear()
{ 
    int val;
    if ((rear + 1) % size == front)
    {
        printf("Queue is full!");
    }
    else if (rear == -1)
    {
        printf("enter the value:\n");
        scanf("%d", &val);
        rear = 0;
        front = 0;
        queue[rear] = val;
    }
    else
    {
        printf("enter the value:\n");
        scanf("%d", &val);
        rear = (rear + 1) % size;
        queue[rear] = val;
    }
}

void delete_front()
{
    int val;
    if (front == -1)
    {
        printf("Queue is empty!");
    }
    else if (front == rear)
    {
        val = queue[front];
        printf("the deleted value is %d ", val);
        front = -1;
        rear = -1;
    }
    else
    {
        val = queue[front];
        printf("the deleted value is %d ", val);
        front = (front + 1) % size;
    }
}
void insert_front()
{
    int val;
    if ((rear + 1) % size == front)
    {
        printf("queue is full!");
    }
    else if (front == -1)
    {
        printf("enter the value to be inserted:\n");
        scanf("%d", &val);
        front = 0;
        rear = 0;
        queue[front] = val;
    }
    else
    {
        printf("enter the value to be inserted:\n");
        scanf("%d", &val);
        front = (front - 1 + size) % size;
        queue[front] = val;
    }
}
void delete_rear()
{
    int val;
    if (rear == -1)
    {
        printf("queue is empty");
    }
    else if (rear == front)
    {
        val = queue[rear];
        printf("the value to be deleted is: %d\n", val);
        front = -1;
        rear = -1;
    }
    else
    {
        val = queue[rear];
        printf("the value to be deleted is: %d\n", val);
        rear = (rear - 1 + size) % size;
    }
}
void main()
{
    int choice1, choice2;
    int exit1 = 1;
    int exit2 = 1;
    while (exit1)
    {
        printf("enter: \n 1.Input Restricted \n 2. Output Restricted \n3.Exit\n");
        scanf("%d", &choice1);
        switch (choice1)
        {
        case 1:
            while (exit2)
            {
                printf("INPUT RESTRICTED:\n");
                printf("Enter:\n 1.insert_rear\n 2.delete_rear\n3.delete_front\n4.Exit");
                scanf("%d ", &choice2);
                switch (choice2)
                {
                case 1:
                    insert_rear();
                    break;
                case 2:
                    delete_rear();
                    break;
                case 3:
                    delete_front();
                    break;
                case 4:
                    exit2 = 0;
                    break;
                default:
                    printf("invalid input!");
                    break;
                }
            }
            break;
        case 2:
            while (exit2)
            {
                printf("OUTPUT RESTRICTED:\n");
                printf("Enter:\n 1.insert_rear\n 2.delete_front\n3.insert_front\n4.Exit");
                scanf("%d ", &choice2);
                switch (choice2)
                {
                case 1:
                    insert_rear();
                    break;
                case 2:
                    delete_front();
                    break;
                case 3:
                    insert_front();
                    break;
                case 4:
                    exit2 = 0;
                    break;
                default:
                    printf("invalid input!");
                    break;
                }
            }
            break;
        case 3:
            exit1 = 0;
            break;
        default:
            printf("inavlid input!");
            break;
        }
    }
}