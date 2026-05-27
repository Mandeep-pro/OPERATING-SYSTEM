// SSTF Disk Scheduling Algorithm Implementation in C

#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, n, head, total = 0;
    int req[50], visited[50];
    
    printf("Enter no of disk requests: ");
    scanf("%d", &n);
    
    printf("Enter the disk requests:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
        visited[i] = 0;
    }
    
    printf("Enter the initial position of head: ");
    scanf("%d", &head);
    
    printf("\nMovement of disk head:\n"); 
    
    for(i = 0; i < n; i++) {
        int min = 9999;
        int pos = -1;
        
        for(j = 0; j < n; j++) {
            if(!visited[j]) {
                // FIX 2: Changed req[i] to req[j] so it actually checks every request
                int distance = abs(head - req[j]); 
                
                if(distance < min) {
                    min = distance;
                    pos = j;
                }
            }
        }
        if(pos != -1) {
            printf("Move from %d to %d with distance %d\n", head, req[pos], min);
            total += min;   
            head = req[pos];
            visited[pos] = 1;
        }
    } 
    printf("\nTotal seek time = %d\n", total);
    return 0;
}
