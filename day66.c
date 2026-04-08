#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
bool visited[MAX];
bool recStack[MAX];
int n;

// DFS function to detect cycle
bool dfs(int node)
{
    visited[node] = true;
    recStack[node] = true;

    for(int i = 0; i < n; i++)
    {
        if(graph[node][i]) // edge exists
        {
            // if not visited -> DFS
            if(!visited[i] && dfs(i))
                return true;

            // if already in recursion stack -> cycle
            else if(recStack[i])
                return true;
        }
    }

    // remove node from recursion stack before return
    recStack[node] = false;
    return false;
}

bool detectCycle()
{
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            if(dfs(i))
                return true;
        }
    }
    return false;
}

int main()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    if(detectCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
