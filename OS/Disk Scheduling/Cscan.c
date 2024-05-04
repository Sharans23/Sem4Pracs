#include<stdio.h>
#include<stdlib.h>

void main() {
    int rq[20], r[20], dist = 0, n, initial, i, j, size, count = 0, temp;

    printf("Enter initial position: ");
    scanf("%d", &initial);

    printf("Enter total disk size: ");
    scanf("%d", &size);

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter requests: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &rq[i]);
    }

    // Sorting requests in ascending order
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (rq[j] > rq[j + 1]) {
                temp = rq[j];
                rq[j] = rq[j + 1];
                rq[j + 1] = temp;
            }
        }
    }

    // Finding the index where the initial head position is less than or equal to the request
    for (i = 0; i < n; i++) {
        if (initial <= rq[i]) {
            break;
        }
    }

    // Scanning disk requests from initial position to the end
    for (j = i; j < n; j++) {
        dist += abs(rq[j] - initial);
        initial = rq[j];
        r[count++] = rq[j];
    }

    // If the head reaches the end, move to the beginning of the disk
    if (j == n) {
        dist += size - 1 - initial;  // Move to the end of the disk
        dist += size - 1;            // Jump to the beginning of the disk
        initial = 0;                 // Reset initial position
    }

    // Scanning disk requests from the beginning to the initial position
    for (j = 0; j < i; j++) {
        dist += abs(rq[j] - initial);
        initial = rq[j];
        r[count++] = rq[j];
    }

    printf("Total head movement is %d\n", dist);
    printf("Requests resolved in the following order: ");
    for (i = 0; i < count; i++) {
        printf("%d\t", r[i]);
    }
}
