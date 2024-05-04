#include <stdio.h>
int input_arr[100];
int front = -1;
int rear = -1;
int z = 0;
int ready[100];
void enqueue(int k)
{
    ready[z] = k;
    z++;
    if (front == -1)
        front = 0;
    rear = rear + 1;
    input_arr[rear] = k;
}
int dequeue()
{
    int k;
    if (front == -1 || front > rear)
    {
        return -1;
    }
    if (front == rear)
    {
        k = input_arr[front];
        front = -1;
        rear = -1;
        return k;
    }
    else
    {
        k = input_arr[front];
        front = front + 1;
        return k;
    }
}
int main()
{
    int n, i, j, total = 0, quant, k, AT[100], BT[100], PID[100], CT[100], WT[100], TT[100], RT[100], ready_time[100];
    float avgtat = 0, avgwt = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter arrival time for process P%d: ", i + 1);
        scanf("%d", &AT[i]);
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &BT[i]);
        RT[i] = BT[i];
        PID[i] = i + 1;
        total += BT[i];
    }
    printf("Enter time quantum: ");
    scanf("%d", &quant);
    int times = 0, x = 0, completed = 0, y, execute;
    for (i = 0; i < n; i++)
    {
        if (AT[i] == times)
            enqueue(i);
    }
    while (completed <= n && times < total)
    {
        y = dequeue();
        if (RT[y] <= quant)
        {
            execute = RT[y];
        }
        else
        {
            execute = quant;
        }
        RT[y] = RT[y] - execute;
        CT[y] = times + execute;
        while (execute > 0)
        {
            times++;
            for (k = 0; k < n; k++)
            {
                if (AT[k] == times)
                    enqueue(k);
            }
            execute--;
        }
        if (RT[y] == 0)
        {
            completed++;
        }
        else
        {
            enqueue(y);
        }
        ready_time[x] = times;
        x++;
    }
    printf("Gantt Chart:\n");
    for (int m = 0; m < z; m++)
    {
        printf("|\tP%d\t", ready[m] + 1);
    }
    printf("|\n");
    printf("0\t");
    for (int m = 0; m < x; m++)
    {
        printf("\t%d\t", ready_time[m]);
    }
    for (i = 0; i < n; i++)
    {
        TT[i] = CT[i] - AT[i];
        avgtat += TT[i];
        WT[i] = TT[i] - BT[i];
        avgwt += WT[i];
    }
    printf("\n\n");
    printf("PID\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", PID[i], AT[i], BT[i], CT[i], WT[i], TT[i]);
    }
    avgtat /= n, avgwt /= n;
    printf("\nAverage TurnAroundTime=%f\nAverage WaitingTime=%f", avgtat, avgwt);
    return 0;
}