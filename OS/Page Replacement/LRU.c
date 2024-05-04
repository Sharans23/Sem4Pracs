#include<stdio.h>
// The checkHit function checks if the incoming page is already present in the occupied frames. 
int checkHit(int incomingPage, int queue[], int occupied){ 
     for(int i = 0; i < occupied; i++){
        if(incomingPage == queue[i])
        return 1;
    }
    return 0;
}

// The printFrame function prints the contents of the occupied frames in the queue array.
void printFrame(int queue[], int occupied)
{
    for(int i = 0; i < occupied; i++)
    printf("%d\t\t\t",queue[i]);
}


int main()
{
    int incomingStream[30], n ,frames = 3, queue[30], distance[30], occupied = 0, pagefault = 0,i;
    printf("enter number of terms in incoming stream: ");
    scanf("%d",&n);
    printf("enter terms in incoming stream: ");
    for(i=0;i<n;i++){
        scanf("%d",&incomingStream[i]);
    }
    printf("\nPage\t Frame1 \t Frame2 \t Frame3\n");
    // The outer loop iterates over the incomingStream array, processing one page reference at a time.
    for(i = 0;i < n; i++)
    {   
        printf("%d: \t\t",incomingStream[i]);

        // For each page reference, the code checks if it is already present in the occupied frames using the checkHit function.
        if(checkHit(incomingStream[i], queue, occupied)){
            // If the page reference is found in the occupied frames, the contents of the frames are printed using printFrame.
            printFrame(queue, occupied);
        }

        // If the page reference is not found in the occupied frames and there are still empty frames available (occupied < frames), the page reference is added to the next available frame, the page fault count is incremented, the number of occupied frames is incremented, and the updated contents of the frames are printed.
        else if(occupied < frames){
            queue[occupied] = incomingStream[i];
            pagefault++;
            occupied++;
 
            printFrame(queue, occupied);
        }

        // If the page reference is not found in the occupied frames and all frames are occupied (occupied == frames), the code enters the page replacement logic.
        else{   
            int max = -1;
            int index;
            for (int j = 0; j < frames; j++)
            {
                distance[j] = 0;
                for(int k = i - 1; k >= 0; k--)
                {
                    ++distance[j];
                    if(queue[j] == incomingStream[k])
                    break;
                }
                if(distance[j] > max){
                    max = distance[j];
                    index = j;
                }
            }  
            queue[index] = incomingStream[i];
            printFrame(queue, occupied);
            pagefault++;
        }
 
        printf("\n");
    }
    int hit = n - pagefault;
    printf("Page Fault: %d\n",pagefault);
    printf("Hit:Miss Ratio: %d:%d",hit,pagefault);
    return 0;
}
