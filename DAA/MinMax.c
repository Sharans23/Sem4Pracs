#include <stdio.h>
#include <stdlib.h>
int min,max;

void main()
{
    int n, min, max;
    printf("enter no length of array");
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nprint element %d", i + 1);
        scanf("%d", &A[i]);
    }
    int start = 0;
    int end = len(A);
    MinMax(A, start, end);
    printf("\nMax = %d", max);
    printf("\n Min = %d", min);
}

int MinMax(int A[], int i, int j)
{
    if (i == j)
    {
        return (A[i], A[j]);
    }
    else if (j - i == 1)
    {
        if (A[i] > A[j])
        {
            return (A[i], A[j]);
        }
        else
        {
            return (A[j], A[i]);
        }
    }
    else
    {
        int min, max;
        int Lmin, Lmax, Rmin, Rmax;
        int mid = (i + j) / 2;
        Lmin, Lmax = (A, i, mid);
        Rmin, Rmax = (A, mid + 1, j);
        if (Lmin < Rmin)
        {
            min = Lmin;
        }
        else
        {
            min = Rmin;
        }
        if (Rmax > Lmax)
        {
            max = Rmax;
        }
        else
        {
            max = Lmax;
        }
        return (min, max);
    }
}