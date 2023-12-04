#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the priority queue
struct Node {
    int data;
    int priority;
    struct Node* next;
};

// Structure to represent the priority queue
struct PriorityQueue {
    struct Node* front;
};

// Function to create a new node
struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty priority queue
struct PriorityQueue* createPriorityQueue() {
    struct PriorityQueue* pq = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    pq->front = NULL;
    return pq;
}

// Function to check if the priority queue is empty
int isEmpty(struct PriorityQueue* pq) {
    return (pq->front == NULL);
}

// Function to insert an element into the priority queue
void enqueue(struct PriorityQueue* pq, int data, int priority) {
    struct Node* newNode = createNode(data, priority);

    // If the priority queue is empty or the new node has higher priority than the front node
    if (isEmpty(pq) || priority < pq->front->priority) {
        newNode->next = pq->front;
        pq->front = newNode;
    }
    else {
        struct Node* temp = pq->front;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to remove and return the element with the highest priority from the priority queue
int dequeue(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority queue is empty.\n");
        return -1;
    }
    else {
        struct Node* temp = pq->front;
        int data = temp->data;
        pq->front = pq->front->next;
        free(temp);
        return data;
    }
}

// Function to display the elements in the priority queue
void display(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority queue is empty.\n");
    }
    else {
        struct Node* temp = pq->front;
        while (temp != NULL) {
            printf("(%d, %d) ", temp->data, temp->priority);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct PriorityQueue* pq = createPriorityQueue();
    int choice, data, priority;

    do {
        printf("\nPriority Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data and priority to enqueue: ");
                scanf("%d %d", &data, &priority);
                enqueue(pq, data, priority);
                break;

            case 2:
                printf("Dequeued element: %d\n", dequeue(pq));
                break;

            case 3:
                printf("Priority queue: ");
                display(pq);
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}
