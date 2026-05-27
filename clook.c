// CLOOK Disk Scheduling Algorithm Implementation in C
#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[50], n, head, total = 0, disk_Size;
    
    printf("Enter no of requests: ");
    scanf("%d", &n);
    
    printf("Enter the requests: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }
    
    printf("Enter the initial position of head: ");
    scanf("%d", &head);
    
    printf("Enter disk size: ");
    scanf("%d", &disk_Size);

    // 1. Sort the request array (Bubble Sort)
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(req[i] > req[j]) {
                int temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    // 2. Find the first request greater than the head position
    int pos = 0;
    for(int i = 0; i < n; i++) {
        if(req[i] >= head) {
            pos = i;
            break;
        }
    }

    printf("\nMovement of disk head (Assuming High direction):\n");
    printf("%d", head); // Print starting point

    // 3. Serve requests from head position to the highest request
    for(int i = pos; i < n; i++) {
        int move = abs(req[i] - head);
        total += move;
        printf(" -> %d", req[i]);
        head = req[i];
    }

    // 4. C-LOOK Wrap Around: Jump directly to the lowest request and serve up to 'pos'
    for(int i = 0; i < pos; i++) {
        int move = abs(req[i] - head);
        total += move;
        printf(" -> %d", req[i]);
        head = req[i];
    }

    printf("\n\nTotal seek time = %d\n", total); 
    return 0;
}
