#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;

// DFS function (recursive)
void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int k, neighbour, start;

    // number of vertices
    scanf("%d", &n);

    // initialize matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    // input adjacency list and convert to matrix
    for (int i = 0; i < n; i++) {
        scanf("%d", &k); // number of neighbours of i
        for (int j = 0; j < k; j++) {
            scanf("%d", &neighbour);
            adj[i][neighbour] = 1;
        }
    }

    // starting vertex
    scanf("%d", &start);

    // initialize visited array
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    dfs(start);

    return 0;
}
