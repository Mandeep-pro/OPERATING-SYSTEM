// look.c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, total = 0, pos = 0;
    printf("Enter no of requests, requests, and initial head:\n");
    scanf("%d", &n);
    int req[n];
    for(int i = 0; i < n; i++) scanf("%d", &req[i]);
    scanf("%d", &head);

    // 1. Sort the requests (Bubble Sort)
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if(req[i] > req[j]) { int t = req[i]; req[i] = req[j]; req[j] = t; }

    // 2. Find the first request >= head
    while(pos < n && req[pos] < head) pos++;

    printf("\nMovement: %d", head);

    // 3. LOOK High Direction: Service requests upwards
    for(int i = pos; i < n; i++) {
        total += abs(req[i] - head);
        printf(" -> %d", req[i]);
        head = req[i];
    }

    // 4. LOOK Reversāe Direction: Service remaining requests downwards
    for(int i = pos - 1; i >= 0; i--) {
        total += abs(req[i] - head);
        printf(" -> %d", req[i]);
        head = req[i];
    }

    printf("\nTotal seek time = %d\n", total);
    return 0;
}
