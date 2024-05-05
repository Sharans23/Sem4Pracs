#include<stdio.h>
#include<stdlib.h>

int dist[20], edges[20][3];

void bellman(int nodes, int ecount, int start){
    int source, destination, weight;
    for(int i=0;i<nodes;i++){
        if(i==start){
            dist[i]=0;
        }
        else{
            dist[i]=1000;
        }
    }
    for(int i=0;i<nodes;i++){
        for(int j=0;j<ecount;j++){
            source = edges[j][0];
            destination = edges[j][1];
            weight = edges[j][2];

            if(dist[source]!=1000 && dist[destination]>dist[source]+weight){
                dist[destination]=dist[source]+weight;
            }
        }
    }
    for(int j=0;j<ecount;j++){
            source = edges[j][0];
            destination = edges[j][1];
            weight = edges[j][2];

            if(dist[source]!=1000 && dist[destination]>dist[source]+weight){
                printf("negative loop");
                return;
            }
        }
        for(int i=0;i<nodes;i++){
            printf("shortest path from %d to %d is:\t %d\n",start, i,dist[i]);
        }
}
void main(){
    int start, nodes, ecount;
    printf("Enter start node, number of nodes and number of edges: ");
    scanf("%d%d%d",&start, &nodes, &ecount);
    printf("Enter edges as source - destination - weight \n");
    for(int i=0;i<ecount;i++){
        scanf("%d%d%d",&edges[i][0],&edges[i][1],&edges[i][2]);
    }
    bellman(nodes, ecount, start);
}