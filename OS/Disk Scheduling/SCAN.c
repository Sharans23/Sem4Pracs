#include<stdio.h>
#include<stdlib.h>
void main(){
    int rq[20], r[20], dist=0,n,initial,i,j,size,count=0,index,temp;
    
// rq[20]: Array to store disk requests.
// r[20]: Array to store the order of processed requests.
// dist: Variable to store the total head movement.
// min: Unused variable, remove it.
// n: Variable to store the number of requests.
// initial: Variable to store the initial head position.
// i, j: Loop counters.
// size: Variable to store the total disk size.
// count: Variable to keep track of processed requests.
// index: Variable to store the index where the initial head position is less than the request.
// temp: Temporary variable used for swapping values.

    printf("enter initial position: ");
    scanf("%d",&initial);
    printf("Enter total disk size: ");
    scanf("%d",&size);
    printf("enter number of requests: ");
    scanf("%d",&n);
    printf("enter requests: ");
    for(i=0;i<n;i++){
        scanf("%d",&rq[i]);
    }
    //bubble sort
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(rq[j]>rq[j+1]){
                temp=rq[j];
                rq[j]=rq[j+1];
                rq[j+1]=temp;
            }
        }
    }
    // least greatest element above initial
    for(i=0;i<n;i++){
        if(initial<=rq[i]){
            index=i;
            break;
        }
    }

    for(i=index;i<n;i++){
        dist=dist+abs(rq[i]-initial);
        initial=rq[i];
        r[count] = rq[i];
        count++;
    }
    // last movement for max size 
    dist=dist+abs(size-rq[i-1]-1);
    initial = size-1;
    r[count] = size - 1;
    count++;

    // This loop processes the remaining requests in descending order, starting from the index obtained earlier (index-1)
    for(i=index-1;i>=0;i--){
        dist=dist+abs(rq[i]-initial);
        initial=rq[i];
        r[count] = rq[i];
        count++;
    }
    printf("Total head moment is %d",dist);
    printf("\nRequests resolved in following order: ");
    for(i=0;i<=n;i++){
        printf("%d\t",r[i]);
    }
}