#include <stdio.h>
#include <math.h>
 
int size = 8;
 
void FCFS(int arr[],int head)
{
    int seek_count = 0;
    int cur_track, distance;
    printf("Seek Sequence is\n");   
    for(int i=0;i<size;i++)
       {
        cur_track = arr[i];
        printf("%d\t",cur_track);
        distance = fabs(head - cur_track);
        seek_count += distance;
        head = cur_track;
    }
   
    printf("\nTotal number of seek operations: \n%d\n",seek_count);
}
int main()
{
    int arr[8] = { 176, 79, 34, 60, 92, 11, 41, 114 };
    int head = 50;  
    FCFS(arr,head);
    return 0;
}