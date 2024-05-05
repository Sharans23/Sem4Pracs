#include<stdio.h>

int n,s,v[20],dist[20],par[20]; 
// int g[9][9]={{0,4,0,0,0,0,0,8,0},{4,0,8,0,0,0,0,11,0},{0,8,0,7,0,4,0,0,2},{0,0,7,0,9,14,0,0,0},{0,0,0,9,0,10,0,0,0},{0,0,4,14,10,0,2,0,0},{0,0,0,0,0,2,0,1,6},{8,11,0,0,0,0,1,0,7},{0,0,2,0,0,0,6,7,0}};
int g[6][6]={{0, 4, 0, 0, 0, 0},
                    {4, 0, 8, 0, 0, 0},
                    {0, 8, 0, 7, 0, 4},
                    {0, 0, 7, 0, 9, 14},
                    {0, 0, 0, 9, 0, 10},
                    {0, 0, 4, 14, 10, 0}};
void initialise_single_source(){
    for(int i=0;i<n;i++){
        dist[i]=10000;
        par[i]=-1;
    }
    dist[s]=0;  //setting distance of source =0;
}

int find_min(){

    int min=10000;
    int temp=-1;
    for(int i=0;i<n;i++){
        if(dist[i]<min && v[i]==0){
            temp=i;
            min=dist[i];
        }
    }
    v[temp]=1;
    return temp;
}

void relax(int u,int v){
    if(dist[v]>(dist[u]+g[u][v])){
        dist[v]=(dist[u]+g[u][v]);
        par[v]=u;
    }
}

void display(){
    printf("dist \t par\n");
    for(int i=0;i<n;i++){
        printf("%d \t %d\n",dist[i],par[i]);
    }
}

void Dijkstra(){
    initialise_single_source();
    for(int i=0;i<n;i++){
        int u = find_min();
        for(int j=0;j<n;j++){
            if(g[u][j]!=0 && v[j]==0){
                relax(u,j);
            }
        }
    }
    display();
}

void main(){
    n=6;
    printf("Graph Entered:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",g[i][j]);
        }
        printf("\n");
    }
    printf("Enter the source vertex:\n");
    scanf("%d",&s);
    Dijkstra();
}