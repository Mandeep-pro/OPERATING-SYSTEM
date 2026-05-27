// FCFS Disk Scheduling Algorithm Implementation in C   

#include <stdio.h>
int main() {
    int n, twt = 0, ttat = 0, current_wt = 0;
    printf("Enter no of processes: ");
    scanf("%d", &n);

    int bt[n];
    printf("Enter burst times:\n");
    for (int i = 0; i < n; i++) scanf("%d", &bt[i]);

    printf("\nProcess\tBurst\tWaiting\tTAT\n");
    for (int i = 0; i < n; i++) {
        int tat = current_wt + bt[i];
        twt += current_wt;
        ttat += tat;
        
        printf("%d\t%d\t%d\t%d\n", i + 1, bt[i], current_wt, tat);
        current_wt += bt[i]; // Next process waits for this one to finish
    }
    printf("\nAvg WT: %.2f\nAvg TAT: %.2f\n", (float)twt / n, (float)ttat / n);
    return 0;
}
