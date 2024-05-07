#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000

void selection(int arr[]){
    int i,j,small;

    for(i=0;i<N-1;i++){
        small=i;
        for(j=i+1;j<N;j++){
            if(arr[j]<arr[small]){
                small=j;
            }
        }
        int temp = arr[small];
        arr[small] = arr[i];
        arr[i] = temp;
    }
}

int main(){
    int arr[N];
    int i;
    for(i=0;i<N;i++){
        arr[i]=rand();
    }
    int start=clock();
    selection(arr);
    int end=clock();
    printf("time taken for sorting %d,",end-start);
}