// Fifo Disk Scheduling Algorithm Implementation in C   

#include <stdio.h>

int main() {
    int n;
    int head;
    int total = 0;

    printf("Enter no of disk requests: ");
    scanf("%d", &n);

    // FIX 1: Allocate the array ONLY after 'n' has a known value
    int req[n]; 

    printf("Enter the disk requests:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    printf("Enter the initial position of head: ");
    scanf("%d", &head);

    printf("\nMovement of Disk Head:\n");
    printf("%d -> ", head); // Shows where the head started

    for(int i = 0; i < n; i++) {
        int move;
        if(head > req[i]) {
            move = head - req[i];
        } else {
            move = req[i] - head;
        }
        
        // FIX 2: Fixed the '+=' spacing typo
        total += move; 
        head = req[i];
        
        printf("%d", head);
        if (i < n - 1) printf(" -> "); // Makes the path look nice
    }

    // FIX 3: Moved outside the loop to print the final total once
    printf("\n\nTotal seek time: %d\n", total); 
    
    return 0;
}
