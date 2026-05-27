// SCAN Disk Scheduling Algorithm Implementation in C
#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[50], n, head, total = 0, disk_size;
    
    printf("Enter no of requests: ");
    scanf("%d", &n);
    
    // FIX 1: Added loop to correctly read all requests
    printf("Enter the requests:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }
    
    printf("Enter the initial position of head: ");
    scanf("%d", &head);
    
    printf("Enter Disk size: ");
    scanf("%d", &disk_size);
    
    // FIX 2: Fixed sorting loop boundary condition (j < n)
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(req[i] > req[j]) {
                int temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    // FIX 3: Find the precise index where head splits the sorted requests
    int pos = 0;
    while(pos < n && head >= req[pos]) {
        pos++;
    }

    printf("\nMovement of disk head (Assuming High direction):\n");
    printf("%d -> ", head);

    // STEP 1: Move from head position up to the high end of the disk array
    for(int i = pos; i < n; i++) {
        printf("%d -> ", req[i]);
        total += abs(req[i] - head);
        head = req[i];
    }
    
    // FIX 4: The elevator must hit the physical boundary of the disk!
    // If there are still requests remaining on the lower side, hit max disk edge
    if(pos > 0) {
        int max_edge = disk_size - 1;
        printf("%d -> ", max_edge);
        total += abs(max_edge - head);
        head = max_edge;
        
        // STEP 2: Reverse direction and service remaining lower elements backwards
        for(int i = pos - 1; i >= 0; i--) {
            printf("%d", req[i]);
            total += abs(req[i] - head);
            head = req[i];
            if(i > 0) printf(" -> ");
        }
    }

    printf("\n\nTotal seek time: %d\n", total);
    return 0;
}





