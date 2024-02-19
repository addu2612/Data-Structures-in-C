#include<stdio.h>
#include<stdlib.h>

#define SIZE 10
/**/
struct Node {
    int data;
    struct Node* next;
};

int hash(int key){
    return key % SIZE;
}


struct Node* search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current;  
        }
        current = current->next;
    }
    return NULL;  
}

void insert(struct Node* H[], int key) {
    int index = hash(key);

    struct Node* nn = (struct Node*)malloc(sizeof(struct Node));
    nn->data = key;
    nn->next = NULL;

    if (H[index] == NULL) {
        H[index] = nn;
    } else {
        struct Node* current = H[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = nn;
    }
}

void display(struct Node* H[]) {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d -> ", i);
        struct Node* current = H[i];
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void displayMenu() {
    printf("\nHash Table Operations:");
    printf("\n1. Insert");
    printf("\n2. Display");
    printf("\n3. Exit");
    printf("\nEnter your choice: ");
}

int main() {
    struct Node* HT[SIZE] = {NULL};
    int choice, key;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                insert(HT, key);
                break;

            case 2:
                display(HT);
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }

    } while (choice != 3);

    return 0;
}
