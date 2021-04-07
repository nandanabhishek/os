#include <stdio.h>
#include <stdbool.h>


// Function to find the need of each process
void calculateNeed(int n, int m, int need[n][m], int max[n][m], int allot[n][m])
{
    // Calculating Need of each Process
    for (int i = 0 ; i < n ; i++)
        for (int j = 0 ; j < m; j++)

            // Need of instance = max instance - allocated instance
            need[i][j] = max[i][j] - allot[i][j];
}


// Function to find the system is in safe state or not
bool isSafe(int n, int m, int avail[m], int max[n][m], int alloc[n][m])
{
    int need[n][m];

    // Function to calculate need matrix
    calculateNeed(n, m, need, max, alloc);

    // Mark all processes as in finish
    bool finish[n];

    // To store safe sequence
    int safeSeq[n];

    // Make a copy of available resources
    int work[m];
    for (int i = 0; i < n ; i++)
        work[i] = avail[i];

    // While all processes are not finished
    // or system is not in safe state.
    int count = 0;
    while (count < n)
    {
        // Find a process which is not finish and
        // whose needs can be satisfied with current
        // work[] resources.
        bool found = false;
        for (int p = 0; p < n; p++)
        {
            // First check if a process is finished,
            // if no, go for next condition
            if (finish[p] == 0)
            {
                // Check if for all resources of
                // current P need is less
                // than work
                int j;
                for (j = 0; j < m; j++)
                    if (need[p][j] > work[j])
                        break;

                // If all needs of p were satisfied.
                if (j == m)
                {
                    // Add the allocated resources of
                    // current P to the available/work
                    // resources i.e.free the resources
                    for (int k = 0 ; k < m ; k++)
                        work[k] += alloc[p][k];

                    // Add this process to safe sequence.
                    safeSeq[count++] = p;

                    // Mark this p as finished
                    finish[p] = 1;

                    found = true;
                }
            }
        }

        // If we could not find a next process in safe
        // sequence.
        if (found == false)
        {
            printf("\n\n System is not in safe state !!!");
            return false;
        }
    }

    // If system is in safe state then
    // safe sequence will be as below
    printf("\n\n System is in safe state.\n Safe sequence is :\n");
    for (int i = 0; i < n-1 ; i++)
        printf(" P%d -> ", safeSeq[i]);
    printf(" P%d", safeSeq[n-1]);

    return true;
}


// Driver code
int main()
{
    int m; // m = Number of Resources
    int n; // n = Number of Processes
    int i, j; // for indexing purposes

    printf("\n Enter the total number of processes : ");
    scanf("%d", &n);

    printf("\n Enter the total number of resources : ");
    scanf("%d", &m);

    int alloc[n][m]; // stores the current amount of Resources alloc. to each processes
    int max[n][m]; // stores the max. amount of Resources req. for each processes
    int avail[m]; // stores the max. available Resources

    printf("\n Enter the current allocation of resources (R1, R2, ...., Rn) for each processes :\n\n");
    for(i=0; i<m; i++) {
        printf("\tR%d", i+1);
    }
    printf("\n");
    for(i=0; i<n; i++) {
        printf(" P%d :\t", i);
        for(j=0; j<m; j++) {
            scanf("%d", &alloc[i][j]);
        }

    }

    printf("\n Enter the maximum demand of resources(R1, R2, ....., Rn) for each processes :\n\n");
    for(i=0; i<m; i++) {
        printf("\tR%d", i+1);
    }
    printf("\n");
    for(i=0; i<n; i++) {
        printf(" P%d :\t", i);
        for(j=0; j<m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\n Enter the number of Maximum Available Resources (R1, R2, ...., Rn) :\n\n");
    for(i=0; i<m; i++) {
        printf("\t R%d :\t", i);
        scanf("%d", &avail[i]);
    }

    // Check system is in safe state or not
    isSafe(n, m, avail, max, alloc);

    return 0;
}

