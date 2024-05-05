#include<stdio.h>
int par[20], v[20], dist[20], n, s, i, j,k;
int graph[6][6]={{0, 4, 0, 0, 0, 0},
                {4, 0, 8, 0, 0, 0},
                {0, 8, 0, 7, 0, 4},
                {0, 0, 7, 0, 9, 14},
                {0, 0, 0, 9, 0, 10},
                {0, 0, 4, 14, 10, 0}};
                    
void initialise_single_source(){
    for(i = 0;i<n;i++){
        dist[i] = 10000;
        par[i]=-1;
    }
    dist[s] = 0;
}
int find_min(){
    int min=10000;
    int temp=-1;
    // int i;
    for(k=0;k<n;k++){
        if(dist[k]<min && v[k]==0){
            temp=k;
            min=dist[k];
        }
    }
    v[temp]=1;
    return temp;
}
void relax(int u, int v){
    if(dist[v]>(dist[u]+graph[u][v])){
        dist[v]=(dist[u]+graph[u][v]);
        par[v]=u;
    }
}
void display(){
    printf("dist\tpar\n");
    for(i = 0;i<n;i++){
        printf("%d\t %d\n",dist[i],par[i]);
    }
}
void Dijkstra(){
    initialise_single_source();
    for(i = 0;i<n;i++){
        int u = find_min();
        for(j=0;j<n;j++){
            if(graph[u][j]!=0 && v[j]==0){
                relax(u,j);
            }
        }
    }
    display();
}

int main(){  
    n=6;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
    printf("Enter source: ");
    scanf("%d",&s);
    Dijkstra();
    return 0;
}