#include <stdio.h>
#include <stdlib.h>
#define max 100

void main(){
    int n;
    int start[max];
    int end[max];
    printf("enter no of activity");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter start and end time of %d",i+1);
        scanf("%d %d",&start[i],&end[i]);
    }
    selectActivity(start,end,n);
}

void selectActivity(int start[],int end[],int n){
    int i=0;
    printf("Activty selected are: %d", i + 1);
    for(int j=1;j<n;j++){
        if(start[j]>=end[i]){
            printf("->%d",j+1);
            i=j;
        }
    }
}