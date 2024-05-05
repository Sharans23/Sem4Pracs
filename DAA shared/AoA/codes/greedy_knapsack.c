#include<stdio.h>

void knapsack(int n,float weight[],float profit[],int c){
    float x[20],tp;
    int i,u;
    u = c;
    for(i=0;i<n;i++){
        x[i]=0.0;
    }
    for(i=0;i<n;i++){
        if(weight[i]>u){
            break;
        }
        else{
            x[i] = 1.0;
            tp = tp + profit[i];
            u = u - weight[i];
        }
    }
    if(i<n){
        x[i]=u/weight[i];
    }
    tp = tp + (x[i]*profit[i]);
    printf("\nThe result vector is:- ");
   for (i = 0; i < n; i++)
      printf("%f\t", x[i]);

   printf("\nMaximum profit is:- %f", tp);

}

void main(){
    float weight[20], profit[20], ratio[20];
    int temp,n,i,j,c;
    printf("number of objects: ");
    scanf("%d",&n);
    printf("enter weight and profit of each: ");
    for(i=0;i<n;i++){
        scanf("%f%f",&weight[i],&profit[i]);
        ratio[i] = profit[i]/weight[i];
    }
    printf("enter capacity: ");
    scanf("%d",&c);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(ratio[i]<ratio[j]){
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = weight[i];
                ratio[i] = weight[j];
                weight[j] = temp;

                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }
    printf("in ascending order\nWeights\tProfits\n");
    for(i=0;i<n;i++){
        printf("%f\t%f\n",weight[i],profit[i]);
    }
    knapsack(n,weight,profit, c);

}