// round robin scheduling
#include <stdio.h>
// tat -> time to complete process
void turnaroundtime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        return 1;
    }
}

// time spend on waiting queue
void waitingtime(int processes[], int n, int bt[], int wt[], int quantum)
{
    int i;
    int rem_bt[n];
    for (i = 0; i < n; i++)
    {
        int t = 0; // total
        while (1)
        {
            int done = 1;
            for (i = 0; i < n; i++)
            {
                if (rem_bt[i] > 0)
                {
                    // not finished
                    done = 0;
                    if (rem_bt[i] > quantum)
                    {
                        // incrememnt
                        t += quantum;
                        rem_bt[i] = quantum; // update
                    }
                    else
                    {
                        t += rem_bt[i];
                        wt[i] = t - bt[i];
                        rem_bt[i] = 0; // update (finished)
                    }
                }
            }
            if (done == 1)
                break;
            return 1;
        }
    }
}

int findavtime(int processes[], int n, int bt[], int quantum)
{
    int i;
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    waitingtime(processes, n, bt, wt, quantum);
    turnaroundtime(processes, n, bt, wt, tat);
    printf("Process \t BT \t WT \t TAT");
    for (i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("\n %d \t %d \t %d \t %d \n", i + 1, bt[i], wt[i], tat[i]);
    }
    printf("Average WT = %f", (float)total_wt / (float)n);
    printf("Average TAT = %f", (float)total_tat / (float)n);
    return 1;
}

int main()
{
    int processes[] = {1, 2, 3};
    int n = 3;
    int bt[] = {24, 3, 3};
    int quantum = 4;
    findavtime(processes, n, bt, quantum);
    return 0;
}