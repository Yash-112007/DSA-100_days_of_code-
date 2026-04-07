#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node for adjacency list
struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];

// Queue implementation
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if(rear == MAX-1) return;
    if(front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if(front == -1 || front > rear) return -1;
    return queue[front++];
}

// Add edge (undirected)
void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

// BFS function
void BFS(int source) {
    enqueue(source);
    visited[source] = 1;

    while(front <= rear) {
        int current = dequeue();
        printf("%d ", current);

        struct Node* temp = adj[current];
        while(temp != NULL) {
            if(!visited[temp->data]) {
                visited[temp->data] = 1;
                enqueue(temp->data);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, m, u, v, source;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for(int i=0;i<n;i++)
        adj[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter edges (u v):\n");
    for(int i=0;i<m;i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    printf("BFS Traversal: ");
    BFS(source);

    return 0;
}
