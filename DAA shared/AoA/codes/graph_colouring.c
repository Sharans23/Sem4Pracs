#include<stdio.h>

int graph[10][10], i,j,count = 0, n,m,x[10],f=0;

void nextvalue(int k){
    while(1){
        x[k] = (x[k]+1)%(m+1);
        if(x[k]==0){
            return;
        }
        for(j=1;j<=n;j++){
            if(graph[k][j]==1 && x[k]==x[j]){
                break;
            }
        }
        if(j==(n+1)){
            return;
        }
    }
}

void graphcolouring(int k){
    while(1){
        nextvalue(k);
        if(x[k]==0){
            return;
        }
        if(k==n){
            f = 1;
            for(i=1;i<=n;i++)
            {
            printf("%d ", x[i]);
            }
            count++;
            printf("\n");
            }
        else{
            graphcolouring(k+1);
        }
    }
    }

void main(){
    printf("number of nodes: ");
    scanf("%d",&n);
    printf("Enter Adjacency Matrix: ");
    for(i = 1; i<=n;i++){
        x[i]=0;
        for(j=1;j<=n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printf("Possible Solutions: ");
    for(m=1;m<=n;m++){
        if (f==1){
            break;
        }
        graphcolouring(1);
    }
    printf("\nThe chromatic number is %d", m-1);
    printf("\nThe total number of solutions is %d", count);
}