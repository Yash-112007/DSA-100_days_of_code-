#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];

// add edge (undirected)
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

// DFS cycle check
int hasCycleDFS(int node, int parent) {
    visited[node] = 1;

    struct Node* temp = adj[node];
    while(temp != NULL) {
        int neighbor = temp->data;

        if(!visited[neighbor]) {
            if(hasCycleDFS(neighbor, node))
                return 1;
        }
        else if(neighbor != parent) {
            return 1; // cycle found
        }

        temp = temp->next;
    }
    return 0;
}

int main() {
    int n, m, u, v;
    printf("Enter vertices: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++) adj[i] = NULL;

    printf("Enter edges: ");
    scanf("%d",&m);

    printf("Enter edges (u v):\n");
    for(int i=0;i<m;i++) {
        scanf("%d %d",&u,&v);
        addEdge(u,v);
    }

    int cycle = 0;
    for(int i=0;i<n;i++) {
        if(!visited[i]) {
            if(hasCycleDFS(i, -1)) {
                cycle = 1;
                break;
            }
        }
    }

    if(cycle) printf("YES");
    else printf("NO");

    return 0;
}
