//linear probing
#include <stdio.h>
#define SIZE 10

int hash(int key) {
    return key % SIZE;
}

int probe(int H[], int key) {
    int index = hash(key);
    int i = 0;
    while (H[(index + i) % SIZE] != 0) {
        i++;
    }
    return (index + i) % SIZE;
}

void Insert(int H[], int key) {
    int index = hash(key);

    if (H[index] != 0) {
        index = probe(H, index);
        if (index == -1) {
            printf("Hash table is full. Unable to insert %d.\n", key);
            return;
        }
    }
    H[index] = key;
}

int Search(int H[], int key) {
    int index = hash(key);
    int i = 0;
    while (H[(index + i) % SIZE] != 0) {
        if (H[(index + i) % SIZE] == key) {
            return (index + i) % SIZE;
        }
        i++;
    }
    return -1;
}

void display(int H[]) {
    int i;
    printf("\nIndex\tValue\n");
    for (i = 0; i < SIZE; i++)
        printf("%d\t%d\n", i, H[i]);
}

void displayMenu() {
    printf("\nHash Table Operations:");
    printf("\n1. Insert");
    printf("\n2. Search");
    printf("\n3. Display");
    printf("\n4. Exit");
    printf("\nEnter your choice: ");
}

int main() {
    int HT[SIZE] = {0};
    int choice, key, result;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                Insert(HT, key);
                break;

            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                result = Search(HT, key);
                if (result != -1 && HT[result] == key) {
                    printf("Element %d found at index %d\n", key, result);
                } else {
                    printf("Element not found\n");
                }
                break;

            case 3:
                display(HT);
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}
