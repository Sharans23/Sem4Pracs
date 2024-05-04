#include <stdio.h> 
void main()
{
    int flag1, flag2, flag3, i, j, k,n, position,inputStream[30], max, faults = 0;
    int num_frames = 3;
    int frames[num_frames];
    int temp[num_frames];
    printf("enter number of terms in incoming stream: ");
    scanf("%d",&n);
    printf("enter terms in incoming stream: ");
    for(i=0;i<n;i++){
        scanf("%d",&inputStream[i]);
    } 
    printf("Frame 1 \t Frame 2 \t Frame 3 "); 
    for(i = 0; i < num_frames; i++){
        frames[i] = -1;
    }
    for(i = 0; i < n; i++){
        flag1 = flag2 = 0;
        // The inner loop checks if the current page reference (inputStream[i]) is present in any of the frames (frames[j]).
        for(j = 0; j < num_frames; j++){
            // If the page reference is found, flag1 and flag2 are set to 1, and the inner loop is exited using the break statement.
            if(frames[j] == inputStream[i]){
                flag1 = flag2 = 1;
                break;
            }
        }
        // If the page reference is not found in the frames (!flag1), the code enters the page replacement logic.
        if(flag1 == 0){
            // The code checks if there are any empty frames (frames[j] == -1). If an empty frame is found, the incoming page reference (inputStream[i]) is added to that frame, the page fault count (faults) is incremented
            for(j = 0; j < num_frames; j++){
                if(frames[j] == -1){
                    faults++;
                    frames[j] = inputStream[i];
                    flag2 = 1;
                    break;
                }
            } 
        }
        // If all frames are occupied (flag2 == 0), the code enters the optimal page replacement logic.
        if(flag2 == 0){
            flag3 =0;
            for(j = 0; j < num_frames; j++){
                temp[j] = -1;
                // For each frame (frames[j]), the code iterates forward from the current page reference (k = i + 1) and finds the next occurrence of the page in the inputStream array. The value of k at which the page is found is stored in temp[j]
                for(k = i + 1; k < n; k++){
                    if(frames[j] == inputStream[k]){
                        temp[j] = k;
                        break;
                    }
                }
            }
            for(j = 0; j < num_frames; j++){
                // The code checks if any page in the frames will not be used again in the future (temp[j] == -1). If found, its position is stored in position, flag3 is set to 1, and the loop is exited using the break statement.
                if(temp[j] == -1){
                    position = j;
                    flag3 = 1;
                    break;
                }
            }
            if(flag3 ==0){
                // f all pages will be used again in the future (flag3 == 0), the code finds the frame that will not be used for the longest time in the future by finding the maximum value in the temp array, which corresponds to the farthest next occurrence of the page in the future.
                max = temp[0];
                position = 0;
                for(j = 1; j < num_frames; j++){
                    if(temp[j] > max){
                        max = temp[j];
                        position = j;
                     }
                } 
            }
            frames[position] = inputStream[i];
            faults++;
        }
        printf("\n");
        for(j = 0; j < num_frames; j++){
            printf("%d\t\t", frames[j]);
        }
    }
    printf("\n\nTotal Page Faults = %d", faults);
    printf("\nHit:Miss Ratio %d:%d",(n-faults),faults);
}