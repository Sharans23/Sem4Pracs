#include <stdio.h>
#include <stdlib.h>

int n, x[10];

// k row and j column
int place(int k, int j)
{
    for (int i = 0; i < k; i++)
    {
        if (x[i] == j || abs(x[i] - j) == abs(i - k))
        {
            return 0;
        }
    }
    return 1;
}

int Nqueen(int k, int n)
{
    for (int j = 0; j < n; j++)
    {
        if (place(k, j))
        {
            x[k] = j;
            if (k + 1 == n)
            {
                for (int i = 0; i < n; i++)
                {
                    printf("%d", x[i] + 1);
                }
                printf("\n");
            }
            else
            {
                Nqueen(k + 1, n);
            }
        }
    }
}

void main()
{
    printf("enter size of board");
    scanf("%d", &n);
    Nqueen(0, n);
}