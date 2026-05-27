// LRU Page Replacement Algorithm in C
#include <stdio.h>

int main() {
    int n, f, fault = 0;
    printf("Enter no of pages: ");   scanf("%d", &n);
    int seq[n];
    printf("Enter reference string: ");
    for(int i = 0; i < n; i++)       scanf("%d", &seq[i]);
    printf("Enter no of frames: ");  scanf("%d", &f);

    int frames[f], time[f];
    for(int i = 0; i < f; i++)       { frames[i] = -1; time[i] = -1; }

    for(int i = 0; i < n; i++) {
        int found = 0, pos = 0;
        
        // Match page, locate empty frame, or find the oldest timestamp all at once
        for(int j = 0; j < f; j++) {
            if(frames[j] == seq[i])  { found = 1; pos = j; break; }
            if(time[j] < time[pos])  pos = j; 
        }
        
        if(!found) fault++;
        frames[pos] = seq[i];
        time[pos] = i; // Save current cycle timestamp
    }
    printf("\nTotal Page Faults = %d\n", fault);
    return 0;
}
