#include <stdlib.h>
#include <stdio.h>

#define MAX 50

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int A[],int low,int high){
    int pivot=A[low];
    int start=low;
    int end=high;

    while(start<end){
        while(A[start]<=pivot && start<=high-1){
            start++;
        }
        while(A[end]>pivot && end>=low+1){
            end--;
        }
        if(start<end){
            swap(&A[start],&A[end]);
        }
    }
    swap(&A[low],&A[end]);
    return end;
}


void quick(int A[],int low,int high){
    if(low<high){
        int loc=partition(A,low,high);
        quick(A,low,loc-1);
        quick(A,loc+1,high);
    }
}

int main(){
    int n=0;
    printf("Enter no of elements");
    scanf("%d",&n);
    int A[50];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    quick(A,0,n-1);
    printf("Sorted array");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}