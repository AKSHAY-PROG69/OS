#include <stdio.h>

int main()
{
    int n, i, j, time = 0, completed = 0, highest;
    int bt[20], rt[20], pr[20];
    int wt[20] = {0}, tat[20] = {0};

    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    if (n <= 0 || n > 20)
    {
        printf("Invalid number of processes.\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter Burst Time of P%d: ", i + 1);
        scanf("%d", &bt[i]);

        printf("Enter Priority of P%d (smaller number = higher priority): ", i + 1);
        scanf("%d", &pr[i]);

        rt[i] = bt[i];
    }

    while (completed < n)
    {
        highest = -1;

        for (i = 0; i < n; i++)
        {
            if (rt[i] > 0 && (highest == -1 || pr[i] < pr[highest]))
            {
                highest = i;
            }
        }

        if (highest == -1)
            break;

        rt[highest]--;
        time++;

        if (rt[highest] == 0)
        {
            completed++;
            tat[highest] = time;
            wt[highest] = tat[highest] - bt[highest];

            avgWT += wt[highest];
            avgTAT += tat[highest];
        }
    }

    printf("\nProcess\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n",
               i + 1, pr[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", avgWT / n);
    printf("Average Turnaround Time = %.2f\n", avgTAT / n);

    return 0;
}