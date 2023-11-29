//The array doesn't necessarily have to be sorted, but the algorithm is more efficient on sorted data.

#include <stdio.h> 
 
int min(int x, int y) 
    { 
        return (x <= y) ? x : y; 
    } 

int FibonacciSearch(int arr[],int n,int x) 
{ 
	
	int f1 = 0; 
	int f2 = 1;  
	int fib = f1 + f2; 

	while (fib < n) { 
		f2 = f1; 
		f1 = fib; 
		fib = f1 +f2; 
	} 

	int offset = -1; 

	while (fib > 1) { 
		int i = min(offset + f2, n - 1); 
		if (arr[i] < x) { 
			fib = f1; 
			f1 = f2; 
			f2 = fib - f1; 
			offset = i; 
		} 

		else if (arr[i] > x) { 
			fib = f2; 
			f1 = f1 - f2; 
			f2 = fib - f1; 
		} 
		else
			return i; 
	} 
	if (f1 && arr[offset + 1] == x) 
		return offset + 1; 
	return -1; 
} 

int main() {
    int a[1000];
    int n;
    int e;
    printf("Enter number of components: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &a[i]);
    }
    printf("Element you want to search:");
    scanf("%d",&e);    
    int searchIndex=FibonacciSearch(a, n,e);

    if(searchIndex==-1){
        printf("Element not found");
    }
    else{
        printf("Element %d was found at position %d",e,searchIndex);
    }

    return 0;  
}