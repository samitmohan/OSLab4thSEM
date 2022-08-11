// priority scheduling
#include <stdio.h>
int main()
{
    int temp, n, p[10], bt[10], priority[10], wt[10], tat[10], avgwt, avgtat, i;
    printf("Enter process : ");
    scanf("%d", &n);
    printf("Enter process(BT) : time priority : ");
    for (i = 0; i < n; i++)
    {
        printf("Process no %d", i + 1);
        scanf("%d %d", &bt[i], &priority[i]);
        p[i] = i + 1;
    }

    for (i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (priority[i] < priority[j])
            {
                // priority[i], priority[j] = priority[j], priority[i]
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;
                // bt[i], bt[j] = bt[j], bt[i]
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }
    wt[0] = 0;
    avgwt = 0;
    tat[0] = bt[0];
    avgtat = tat[0];
    for (i = 1; i < n; i++)
    {
        wt[i] = tat[i - 1];
        avgwt += wt[i];
        tat[i] = wt[i] + bt[i];
        avgtat += tat[i];
    }
    printf("\n \n Job \t BT \t WT \t TAT \t Priority \n");
    for (i = 0; i < n; i++)
    {
        printf("\n %d \t \t %d \t \t %d \t \t %d \t \t %d \n", p[i], bt[i], wt[i], tat[i], priority[i]);
    }
    avgwt = (float)avgwt / n;
    avgtat = (float)avgtat / n;
    printf("Average WT : %d \n", avgwt);
    printf("Average TAT : %d \n", avgtat);
}