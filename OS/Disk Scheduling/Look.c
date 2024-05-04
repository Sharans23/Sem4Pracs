#include <stdio.h>
#include <stdlib.h>

void main()
{
    int rq[20], r[20], dist = 0, min, n, initial, i, j, size, count = 0, index, temp;
    printf("enter initial position: ");
    scanf("%d", &initial);
    printf("Enter total disk size: ");
    scanf("%d", &size);
    printf("enter number of requests: ");
    scanf("%d", &n);
    printf("enter requests: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &rq[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (rq[j] > rq[j + 1])
            {
                temp = rq[j];
                rq[j] = rq[j + 1];
                rq[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (initial < rq[i])
        {
            index = i;
            break;
        }
    }
    for (i = index; i < n; i++)
    {
        dist = dist + abs(rq[i] - initial);
        initial = rq[i];
        r[count] = rq[i];
        count++;
    }
    // No need to scan back to the beginning in LOOK
    for (i = index - 1; i >= 0; i--) // Start from index - 1 to scan in reverse order
    {
        dist = dist + abs(rq[i] - initial);
        initial = rq[i];
        r[count] = rq[i];
        count++;
    }
    printf("Total head moment is %d", dist);
    printf("\nRequests resolved in following order: ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", r[i]);
    }
}
