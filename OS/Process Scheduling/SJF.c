#include <stdio.h>

int main() {
    int n, j, min = 0;
    float avgtat = 0, avgwt = 0;

    printf("<--SJF Scheduling Algorithm (Non-Preemptive)-->\n");
    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    int no[10], at[10], bt[10], it[10], ct[10], tat[10], wt[10];
    printf("\n");

    // Reading process details
    for (int i = 0; i < n; i++) {
        printf("Process No: %d\n", i + 1);
        no[i] = i + 1;

        printf("Enter Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Enter Burst Time: ");
        scanf("%d", &bt[i]);

        printf("\n");
    }

    // Sorting processes based on arrival time
    for (int i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                // Swapping process details
                int temp;
                temp = no[j];
                no[j] = no[j + 1];
                no[j + 1] = temp;

                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
            }
        }
    }

    // Calculating completion time, turnaround time, and waiting time
    ct[0] = at[0] + bt[0];
    tat[0] = ct[0] - at[0];
    wt[0] = tat[0] - bt[0];
    avgtat += tat[0];
    avgwt += wt[0];

    for (int i = 1; i < n; i++) {
        it[i] = ct[i - 1];

        // Find next shortest burst time process
        for (j = i, min = i; j < n && at[j] <= ct[i - 1]; j++) {
            if (bt[j] < bt[min]) {
                min = j;
            }
        }

        // Swapping process details
        int temp;
        temp = no[i];
        no[i] = no[min];
        no[min] = temp;

        temp = at[i];
        at[i] = at[min];
        at[min] = temp;

        temp = bt[i];
        bt[i] = bt[min];
        bt[min] = temp;

        // Calculate completion time, turnaround time, and waiting time
        ct[i] = it[i] + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avgtat += tat[i];
        avgwt += wt[i];
    }

    // Print process details
    printf("\nProcess\t\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t%d\t%d\t%d\t%d\t%d\n", no[i], at[i], bt[i], ct[i], tat[i], wt[i], wt[i]);
    }

    // Calculate and print average turnaround time and average waiting time
    avgtat /= n;
    avgwt /= n;
    printf("\nAverage TurnAroundTime=%f\nAverage WaitingTime=%f", avgtat, avgwt);

    return 0;
}
