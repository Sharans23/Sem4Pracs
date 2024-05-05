#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int a[30],count=0;
int place(int r)
{
    int j;
    for(j=1;j<r;j++)
    {
        if(a[j]==a[r]|| abs(a[j]-a[r])== abs(j-r))
        return 0;
    }       
    
    return 1;
}
void print_sol(int n)
{
    int i,j;
    count++;
    printf("solution %d\n",count);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i]==j)
            {
                printf("Q\t");
            }
            else
            printf("*\t");
        }
        printf("\n");
    }
}
void queen(int n)
{
    int k=1;
    a[k]=0;
    while(k!=0)
    {
        do{
            a[k]++;
        }while(a[k]<=n && !place(k));

        if(a[k]<=n)
        {
            if(k==n)
            {
                print_sol(n);
            }
            else
            {
                k++;
                a[k]=0;
            }
        }
        else
        k--;
    }
}
void main()
{
    int n;
    printf("Enter no of queens");
    scanf("%d",&n);
    queen(n);
    printf("Total Solutions: %d",count);
}