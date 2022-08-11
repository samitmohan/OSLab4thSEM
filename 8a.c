// sjf
#include <stdio.h>
int main()
{
    int bt[10], wt[20], p[20], i, j, total = 0, pos, temp, tat[20], n;
    float avgwt, avgtat;
    printf("Enter number of process : ");
    scanf("%d", &n);
    printf("Enter BT : ");
    for (i = 0; i < n; i++)
    {
        printf("Process%d : ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }

    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (bt[j] < bt[pos])
            {
                pos = j; // update to min
            }
        }
        // bt[i], bt[pos] = bt[pos], bt[i]
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
        // p[i], p[pos] = p[pos], p[i];
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }
    wt[0] = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
        {
            wt[i] += bt[j];
            total += wt[i];
        }
        avgwt = (float)total / n;
        total = 0; // reset
        printf("\n Process \t BT \t WT \t TAT");
        for (i = 0; i < n; i++)
        {
            tat[i] = bt[i] + wt[i];
            total += tat[i];
            printf("\np %d \t %d \t %d \t %d", p[i], bt[i], wt[i], tat[i]);
        }
        avgtat = (float)total / n;
        printf("Average WT : %f \n", avgwt);
        printf("Average TAT : %f \n", avgtat);
    }
}