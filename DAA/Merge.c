#include <stdio.h>
#include <stdlib.h>
#define MAX 50

void merge(int A[],int low,int mid,int high){
    int i=low;
    int j=mid+1;
    int k=low;
    int b[MAX];
    while(i<=mid && j<=high){
        if(A[i]<A[j]){
            b[k]=A[i];
            i++;
            k++;
        }else{
            b[k]=A[j];
            j++;
            k++;
        }
    }
    if(i>=mid){
        while(j<=high){
            b[k]=A[j];
            j++;
            k++;
        }
    }
    if(j>=high){
        while (i<=mid)
        {
            b[k]=A[i];
            i++;
            k++;
        }
    }
    for(k=low;k<=high;k++){
        A[k]=b[k];
    }
}

void merge_sort(int A[],int low,int high){
    if(low<high){
        int p=(low+high)/2;
        merge_sort(A,low,p);
        merge_sort(A,p+1,high);
        merge(A,low,p,high);
    }
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int A[MAX];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    merge_sort(A,0,n-1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}