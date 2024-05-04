#include <stdio.h>
#include <stdlib.h>

int i;
int mutex=1;
int full=0; //no of slots
int empty=10; //variable represents the number of empty slots in the buffer, initialized to 10 (the size of the buffer).
int x=0; //represents the item being produced

void producer(){
    --mutex;
    ++full;
    --empty;
    x++;
    printf("\nProducer produces the item: %d",x);
    ++mutex;
}
void consumer(){
    --mutex;
    --full;
    ++empty;
    x--;
    printf("\nConsumer consumed the item: %d",x);
    ++mutex;
}

void main(){
    int n, i;
    printf("\n1. Press 1 for Producer"
           "\n2. Press 2 for Consumer"
           "\n3. Press 3 for Exit");
    #pragma omp critical           
    for(int i=1;i>0;i++){
        printf("Enter your choice");
        scanf("%d",&n);
        switch(n){
        case 1:
            if((mutex==1) && (empty!=0)){
                producer();
            }
            else{
                printf("Buffer is full");
            }
        case 2:
            if((mutex==1)&&(full!=0)){
                consumer();
            }
            else{
                printf("Buffer is empty");
            }
        case 3:
            exit(0);
            break;        
        }
    }
}
