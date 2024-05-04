#include <stdio.h>

int main() {
    int n, bt[20], at[20], temp[20], wt[20], tat[20],  i;
    float avwt = 0.0, avtat = 0.0;

    printf("Enter total number of processes (maximum 20): ");
    scanf("%d", &n);

    printf("\nEnter Process Arrival Time and Burst Time\n");
    for (i = 0; i < n; i++) {
        printf("P[%d] Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
        printf("P[%d] Burst Time  : ", i + 1);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0; // Waiting time for the first process is 0
    temp[0] = 0; // Initialize temporary array

    // Calculate waiting time for each process
    for (i = 1; i < n; i++) {
        temp[i] = temp[i - 1] + bt[i - 1]; // Calculate completion time of previous process
        wt[i] = temp[i] - at[i]; // Calculate waiting time
        if (wt[i] < 0) {
            wt[i] = 0; // If waiting time is negative, set it to 0
        }
    }

    // Calculate turnaround time for each process
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i]; // Turnaround time = Burst Time + Waiting Time
        avwt += wt[i];
        avtat += tat[i];
    }

    avwt /= n; // Calculate average waiting time
    avtat /= n; // Calculate average turnaround time

    printf("\nProcess Arrival Burst Waiting Turnaround\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]\t\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %f", avwt);
    printf("\nAverage Turnaround Time: %f\n", avtat);

    return 0;
}
