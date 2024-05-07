#include <stdio.h>

int binary_search(int arr[],int left,int right,int target){
    while(left<=right){
        int mid=(left+right)/2;

        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return -1;
}

int main(){
    int arr[]={1,3,54,66,67};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=54;
    int index=binary_search(arr,0,n-1,target);
    if(index==-1){
        printf("Target not found");
    }else{
        printf("target found at %d",index);
    }
}