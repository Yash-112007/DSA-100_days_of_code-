#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Edge structure
typedef struct {
    int dest, weight;
} Edge;

// Adjacency list node
typedef struct Node {
    Edge edge;
    struct Node* next;
} Node;

Node* adj[MAX];

// Min Heap Node
typedef struct {
    int vertex;
    int dist;
} HeapNode;

HeapNode heap[MAX];
int heapSize = 0;

int dist[MAX];
int visited[MAX];
int V;

// Swap heap nodes
void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(int i) {
    while (i && heap[i].dist < heap[(i-1)/2].dist) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Heapify down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < heapSize && heap[left].dist < heap[smallest].dist)
        smallest = left;
    if (right < heapSize && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Push into heap
void push(int v, int d) {
    heap[heapSize].vertex = v;
    heap[heapSize].dist = d;
    heapifyUp(heapSize);
    heapSize++;
}

// Pop min
HeapNode pop() {
    HeapNode root = heap[0];
    heap[0] = heap[--heapSize];
    heapifyDown(0);
    return root;
}

// Add edge
void addEdge(int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->edge.dest = v;
    newNode->edge.weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Dijkstra Algorithm
void dijkstra(int src) {
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;
    push(src, 0);

    while (heapSize > 0) {
        HeapNode minNode = pop();
        int u = minNode.vertex;

        if (visited[u]) continue;
        visited[u] = 1;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->edge.dest;
            int weight = temp->edge.weight;

            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                push(v, dist[v]);
            }
            temp = temp->next;
        }
    }
}

// Driver
int main() {
    int E, u, v, w, src;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++) adj[i] = NULL;

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w); // remove if directed graph
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(src);

    printf("\nShortest distances from source:\n");
    for (int i = 0; i < V; i++)
        printf("To %d = %d\n", i, dist[i]);

    return 0;
}
