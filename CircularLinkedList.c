#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*start;

/**/
void createCLL() {
    struct Node *nn, *temp;

    nn = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &nn->data);
    nn->next = NULL;

    if (start == NULL) { 
        start = nn;
        start->next = start; // For a circular linked list, point back to start
    } else {
        // Traverse to the last node
        temp = start;
        while (temp->next != start) {
            temp = temp->next;
        }

        // Update last node's next pointer
        temp->next = nn;

        // For circular linked list, set new node's next to start
        nn->next = start;
    }
}

void display(){
    struct Node *temp = start;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Elements of CLL are: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != start);

    printf("\n");
}


void insert_beg(){
    struct Node*temp,*nn;
    
    nn = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &nn->data);
    if (start == NULL) {
       
        nn->next = nn;
        start = nn;
    }
    else{
    temp=start;
    while(temp->next!=start){
        temp=temp->next;
    }
    nn->next=start;
    temp->next=nn;
    start=nn;
    }
}

void insert_end(){
    struct Node*temp,*nn;
    
    nn = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &nn->data);
    if (start == NULL) {
        start = nn;
    }
    else{
    temp=start;
    while(temp->next!=start){
        temp=temp->next;
    }
    temp->next=nn;
    nn->next=start;
    }
}

void insert_after(){
    struct Node*temp,*nn;
    int val;
    printf("Value you want to insert after: ");
    scanf("%d",&val);
    nn = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &nn->data);
    temp=start;
    while(temp->next!=start && temp->data!=val){
        temp=temp->next;
    }
    nn->next=temp->next;
    temp->next=nn;
   
}

int count_nodes(){
    int c=0;
    struct Node*temp;
    temp = start;
    do {
        c++;
        temp = temp->next;
    } while (temp != start);
    return c;
}

void delete_cll(){
    struct Node *temp=start;
    struct Node *prev=NULL;
    int val;
    printf("Enter value to be deleted");
    scanf("%d",&val);
    //zero-eth case:empty list
    if (start == NULL) {
        printf("List is empty\n");
    }
    //first case:node is at the beginning and only element
    else if(start==start->next){
        free(start);
        start = NULL;
        printf("Node deleted");
    }
    //third case:node is anywhere
    else{
        while(temp->next!=start && temp->data!=val){
            prev=temp;
            temp=temp->next;
        }
        if (temp->next != start) {
            prev->next = temp->next;
            free(temp);
            printf("Node with value %d deleted\n", val);
        } 
        //node is at the end
        else {
            prev->next = start;
            free(temp);
            printf("Node with value %d deleted\n", val);
        }
    }
}

struct Node *search() {
    struct Node *temp = start;
    int key;
    
    if (temp == NULL) {
        printf("List is empty. Cannot search.\n");
        return NULL;
    }

    printf("Enter value you want to search: ");
    scanf("%d", &key);

    do {
        if (temp->data == key) {
            printf("Node with value %d found.\n", key);
            return temp;
        }
        temp = temp->next;
    } while (temp != start);

    printf("Node with value %d not found.\n", key);
    return NULL;
}


int main()
{
    int choice;

    do
    {
        printf("\n\n----- Circular Linked List Menu -----\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Insert at the beginning\n");
        printf("4. Insert at the end\n");
        printf("5. Insert after a node\n");
        printf("6. Count nodes\n");
        printf("7. Delete a node\n");
        printf("8. Search a node\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createCLL();
            break;
        case 2:
            display();
            break;
        case 3:
            insert_beg();
            break;
        case 4:
            insert_end();
            break;
        case 5:
            insert_after();
            break;
        case 6:
            printf("Number of nodes: %d\n", count_nodes());
            break;
        case 7:
            delete_cll();
            break;
        case 8:
            search();
            break;
        case 9:
            printf("Exiting the program. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (1);

    return 0;
}
