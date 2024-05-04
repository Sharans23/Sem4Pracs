#include<stdio.h>
#include<stdlib.h>
void main()
{
    // rq (an array to store the track requests), dist (to store the total head movement), min (to store the minimum distance), n (number of requests), initial (initial head position), i (loop counter), count (to keep track of processed requests), and r (an array to store the order of processed requests).
    int rq[20], dist=0, min,n,initial,i,count=0,r[20];
    printf("enter initial position: ");
    scanf("%d",&initial);
    printf("enter number of requests: ");
    scanf("%d",&n);
    printf("enter requests: ");
    for(i=0;i<n;i++){
        scanf("%d",&rq[i]);
        r[i]=0;
    }
    while(count!=n)
    {
        int min=1000,d,index;
        for(i=0;i<n;i++)
        {
            d=abs(rq[i]-initial);
            if(min>d)
            {
                min=d;
                index=i;
                r[count] = rq[i];
            }
        }
        dist=dist+min;
        initial=rq[index];
        // To prevent the same request from being processed again, rq[index] is set to a large value (1000).
        rq[index]=1000;
        count++;
    }
    printf("Total head movement is %d",dist);
    printf("\nRequests resolved in following order: ");
    for(i=0;i<n;i++){
        printf("%d\t",r[i]);
    }
}