#include <stdio.h>

int max(int a,int b){
    return (a>b) ? a:b;
}

int knapsack(int W,int wt[],int val[],int n){
    int i,w;
    int table[n+1][w+1];
    for(i=0;i<=n;i++){
        for(w=0;w<=W;W++){
            if(i==0 || w==0){
                table[i][w]=0;
            }
            else if(wt[i-1]<=w){
                table[i][w]=max(val[i-1]+table[i-1][w-wt[i-1]],table[i-1][w]);
            }
            else{
                table[i][w]=table[i-1][w];
            }
        }
    }
    return table[n][W];
}

int main(){
    int profit[]={60,100,120};
    int weight[]={10,20,30};
    int W=50;
    int n=sizeof(profit)/sizeof(profit[0]);
    printf("maximum profit: %d",knapsack(W,weight,profit,n));
    return 0;
}