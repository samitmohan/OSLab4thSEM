#include <stdio.h>
int req[100][100];
int alloc[100][100];
int avail[100];
int n, r;
void input();
void show();
void cal();
int main()
{
    int i, j;
    printf("DDL ALGO\n");
    input();
    show();
    cal();
    return 0;
}

void input()
{
    int i, j;
    printf("Enter number of processes \t");
    scanf("%d", &n);
    printf("Enter number of resource instances \t");
    scanf("%d", &r);
    printf("Enter required matrix \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < r; j++)
        {
            scanf("%d", &req[i][j]);
        }
    }
    printf("Enter allocation matrix \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < r; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }
}

void show()
{
    int i, j;
    printf("Process Allocation");
    for (i = 0; i < n; i++)
    {
        printf("\n P %d \t", i + 1);
        for (j = 0; j < r; j++)
        {
            printf("%d", alloc[i][j]);
        }
        printf("\t");
        for (j = 0; j < r; j++)
        {
            printf("%d", req[i][j]);
        }
        printf("\t");
        if (i == 0)
        {
            for (j = 0; j < r; j++)
            {
                printf("%d", avail[j]); // only 1 process
            }
        }
    }
}

// main
void cal()
{
    int finish[100], temp, need[100][100], flag = 1, k, c = 0;
    int dead[100];
    int safe[100];
    int i, j;
    for (i = 0; i < n; i++)
    {
        finish[i] = 0; // initially
    }
    while (flag)
    {
        flag = 0;
        for (i = 0; i < n; i++)
        {
            int c = 0;
            for (j = 0; j < r; j++)
            {
                if ((finish[i] == 0) && (req[i][j] < avail[j]))
                {
                    c++; // allot
                    if (c == r)
                    {
                        for (k = 0; k < n; k++)
                        {
                            avail[k] += alloc[i][j];
                            finish[i] = 1;
                            flag = 1;
                        }
                    }
                }
                if (finish[i] == 1)
                {
                    i = n;
                }
            }
        }
    }
    // check for dead state
    j = 0;
    flag = 0;
    for (i = 0; i < n; i++)
    {
        if (finish[i] == 0)
        {
            dead[j] = 1;
            j++;
            flag = 1;
        }
    }
    // if still in dl
    if (flag == 1)
    {
        printf("System is in DL");
        for (i = 0; i < j; i++)
        {
            printf("%d \t", dead[i]);
        }
    }
    else
    {
        printf("No deadlock \n");
    }
}