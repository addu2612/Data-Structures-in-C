#include<stdio.h>


void  SelectionSort(int a[], int n){
    int i,j,k;
    int temp=0;
    for(i=0;i<n-1;i++){
        for(j=k=i;j<n;j++){
            if(a[j]<a[k]){
                k=j;
            }
        }  
        temp=a[i];
        a[i]=a[k];
        a[k]=temp;
    }
    printf("After sorting: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
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

    SelectionSort(a, n);

    return 0;
}
