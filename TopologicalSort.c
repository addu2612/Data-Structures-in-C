#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Graph {
    int numVertices;
    struct Node** adjList;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->adjList = (struct Node**)malloc(numVertices * sizeof(struct Node*));

    for (int i = 0; i < numVertices; ++i) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

void topologicalSortUtil(struct Graph* graph, int v, int visited[], struct Node** stack, int* stackIndex) {
    visited[v] = 1;

    struct Node* temp = graph->adjList[v];
    while (temp != NULL) {
        int adjVertex = temp->data;
        if (!visited[adjVertex]) {
            topologicalSortUtil(graph, adjVertex, visited, stack, stackIndex);
        }
        temp = temp->next;
    }
    stack[(*stackIndex)++] = createNode(v);
}

void topologicalSort(struct Graph* graph) {
    int numVertices = graph->numVertices;
    int visited[numVertices];
    struct Node* stack[numVertices];
    int stackIndex = 0;

    for (int i = 0; i < numVertices; ++i) {
        visited[i] = 0;
    }

    for (int i = 0; i < numVertices; ++i) {
        if (!visited[i]) {
            topologicalSortUtil(graph, i, visited, stack, &stackIndex);
        }
    }
    printf("Topological Order: ");
    while (stackIndex > 0) {
        printf("%d ", stack[--stackIndex]->data);
        free(stack[stackIndex]);
    }
    printf("\n");
}

int main() {
    struct Graph* graph = createGraph(6);
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    topologicalSort(graph);

    return 0;
}
