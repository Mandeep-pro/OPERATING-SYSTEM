// LFU Page Replacement Algorithm in C
#include <stdio.h>

int main() {
    int n, f, fault = 0;
    printf("Pages: "); scanf("%d", &n); int seq[n];
    for(int i=0; i<n; i++) scanf("%d", &seq[i]);
    printf("Frames: "); scanf("%d", &f);
    int frame[f], freq[f];
    for(int i=0; i<f; i++) { frame[i] = -1; freq[i] = 0; }

    for(int i=0; i<n; i++) {
        int found = 0, pos = -1;
        for(int j=0; j<f; j++) {
            if(frame[j] == seq[i]) { found = 1; pos = j; break; }
            if(frame[j] == -1 && pos == -1) pos = j;
        }
        if(!found) {
            fault++;
            if(pos == -1) {
                pos = 0;
                for(int j=1; j<f; j++) if(freq[j] < freq[pos]) pos = j;
            }
            freq[pos] = 0;
        }
        frame[pos] = seq[i]; freq[pos]++;
    }
    printf("Faults: %d\n", fault);
}
