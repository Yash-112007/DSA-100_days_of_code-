#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int n;

// Queue implementation
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX-1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void kahnTopologicalSort() {
    int i, j;
    int count = 0;

    // Step 1: Calculate indegree
    for(i = 0; i < n; i++)
        indegree[i] = 0;

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            if(adj[i][j] == 1)
                indegree[j]++;

    // Step 2: Add nodes with indegree 0 to queue
    for(i = 0; i < n; i++)
        if(indegree[i] == 0)
            enqueue(i);

    printf("Topological Order: ");

    // Step 3: Process queue
    while(!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        // Reduce indegree of neighbours
        for(i = 0; i < n; i++) {
            if(adj[node][i] == 1) {
                indegree[i]--;
                if(indegree[i] == 0)
                    enqueue(i);
            }
        }
    }

    // Step 4: Check cycle
    if(count != n)
        printf("\nCycle detected! Topological sort not possible.");
}

int main() {
    int edges, u, v, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v) for u -> v:\n");
    for(i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    kahnTopologicalSort();
    return 0;
}
