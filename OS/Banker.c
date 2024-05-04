#include <stdio.h>
int main(){
    // P0,P1,P2,P3,P4 are process names here
    int i, j, k;
    int n=5;  //number of processes
    int m=3; // number of resources

    //already allocated
    int alloc[5][3]=
    {
        {0,1,0},
        {2,0,0},
        {3,0,2},
        {2,1,1},
        {0,0,2}
    };
    //max resources needed
    int max[5][3]=
    {
        {7,5,3},
        {3,2,2},
        {9,0,2},
        {2,2,2},
        {4,3,3}
    };
    // remaining resources
    int avail[3]={3,3,2};

    int f[n],ans[n],index=0;
    // f is used to keep track of processes that have been completed
    // ans is used to store the safe search result
    for (int k=0;k<n;k++){
        f[k]=0; //storing zero for initial stage and will change to one once it is completed
    }

    int need[n][m];
    // creating need matrix
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            need[i][j]=max[i][j] - alloc[i][j];
        }
    }

    int y=0;
    for (k=0;k<5;k++){
        for(i=0;i<n;i++){
            if(f[i]==0){
                int flag=0;
                for (j=0;j<m;j++){
                    if(need[n][m]>avail[j]){
                        flag=1;
                        break;
                    }
                }

                if(flag==0){
                    ans[index++]=i;
                    for(j=0;j<m;j++){
                        avail[j]=avail[j] + alloc[i][j];
                        f[i]=1;
                    }
                }
            }
        }
    }

    int flag=1;
    for(int i=0;i<n;i++){
        if(f[i]==0){
            flag=0;
	        printf("The following system is not safe");
	        break;
        }
    }
    if(flag==1){
        printf('The safe sequence is\n');
        for (int i=0;i<n;i++){
            printf("P%d ->",ans[i]);   
        }
    }
    
}