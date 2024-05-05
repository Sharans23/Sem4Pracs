#include <stdio.h>
void maxmin(int a[], int l, int h, int *max, int *min)
{
    int max1 = -1, min1 = 999999;
    if (h == l)
    {
        *min = *max = a[h];
    }
    else if (h == l + 1)
    {
        if (a[l] > a[h])
        {
            *max = a[l];
            *min = a[h];
        }
        else
        {
            *max = a[h];
            *min = a[l];
        }
    }
    else
    {
        int mid = (l + h) / 2;
        maxmin(a, l, mid, max, min);
        maxmin(a, mid + 1, h, &max1, &min1);
        if (min1 < *min)
        {
            *min = min1;
        }
        if (max1 > *max)
        {
            *max = max1;
        }
    }
}
void main()
{
    int a[5] = {5, 45, 32, 1, 90};
    int min = 9999, max = -1;
    maxmin(a, 0, 4, &max, &min);
    printf("Max:%d Min:%d ", max, min);
}