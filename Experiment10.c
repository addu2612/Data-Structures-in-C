#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int data;
    struct Node* next;
};

struct Node* hashTable[SIZE];

// Function to initialize the hash table
void initializeHashTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }
}

// Function to insert a key into the hash table
void insert(int key) {
    int index = key % SIZE;
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = NULL;

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        struct Node* temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to search for a key in the hash table
int search(int key) {
    int index = key % SIZE;
    
    struct Node* temp = hashTable[index];
    while (temp != NULL) {
        if (temp->data == key) {
            return 1;  // Key found
        }
        temp = temp->next;
    }
    return 0;  // Key not found
}

// Function to display the hash table
void displayHashTable() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d:", i);
        struct Node* temp = hashTable[i];
        while (temp != NULL) {
            printf(" %d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    initializeHashTable();

    int choice, key;

    do {
        printf("\nHashing Techniques Menu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display Hash Table\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                if (search(key)) {
                    printf("Key %d found in the hash table.\n", key);
                } else {
                    printf("Key %d not found in the hash table.\n", key);
                }
                break;

            case 3:
                displayHashTable();
                break;

            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }

    } while (choice != 0);

    return 0;
}
