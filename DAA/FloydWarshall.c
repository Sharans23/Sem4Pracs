#include <stdio.h>
#include <stdlib.h>
#define INF 99999
#define V 5

void print(int dist[][V]){
    printf("the following matrix shows the shortest distance between every pair of vertices:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
            {
                printf("%s \t", "INF");
            }
            else
            {
                printf("%d \t", dist[i][j]);
            }
        }
        printf("\n");
    }
}

void floydWar(int dist[][V]){
    int i,j,k;
    for(int k=0;k<V;k++){
        for (int i = 0; i < V; i++){
            for (int j = 0; j < V; j++){
                if(dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }   
        }
    }
    print(dist);
}

int main()
{
    int graph[V][V] = {{0, 4, INF, 5, INF},
                       {INF, 0, 1, INF, 6},
                       {2, INF, 0, 3, INF},
                       {INF, INF, 1, 0, 2},
                       {1, INF, INF, 4, 0}};
    floydWar(graph);
    return 0;
}