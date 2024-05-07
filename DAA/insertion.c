#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000

void insertionSort(int arr[])
{
    int i, key, j;
    for (i = 1; i < N; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[N];
    int i;
    for (i = 0; i < N; i++)
    {
        arr[i] = rand();
    }
    int start_time2 = clock();
    insertionSort(arr);
    int end_time2 = clock();

    printf("time taken for insertion sorting:%d\n", end_time2 - start_time2);
    return 0;
}