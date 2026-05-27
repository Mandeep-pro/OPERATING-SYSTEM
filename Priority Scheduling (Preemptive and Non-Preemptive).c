// PriorityScheduling(PreemptiveandNon-Preemptive).c
#include <stdio.h>

void simulate(int n, int pid[], int bt[], int pr[], int preemptive) {
    int rt[n], wt[n], tat[n], ct[n],  finished[n], t = 0, completed = 0;
    for (int i = 0; i < n; i++) { rt[i] = bt[i]; finished[i] = 0; }

    while (completed < n) {
        int idx = -1, hp = 9999;
        for (int i = 0; i < n; i++) {
            if (!finished[i] && pr[i] < hp && rt[i] > 0) { hp = pr[i]; idx = i; }
        }

        if (idx != -1) {
            if (preemptive) { rt[idx]--; t++; } 
            else { t += rt[idx]; rt[idx] = 0; } // Process run to completion if non-preemptive

            if (rt[idx] == 0) {
                finished[idx] = 1; completed++;
                ct[idx] = t; tat[idx] = t; wt[idx] = t - bt[idx];
            }
        } else t++;
    }

    printf("\n--- %s Priority Scheduling ---\nPid\tCT\tWT\tTAT\tPriority\n", preemptive ? "Preemptive" : "Non-Preemptive");
    for (int i = 0; i < n; i++) printf("P%d\t%d\t%d\t%d\t%d\n", pid[i], ct[i], wt[i], tat[i], pr[i]);
}

int main() {
    int n;
    printf("Enter the no. of processes: ");
    if (scanf("%d", &n) != 1) return 1;

    int pid[n], bt[n], priority[n];
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter burst time and priority for P%d: ", i + 1);
        scanf("%d %d", &bt[i], &priority[i]);
    }

    simulate(n, pid, bt, priority, 0); // 0 = Non-Preemptive
    simulate(n, pid, bt, priority, 1); // 1 = Preemptive
    return 0;
}
