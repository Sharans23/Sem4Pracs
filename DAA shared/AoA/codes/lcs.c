#include<stdio.h>
#include<string.h>
int m, n,i,j,LCS_table[20][20];
char s1[20], s2[20], b[20][20];
void lcsalgo(){
    m=strlen(s1);
    n=strlen(s2);

    for (i = 0; i <= m; i++)
        LCS_table[i][0] = 0;
    for (i = 0; i <= n; i++)
        LCS_table[0][i] = 0;
    
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                LCS_table[i][j] = LCS_table[i-1][j-1]+1;
            }
            else if(LCS_table[i-1][j]>=LCS_table[i][j-1]){
                LCS_table[i][j] = LCS_table[i-1][j];
            }
            else{
                LCS_table[i][j] = LCS_table[i][j-1];
            }
        }
    }
    int index = LCS_table[m][n];
    char lcsalgo[index+1];
    lcsalgo[index]='\0';

    int i = m, j = n;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            lcsalgo[index-1]=s1[i-1];
            i--;
            j--;
            index--;
        }
        else if(LCS_table[i-1][j]>LCS_table[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d ",LCS_table[i][j]);
        }
        printf("\n");
    }
    printf("s1: %s\ns2: %s\n",s1,s2);
    printf("LCS: %s",lcsalgo);
}
void main(){
    printf("enter the string1: ");
    scanf("%s",s1);
    printf("enter the string2: ");
    scanf("%s",s2);
    lcsalgo();
}