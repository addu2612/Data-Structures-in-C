// To implement Double Ended queue.

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int front = -1;
int rear = -1;
int queue[SIZE];

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
    }

    for (int i = front; i != rear; i = (i + 1) % SIZE) {
        printf("%d ", queue[i]);
    }
    printf("%d\n", queue[rear]);
}


void insert_rear() {
    if ((rear + 1) % SIZE == front) {
        printf("Queue is full!\n");
    }

    int val;
    printf("Enter the value to be inserted: ");
    scanf("%d", &val);

    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = val;
}

void delete_front() {
    if (front == -1) {
        printf("Queue is empty!\n");
    }

    int val = queue[front];
    printf("The deleted value is: %d\n", val);

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}


void insert_front() {
    if ((rear + 1) % SIZE == front) {
        printf("Queue is full!\n");
    }
    int val;
    printf("Enter the value to be inserted: ");
    scanf("%d", &val);

    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        front = (front - 1 + SIZE) % SIZE;
    }

    queue[front] = val;
}

void delete_rear() {
    int val;
    if (rear == -1) {
        printf("Queue is empty!\n");
    } else if (rear == front) {
        val = queue[rear];
        printf("The value to be deleted is: %d\n", val);
        front = -1;
        rear = -1;
    } else {
        val = queue[rear];
        printf("The value to be deleted is: %d\n", val);
        rear = (rear - 1 + SIZE) % SIZE;
    }
}

int main() {
    int choice1, choice2;
    int exit1 = 1;
    int exit2 = 1;
    while (exit1) {
        printf("Enter:\n 1. Input Restricted\n 2. Output Restricted\n 3. Exit\n");
        scanf("%d", &choice1);
        switch (choice1) {
        case 1:
            while (exit2) {
                printf("INPUT RESTRICTED:\n");
                printf("Enter:\n 1. insert_rear\n 2. delete_rear\n 3. delete_front\n 4. Display\n 5. Exit\n");
                scanf("%d", &choice2);
                switch (choice2) {
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
                    display();
                    break;
                case 5:
                    exit2 = 0;
                    break;
                default:
                    printf("Invalid input!\n");
                    break;
                }
            }
            break;
        case 2:
            while (exit2) {
                printf("OUTPUT RESTRICTED:\n");
                printf("Enter:\n 1. insert_rear\n 2. delete_front\n 3. insert_front\n 4. Display\n 5. Exit\n");
                scanf("%d", &choice2);
                switch (choice2) {
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
                    display();
                    break;
                case 5:
                    exit2 = 0;
                    break;
                default:
                    printf("Invalid input!\n");
                    break;
                }
            }
            break;
        case 3:
            exit1 = 0;
            break;
        default:
            printf("Invalid input!\n");
            break;
        }
    }

    return 0;
}
