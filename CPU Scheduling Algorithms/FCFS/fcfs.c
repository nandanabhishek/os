#include<stdio.h>

// main function
int main()
{
    int n; // n = Total number of processes
    int bt[n]; // bt[] = Array for Burst Time
    int wt[n]; // wt[] = Array for Waiting Time
    int tat[n]; // tat[] = Array for Turnaround Time
    float av_wt=0, av_tat=0; // av_wt = Average Waiting Time, av_tat = Average Turnaround Time
    int i, j;

    printf("\n Enter total number of processes : ");
    scanf("%d",&n);

    printf("\n Enter Burst Time of each process :\n");
    for(i=0; i<n; i++) {
        printf(" P[%d] : ",i+1);
        scanf("%d",&bt[i]);
    }

    wt[0]=0;

    for(i=1; i<n; i++) {
        wt[i]=0;
        for(j=0; j<i; j++)
            wt[i] += bt[j];
    }

    printf("\n Process\t Burst Time\t Waiting Time\t Turnaround Time\n");

    for(i=0;i<n;i++)
    {
        tat[i] = bt[i] + wt[i];
        av_wt += wt[i];
        av_tat += tat[i];
        printf("\n P[%d] \t\t %d \t\t %d \t\t %d", i+1, bt[i], wt[i], tat[i]);
    }

    av_wt /= i;
    av_tat /= i;
    printf("\n\n Average Waiting Time : %.2f",av_wt);
    printf("\n Average Turnaround Time : %.2f\n",av_tat);

    return 0;
}
