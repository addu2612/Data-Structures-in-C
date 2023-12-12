//WAP in C to implement Polynomial Addition and Subtraction using Linked List

#include <stdio.h>
#include <stdlib.h>

// Node structure for a term in a polynomial
struct Node {
    int coeff, power;
    struct Node *next;
};

// Function to create a polynomial
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

// Function to add or subtract two polynomials
struct Node *addOrSubtractPolynomials(struct Node *poly1, struct Node *poly2, int subtract) {
    struct Node *result = NULL;
    struct Node *t1 = poly1;
    struct Node *t2 = poly2;

    while (t1 != NULL || t2 != NULL) {
        int c = 0, p = 0;

        if (t1 != NULL) {
            c += t1->coeff;
            p = t1->power;
            t1 = t1->next;
        }

        if (t2 != NULL) {
            c += (subtract ? -1 : 1) * t2->coeff;
            p = (t2->power > p) ? t2->power : p;
            t2 = t2->next;
        }

        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->coeff = c;
        newNode->power = p;
        newNode->next = NULL;

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

    return result;
}

// Function to display a polynomial
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

    } while (choice != 0);

    return 0;
}
