#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define V 9

int minDist(int dist[], bool spcset[])
{
    int min = INT_MAX, min_value;
    for (int v = 0; v < V; v++)
    {
        if (spcset[v] == false && dist[v] <= min)
        {
            min = dist[v];
            min_value = v;
        }
    }
    return min_value;
}

void printS(int dist[])
{
    printf("Vertex \t distance from origin");
    for (int i = 0; i < V; i++)
    {
        printf("%d \t %d\n", i, dist[i]);
    }
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool spcset[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        spcset[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDist(dist, spcset);
        spcset[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!spcset[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printS(dist);
}

int main()
{
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    dijkstra(graph, 0);
    return 0;
}
