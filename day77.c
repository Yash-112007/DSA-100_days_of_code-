#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];
int adj[MAX][MAX];
int n, m;

void dfs(int node) {
    visited[node] = 1;
    for(int i = 1; i <= n; i++) {
        if(adj[node][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    
    // edges input
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;   // undirected graph
    }
    
    // DFS start from node 1
    dfs(1);
    
    // check if all nodes visited
    for(int i = 1; i <= n; i++) {
        if(visited[i] == 0) {
            printf("NOT CONNECTED");
            return 0;
        }
    }
    
    printf("CONNECTED");
    return 0;
}
