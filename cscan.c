// CSCAN Disk Scheduling Algorithm Implementation in C
#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[50], n, head, total = 0, disk_size;
    
    printf("Enter no of requests: ");
    
    if (scanf("%d", &n) != 1) return 1; 
    
    printf("Enter the requests: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }
    
    printf("Enter the initial position of head: ");   
    scanf("%d", &head);
    
    printf("Enter disk size: ");
    scanf("%d", &disk_size);
    
    // 2. Sort the array
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(req[i] > req[j]) {
                int temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }
    printf("\nMovement of disk head (Assuming High direction):\n");
    printf("%d", head); // Print starting point for clarity

    int pos = 0; 
    for(pos = 0; pos < n; pos++) {
        if(req[pos] >= head) { // Changed to >= to properly account for head positions
            break;
        }
    }
    
    for(int i = pos; i < n; i++) {
        printf(" -> %d", req[i]);
        total += abs(req[i] - head);
        head = req[i];
    }
    
    // 5. C-SCAN Requirement: Go all the way to the end boundary of the disk
    printf(" -> %d", disk_size - 1);
    total += abs((disk_size - 1) - head);
    head = disk_size - 1;
    
    // 6. C-SCAN Requirement: Jump immediately to the start boundary (0)
    printf(" -> 0");
    total += abs(head - 0);
    head = 0;
    
    // 7. Serve the remaining lower requests
    for(int i = 0; i < pos; i++) {
        printf(" -> %d", req[i]);
        total += abs(req[i] - head);
        head = req[i];
    }
    
    printf("\n\nTotal seek time = %d\n", total);
    return 0;
} 
