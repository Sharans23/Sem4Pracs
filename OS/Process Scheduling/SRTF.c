#include <stdio.h>
#define MAX 9999
#define N 10 // Maximum number of processes

int main()
{
    int no[N], at[N], bt[N], rt[N], ct[N], tat[N], wt[N];
    float avgtat = 0, avgwt = 0;
    int n, s, remain = 0, time, temp;

    printf("<--SRTF Scheduling Algorithm (Preemptive)-->\n");
    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nProcess No: %d\n", i + 1);
        no[i] = i + 1;
        printf("Enter Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Enter Burst Time: ");
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (at[j] > at[j + 1])
            {
                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = no[j];
                no[j] = no[j + 1];
                no[j + 1] = temp;
            }

    printf("\nProcess\t\tAT\tBT\tCT\tTAT\tWT\n");
    rt[n] = MAX; // Sentinel value

    for (time = 0; remain != n; time++)
    {
        s = n;
        for (int i = 0; i < n; i++)
            if (at[i] <= time && rt[i] < rt[s] && rt[i] > 0)
                s = i;
        rt[s]--;
        if (rt[s] == 0)
        {
            remain++;
            ct[s] = time + 1;
            tat[s] = ct[s] - at[s];
            avgtat += tat[s];
            wt[s] = tat[s] - bt[s];
            avgwt += wt[s];
            printf("P%d\t\t%d\t%d\t%d\t%d\t%d\n", no[s], at[s], bt[s], ct[s], tat[s], wt[s]);
        }
    }

    avgtat /= n, avgwt /= n;
    printf("\nAverage TurnAroundTime=%f\nAverage WaitingTime=%f", avgtat, avgwt);
}