#include<stdio.h>
int nf,np,j,i,fifo_pointer=0,hit=0,fault=0;
int frames[100],pages[100];
int find(int x){
for(int k=0;k<nf;k++){
if(frames[k]==x)
return 1;
}
return 0;
}
int find_index(int x){
int time[nf],temp;
for(int l=0;l<nf;l++){
for(int m=0;m<x;m++){
if(frames[l]==pages[m])
time[l]=m;
}
}
//sorting time array
for(int l=0;l<nf;l++){
for(int m=l+1;m<nf;m++){
if(time[l]>time[m]){
temp=time[l];
time[l]=time[m];
time[m]=temp;
}
}
}
// now checking which frame index to return
for(int l=0;l<nf;l++){
if(frames[l]==pages[time[0]])
return l;
}
}
void print_frame(){
for(int k=0;k<nf;k++){
if(frames[k]==-1)
printf("-\t");
else
printf("%d\t",frames[k]);
}
printf("\n");
}
void main(){
printf("Enter no of frames:\n");
scanf("%d",&nf);
printf("Enter no of page references:\n");
scanf("%d",&np);
printf("Enter page references:\n");
for(i=0;i<np;i++)
scanf("%d",&pages[i]);
for(i=0;i<nf;i++)
frames[i]=-1;
//printing header
for(i=0;i<nf;i++)
printf("F%d\t",i+1);
printf("\n");
for(i=0;i<np;i++){
if(find(pages[i])){
hit++;
print_frame();
}
else{
for(j=0;j<nf;j++){
if(frames[j]==-1){
fault++;
frames[j]=pages[i];
print_frame();
break;
}
}
if(j==nf){
fault++;
int index = find_index(i);
frames[index]=pages[i];
print_frame();
}
}
}
printf("Sharan Shetty C151 60004220224 07/03/2024\n");
printf("Number of Page Faults:%d\n",fault);
printf("Number of Page Hits:%d\n",hit);
}