#include <stdio.h>

void FirstFit(int blockSize[],int blocks,int processSize[],int processes){
    int allocate[processes];
    int occupied[blocks];
    int totalMemory=0;
    int allocatedMemory=0;

    for (int i=0;i<processes;i++){
        allocate[i]=-1;
    }
    for(int i=0;i<blocks;i++){
        occupied[i]=0;
        totalMemory+=blockSize[i];
    }
    for(int i=0;i<processes;i++){
        for(int j=0;j<blocks;j++){
            if(!occupied[j] && blockSize[j]>=processSize[i]){
                allocate[i]=j;
                occupied[j]=1;
                allocatedMemory+=processSize[i];
                break;
            }
        }
    }
    printf("\nProcess No.\tProcess Size\tBlockk No.\n");
    for(int i=0;i<processes;i++){
        printf("%d \t\t\t %d \t\t\t",i+1,processSize[i]);
        if(allocate[i]!=-1){
            printf("%d\n",allocate[i]+1);;
        }
        else{
            printf("not allocated\n");
        }
    }
    printf("Percentage utilization:%.2f%%\n",((float)allocatedMemory/totalMemory)*100);
}

void bestFit(int blockSize[],int m,int processSize[],int n){
    int blockSizeCopy[m];
    int allocation[n];
    int totalMemory=0;
    int allocatedMemory=0;
    int blockAllocated[m];

    for(int i=0;i<m;i++){
        blockSizeCopy[i]=blockSize[i];
        blockAllocated[i]=0;
    }
    for(int i=0;i<n;i++){
        allocation[i]=-1;
    }
    for(int i=0;i<m;i++){
        totalMemory+=blockSize[i];
    }
    for(int i=0;i<n;i++){
        int bestIndex=-1;
        for(int j=0;j<m;j++){
            if(!blockAllocated[j] && blockSize[j]>=processSize[i]){
                if(bestIndex==-1 || blockSizeCopy[bestIndex]>blockSizeCopy[j]){
                    bestIndex=j;
                }
            }
        }
        if(bestIndex!=-1){
            allocation[i]=bestIndex;
            blockSizeCopy[bestIndex]-=processSize[i];
            allocatedMemory+=processSize[i];
            blockAllocated[bestIndex] = 1;
        }
    }
    printf("\nProcess No. \tProcess Size \tBlock No.\n");
    for(int i=0;i<n;i++){
        printf("%d \t\t\t %d\t\t\t",i+1,processSize[i]);
        if(allocation[i]!=-1){
            printf("%d\n",allocation[i]+1);
        }
        else{
            printf("Not allocated\n");
        }
    }
    printf("Percentage utilization%.3f%%\n",((float)allocatedMemory/totalMemory)*100);
}

void worstFit(int blockSize[],int m,int processSize[],int n){
    int blockSizeCopy[m];
    int allocation[n];
    int totalMemory=0;
    int allocatedMemory=0;
    int blockAllocated[m];

    for(int i=0;i<m;i++){
        blockSizeCopy[i]=blockSize[i];
        blockAllocated[i]=0;
    }
    for(int i=0;i<n;i++){
        allocation[i]=-1;
    }
    for(int i=0;i<m;i++){
        totalMemory+=blockSize[i];
    }
    for(int i=0;i<n;i++){
        int bestIndex=-1;
        for(int j=0;j<m;j++){
            if(!blockAllocated[j] && blockSize[j]>=processSize[i]){
                // only this difference


                if(bestIndex==-1 || blockSizeCopy[bestIndex]<blockSizeCopy[j]){
                    bestIndex=j;
                }
            }
        }
        if(bestIndex!=-1){
            allocation[i]=bestIndex;
            blockSizeCopy[bestIndex]-=processSize[i];
            allocatedMemory+=processSize[i];
            blockAllocated[bestIndex] = 1;
        }
    }
    printf("\nProcess No. \tProcess Size \tBlock No.\n");
    for(int i=0;i<n;i++){
        printf("%d \t\t\t %d\t\t\t",i+1,processSize[i]);
        if(allocation[i]!=-1){
            printf("%d\n",allocation[i]+1);
        }
        else{
            printf("Not allocated\n");
        }
    }
    printf("Percentage utilization%.3f%%\n",((float)allocatedMemory/totalMemory)*100);
}


void nextfit(int blockSize[],int blocks,int processSize[],int processes){
    int allocate[processes];
    int occupied[blocks];
    int totalMemory=0;
    int allocatedMemory=0;
    int lastIndex=0;
    int blockAllocated[blocks];

    for (int i=0;i<processes;i++){
        allocate[i]=-1;
    }
    for (int i=-1;i<blocks;i++){
        occupied[i]=0;
        totalMemory+=blockSize[i];
    }
    for(int i=0;i<processes;i++){
        for(int j=lastIndex;j<blocks;j++){
            if(!occupied[j] && blockSize[j]>=processSize[i]){
                allocate[i]=j;
                occupied[j]=1;
                allocatedMemory+=processSize[i];
                lastIndex=j;
                break;
            }
        }
    }
    printf("Next fit\n");
    printf("\nProcess No. \tProcess Size \tBlock No \n");
    for(int i=0;i<processes;i++){
        printf("%d \t\t\t %d \t\t\t",i+1,processSize[i]);
        if(allocate[i]!=-1){
            printf("%d\n",allocate[i]+1);
        }
        else{
            printf("not allocated");
        }
    }
    printf("PercentageUtilization:%.2f%%\n",((float)allocatedMemory/totalMemory)*100);
}


int main(){
    int blockSize[]={100,500,200,300,600};
    int m=sizeof(blockSize)/sizeof(blockSize[0]);
    int n;
    printf("enter no of processes");
    scanf("%d",&n);
    int processSize[n];
    printf("Enter the size of %d processes\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&processSize[i]);
    }
    printf("\n\nFirst Fit");
    FirstFit(blockSize,m,processSize,n);
    bestFit(blockSize,m,processSize,n);
    nextfit(blockSize,m,processSize,n);
}