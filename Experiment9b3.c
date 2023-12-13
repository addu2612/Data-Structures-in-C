#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Partition(int a[], int l, int h) {
    int pivot = a[l];
    int i = l;
    int j = h;

    do {
        do {
            i++;
        } while (a[i] <= pivot);

        do {
            j--;
        } while (a[j] > pivot);

        if (i < j) {
            swap(&a[i], &a[j]);
        }
    } while (i < j);

    swap(&a[l], &a[j]);
    return j;
}

void QuickSort(int a[], int l, int h) {
    int j;
    if (l < h) {
        j = Partition(a, l, h);
        QuickSort(a, l, j);
        QuickSort(a, j + 1, h);
    }
}

int main() {
    int a[1000];
    int n;

    printf("Enter number of components: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &a[i]);
    }

    QuickSort(a, 0, n);

    printf("After sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
