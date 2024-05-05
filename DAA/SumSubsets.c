#include <stdio.h>
#include <stdbool.h>

int main(){
    int arr[]={2,3,4,5,6,7,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=10;
    int subset[n];
    bool found =false;
    printf("All subsets that add upto %d: \n",sum);
    subset_sum(arr,n,sum,subset,0,0,&found);
    if(!found){
        printf("No subset found");
    }
    return 0;
}

void sum_subset(int arr[],int n,int sum,int subset[],int k,int index,bool *found){
    // k:The current size of the subset being considered
    // idx : The index in the input array arr from which we start considering elements
    // found : A pointer to a boolean variable indicating whether a subset with the target sum has been found ornot
    if(sum==0){
        printf("{");
        for(int i=0;i<k;i++){
            if(i<k-1){
                printf(", ");
            }
        }
        printf("}\n");
        *found=true;
        return;
    }
    if(sum<0 || index>=n){
        return;
    }
    // include the current element in the subset
    subset[k]=arr[index];
    sum_subset(arr,n,sum-subset[k],subset,k+1,index+1,found);

    // exclude the current element from the subset
    sum_subset(arr,n,sum,subset,k,index+1,found);
}

