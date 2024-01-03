#include <stdio.h>

int array_priority[100];
int array_data[100];
int size=0;

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void minHeapify(int index){
    int smallest=index;
    int left=2*index;
    int right=2*index+1;

    if(left<=size && array_priority[left]<array_priority[smallest]){
        smallest=left;
    }
    if(right<=size && array_priority[right]<array_priority[smallest]){
        smallest=right;
    }

    if(smallest!=index){
        swap(&array_priority[index], &array_priority[smallest]);
        swap(&array_data[index], &array_data[smallest]);
        minHeapify(smallest);
    }
}

void enqueue(int priority,int data){
    if(size==99){
        printf("Queue is full.");
    }
    else{
        size++;
        int i=size;
        array_priority[i]=priority;
        array_data[i]=data;

        while(i>1 && array_priority[i]<array_priority[i/2]){
            swap(&array_priority[i],&array_priority[i/2]);
            swap(&array_data[i],&array_data[i/2]);
            i=i/2;
        }
    }
}

int dequeue(){
    if (size == 0) {
        printf("Priority queue is empty. Cannot dequeue.\n");
        return -1; 
    }
    int root_data=array_data[1];
    array_priority[1]=array_priority[size];
    array_data[1]=array_data[size];
    size--;
    minHeapify(1);

    return root_data;
}

void printPriorityQueue() {
    printf("Priority Queue: ");
    for (int i = 1; i <= size; i++) {
        printf("(%d, %d) ", array_priority[i], array_data[i]);
    }
    printf("\n");
}

int main() {
    int priority, data;
    char choice;

    do {
        printf("Enter priority: ");
        scanf("%d", &priority);

        printf("Enter data: ");
        scanf("%d", &data);

        enqueue(priority, data);

        printf("Do you want to enqueue more elements? (y/n): ");
        scanf(" %c", &choice); 

    } while (choice == 'y' || choice == 'Y');

    printPriorityQueue();

    int removed = dequeue();
    printf("Dequeued: %d\n", removed);

    printPriorityQueue();

    return 0;
}
