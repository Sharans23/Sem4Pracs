#include<stdio.h> 
void main() 
{ 
    int incomingStream[30]; 
    int pageFaults = 0; 
    int frames = 3; 
    int j, i,n, s;
    printf("enter number of terms in incoming stream: ");
    scanf("%d",&n);
    printf("enter terms in incoming stream: ");
    for(i=0;i<n;i++){
        scanf("%d",&incomingStream[i]);
    }
    printf(" Incoming \t\t Frame 1 \t\t Frame 2 \t\t Frame 3 "); 
    //temp is used for storing the terms to be printed that is in memory
    int temp[ frames ]; 
    for(i = 0; i < frames; i++) 
    { 
        temp[i] = -1; 
    } 
    for(i = 0; i < n; i++) 
    { 
        //The variable s is initialized to 0 and will be used to track if the current page reference is already in memory.
        s = 0; 
        for(j = 0; j < frames; j++) 
        { 
            if(incomingStream[i] == temp[j]) 
            { 
                s++; 
                pageFaults--; 
            } 
        } 
        pageFaults++; 
        //if any memory location is free
        if((pageFaults <= frames) && (s == 0)) 
        { 
            temp[i] = incomingStream[i]; 
        }
        // replaces the oldest page in memory using the FIFO policy. 
        else if(s == 0) 
        { 
            //(pagefault-1)%frames is the formula for fifo
            temp[(pageFaults - 1) % frames] = incomingStream[i]; 
        } 
        printf("\n"); 
        printf("%d\t\t\t",incomingStream[i]); 
        for(j = 0; j < frames; j++) 
        { 
            if(temp[j] != -1) 
            printf(" %d\t\t\t", temp[j]); 
            else 
            printf(" - \t\t\t"); 
        } 
    } 
    printf("\nTotal Page Faults:\t%d\n", pageFaults); 
    int hit = n - pageFaults;
    printf("Hit:Miss Ratio: %d:%d",hit,pageFaults);
}