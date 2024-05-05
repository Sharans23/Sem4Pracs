#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define d 256

// q (a prime number used for modular arithmetic).
void search(char pat[], char text[], int q)
{
    int m = strlen(pat);
    int n = strlen(text);
    int i, j;

    int p = 0;
    int t = 0;
    int h = 1;
    // p and t are used to store the hash values of the pattern and the current window in the text, respectively.
    // h is used for modular arithmetic calculations.

    for (i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }

    for (i = 0; i < m; i++)
    {
        p = (p * d + pat[i]) % q;
        t = (t * d + text[i]) % q;
    }

    for (i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
            {
                if (text[i + j] != pat[j])
                {
                    break;
                }
            }
            if (j == m)
            {
                printf("pattern found %d\n", i);
            }
        }
        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            if (t < 0)
            {
                t = t + q;
            }
        }
    }
}

int main()
{
    char text[] = "VIDHI LOVES CODING";
    char pat[] = "CODING";
    int q = 101;

    search(pat, text, q);
    return 0;
}