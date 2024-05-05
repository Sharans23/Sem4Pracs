#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prefixSuffixarray(char *pat, int m, int *pps){
    int length = 0;
    pps[0] = 0;
    int i = 1;

    while (i < m){
        if (pat[i] == pat[length]){
            length++;
            pps[i] = length;
            i++;
        }
        else{
            if (length != 0){
                length = pat[length - 1];
            }
            else{
                pps[i] = 0;
                i++;
            }
        }
    }
}

int main(){
    char text[] = "hjhhh";
    char pat[] = "jhh";
    kmp(text, pat);
    return 0;
}

void kmp(char *text, char *pat){
    int m = strlen(pat);
    int n = strlen(text);
    int pps[m];
    prefixSuffixarray(pat, m, pps);

    int i = 0;
    int j = 0;

    while (i < n){
        if (pat[j] == text[i]){
            i++, j++;
        }
        if (j == m){
            printf("Pattern fpund at %d", i - j);
            j = pps[j - 1];
        }
        else if (i < n && pat[j] != text[i]){
            if (j != 0){
                j = pps[j - 1];
            }
            else{
                i = i + 1;
            }
        }
    }
}