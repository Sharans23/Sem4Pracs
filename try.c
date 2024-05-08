#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int checkHit(int incomingPage,int queue[],int occupied){
    for(int i=0;i<occupied;i++){
        if(incomingPage==queue[i]){
            return 1;
        }
    }
    return 0;
}

void printFrame(int queue[],int occupied){
    for(int i=0;i<occupied;i++){
        printf("%d\t\t\t",queue[i]);
    }
}

int main(){
    int incommingStream[30],n,frames=3,queue[30],distance[30],occupied=0,pagefault=0,i;

    printf("enter number of terms in incoming stream: ");
    scanf("%d", &n);
    printf("enter terms in incoming stream: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &incommingStream[i]);
    }
    printf("\nPage\t Frame1 \t Frame2 \t Frame3\n");

    for(i=0;i<n;i++){
        printf("%d\t\t",incommingStream[i]);

        if(checkHit(incommingStream[i],queue,occupied)){
            printFrame(queue,occupied);
        }

        else if(occupied<frames){
            queue[occupied++]=incommingStream[i];
            pagefault++;

            printFrame(queue,occupied);
        }
        else{
            int max=-1;
            int index;
            for(int j=0;j<frames;j++){
                distance[j]=0;
                for(int k=i-1;k>0;k--){
                    ++distance[k];
                    if(queue[j]==incommingStream[k]){
                        break;
                    }
                }
                if (distance[j] > max)
                {
                    max = distance[j];
                    index = j;
                }
            }
            queue[index]=incommingStream[i];
            printf(queue,occupied);
            pagefault++;
        }
        printf("\n");
    }
    int hit = n - pagefault;
    printf("Page Fault: %d\n", pagefault);
    printf("Hit:Miss Ratio: %d:%d", hit, pagefault);
    return 0;
}