#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int n, m;
int graph[MAX][MAX];

// Function to find vertex with minimum distance
int findMinVertex(int dist[], int visited[])
{
    int min = INF, minIndex = -1;

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i] && dist[i] < min)
        {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int source)
{
    int dist[MAX], visited[MAX];

    // Initialize distances
    for(int i = 1; i <= n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    // Main loop
    for(int i = 1; i <= n; i++)
    {
        int u = findMinVertex(dist, visited);
        visited[u] = 1;

        for(int v = 1; v <= n; v++)
        {
            if(graph[u][v] != 0 && !visited[v])
            {
                if(dist[u] + graph[u][v] < dist[v])
                    dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print result
    for(int i = 1; i <= n; i++)
        printf("%d ", dist[i]);
}

int main()
{
    scanf("%d %d", &n, &m);

    // Initialize graph with 0
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            graph[i][j] = 0;

    // Input edges (undirected graph)
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int source;
    scanf("%d", &source);

    dijkstra(source);

    return 0;
}
