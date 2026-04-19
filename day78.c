#include <stdio.h>
#include <limits.h>

#define MAX 100

int minKey(int key[], int mst[], int n) {
    int min = INT_MAX, minIndex;
    for(int i = 1; i <= n; i++) {
        if(mst[i] == 0 && key[i] < min) {
            min = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX];
    
    // initialize graph
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            graph[i][j] = 0;

    // input edges
    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        graph[u][v] = graph[v][u] = w;
    }

    int key[MAX], mst[MAX];
    int totalWeight = 0;

    for(int i=1;i<=n;i++){
        key[i] = INT_MAX;
        mst[i] = 0;
    }

    key[1] = 0; // start from node 1

    for(int count=1; count<=n; count++) {
        int u = minKey(key, mst, n);
        mst[u] = 1;
        totalWeight += key[u];

        for(int v=1; v<=n; v++) {
            if(graph[u][v] && mst[v]==0 && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d", totalWeight);
    return 0;
}
