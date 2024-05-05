#include <stdio.h>

int graph[10][10], i, j, count = 0, n, m, x[10], f = 0;
// count is used to keep track of the number of solutions found.
// n represents the number of nodes in the graph.
// m represents the number of colors used.
// x is an array to store the color assigned to each node.
// f is a flag variable to indicate if a solution is found or not .

void next_value(int k){
    while(1){
        x[k]=(x[k]+1)%m+1;
        // if the color value becomes 0, it means that all colors have been tried
        if (x[k] == 0)
        {
            return;
        }

        for(j=1;j<=n;j++){
            // it checks if the current color is valid by iterating over all adjacent nodes of k.If an adjacent node has the same color, it breaks out
            if (graph[k][j] == 1 && x[k] == x[j])
            {
                break;
            }
        }
        // If no adjacent node has the same color, the function returns.
        if(j==(n+1)){
            return;
        }
    }
}

void graphColoring(int k){
    while(1){
        next_value(k);
        // If no color is available (x[k] == 0), it returns.
        if(x[k]==0){
            return;
        }

        // If all nodes have been assigned colors (k == n), it prints the solution, increments the solution count, and returns.
        if(k==n){
            f=1;
            for(int i=1;i<=n;i++){
                printf("%d ",x[i]);
            }
            count++;
            printf("\n");
        }
        else{
            graphColoring(k+1);
        }
    }
}

void main(){
    printf("no of nodes");
    scanf("%d",&n);
    printf("Enter adjacency matrix");
    for(int i=1;i<=n;i++){
        x[i]=0;
        for(int j=1;j<=n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printf("Possible solns");
    for(m=1;m<=n;m++){
        if(f==1){
            break;
        }
        graphColoring(1);
    }
    printf("\nThe chromatic number is %d", m - 1);
    printf("\nThe total number of solutions is %d", count);
}