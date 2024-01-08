//WAP in C to implement Polynomial Addition and Subtraction using Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff, power;
    struct Node *next;
};


struct Node *createPoly() {
    int n, c, p;
    struct Node *start = NULL, *temp;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter coefficient and power: ");
        scanf("%d%d", &c, &p);
        newNode->coeff = c;
        newNode->power = p;
        newNode->next = NULL;

        if (start == NULL) {
            start = newNode;
        } else {
            temp = start;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    return start;
}

struct Node *addOrSubtractPolynomials(struct Node *poly1, struct Node *poly2, int subtract) {
    struct Node *result = NULL;
    struct Node *t1 = poly1;
    struct Node *t2 = poly2;

    while (t1 != NULL && t2 != NULL) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->next = NULL;

        // If powers are equal
        if (t1->power == t2->power) {
            newNode->coeff = t1->coeff + (subtract ? -1 : 1) * t2->coeff;
            newNode->power = t1->power;
            t1 = t1->next;
            t2 = t2->next;
        }
        // If power of first polynomial is greater
        else if (t1->power > t2->power) {
            newNode->coeff = t1->coeff;
            newNode->power = t1->power;
            t1 = t1->next;
        }
        // If power of second polynomial is greater
        else {
            newNode->coeff = (subtract ? -1 : 1) * t2->coeff;
            newNode->power = t2->power;
            t2 = t2->next;
        }

        if (result == NULL) {
            result = newNode;
        } else {
            struct Node *temp = result;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // If there are remaining terms in the first polynomial
    while (t1 != NULL) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->coeff = t1->coeff;
        newNode->power = t1->power;
        newNode->next = NULL;

        struct Node *temp = result;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;

        t1 = t1->next;
    }

    // If there are remaining terms in the second polynomial
    while (t2 != NULL) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->coeff = (subtract ? -1 : 1) * t2->coeff;
        newNode->power = t2->power;
        newNode->next = NULL;

        struct Node *temp = result;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;

        t2 = t2->next;
    }

    return result;
}

void display(struct Node *poly) {
    while (poly != NULL) {
        printf("(%d)x^(%d) ", poly->coeff, poly->power);
        poly = poly->next;
        if (poly != NULL) {
            printf("+ ");
        }
    }
    printf("\n");
}

int main() {
    struct Node *start1 = NULL, *start2 = NULL, *result = NULL;
    int choice;

    printf("Enter the first polynomial:\n");
    start1 = createPoly();
    printf("Enter the second polynomial:\n");
    start2 = createPoly();

    do {
        printf("\nPolynomial Operations Menu:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                result = addOrSubtractPolynomials(start1, start2, 0);
                printf("Polynomial addition is: ");
                display(result);
                break;

            case 2:
                result = addOrSubtractPolynomials(start1, start2, 1);
                printf("Polynomial subtraction is: ");
                display(result);
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
