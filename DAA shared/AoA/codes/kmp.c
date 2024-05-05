#include<stdio.h>
#include<string.h>

void computeLPS(char par[], int m, int lps[]) {
    int len = 0;
    lps[0] = 0;
    int i=1;
    while(i<m){
        if(par[i]==par[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len!=0){
                len = lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}
void KMPSearch(char txt[], char par[]){
    int m = strlen(par);
    int n = strlen(txt);
    int lps[20];
    computeLPS(par,m,lps);
        int i =0,j=0;
    while(i<n){
        if(txt[i]==par[j]){
            i++;
            j++;
        }
        if(j==m){
            printf("pattern found at: %d\n", i-j);
            j = lps[j-1];
        }
        else if(i<n && txt[i]!=par[j]){
            if(j!=0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    if(j!=m){
        printf("no more patterns");
    }
}
void main(){
    char txt[] = {"ABABDABACDABABCABAB"};
    char par[] = {"ABAB"};
    KMPSearch(txt, par);
}