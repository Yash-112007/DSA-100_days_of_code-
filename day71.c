#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

// Edge structure
struct Edge {
    int u, v, w;
};

int main() {
    int n, m, source;
    scanf("%d %d", &n, &m);

    struct Edge edges[m];

    // Input edges
    for(int i = 0; i < m; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    scanf("%d", &source);

    int dist[n];

    // Step 1: Initialize distances
    for(int i = 0; i < n; i++)
        dist[i] = INF;

    dist[source] = 0;

    // Step 2: Relax edges (n-1 times)
    for(int i = 1; i <= n-1; i++) {
        for(int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if(dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    // Step 3: Check negative cycle
    for(int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if(dist[u] != INF && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            return 0;
        }
    }

    // Step 4: Print shortest distances
    printf("Shortest distances from source:\n");
    for(int i = 0; i < n; i++) {
        if(dist[i] == INF)
            printf("%d -> INF\n", i);
        else
            printf("%d -> %d\n", i, dist[i]);
    }

    return 0;
}
