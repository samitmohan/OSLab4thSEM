// FCFS scheduling
#include <stdio.h>
int main()
{
    int bt[20], wt[20], tat[20], i, n;
    float wtavg, tatavg;
    printf("Enter number of processes : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter BT for process %d", i);
        scanf("%d", &bt[i]);
    }
    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }
    printf("\t Processes \t BT \t WT \t TAT");
    for (i = 0; i < n; i++)
    {
        printf("\n \t p %d \t \t %d \t \t %d \t \t %d", i, bt[i], wt[i], tat[i]);
    }
    printf("Average wt : %f", wtavg);
    printf("Average tat : %f", tatavg);
}
