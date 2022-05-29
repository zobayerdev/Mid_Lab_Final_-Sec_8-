#include <stdio.h>
int main ()
{
    int c[20], process[20], wt[20] = {0}, tat[20], i, j, n, total=0, pos,temp;
    float avg_wt = 0, avg_tat = 0, sum_wt = 0, sum_tat = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        printf("\nEnter the CPU Time of P%d: ", i+1);
        scanf("%d", &c[i]);
        process[i] = i+1;
    }


    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(c[i]>c[j])
            {
                temp=c[i];
                c[i]=c[j];
                c[j]=temp;

                temp=process[i];
                process[i]=process[j];
                process[j]=temp;
            }
        }
    }


    for(i=1; i<n; i++)
    {
        wt[i]=c[i-1]+wt[i-1];
    }

    for(i=0; i<n; i++)
    {
        tat[i]=c[i]+wt[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");
    for(i=0; i<n; i++)
    {
        tat[i]=c[i]+wt[i];
        total+=tat[i];
        printf("\np%d \t\t%d \t\t%d \t\t%d", process[i], c[i], wt[i], tat[i]);
    }


    for(i=0; i<n; i++)
    {
        sum_wt += wt[i];
        sum_tat += tat[i];
    }

    avg_tat = sum_tat/n;
    avg_wt = sum_wt/n;

    printf("\n\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f", avg_tat);

    printf("\n\nGantt Chart:\n\n|");
    for(i = 0; i < n; i++)
    {
        printf(" P%d     |", i+1);
    }

    printf("\n0");
    for(i = 0; i < n; i++)
    {
        printf("       %d", tat[i]);
    }
}
