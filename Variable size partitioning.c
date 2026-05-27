// Variable size partitioning.
#include <stdio.h>
int main(){
    int ms, mp[10], n, p = 0, ef, tif = 0;
    printf("Enter the memory size: ");
    scanf("%d", &ms);
    printf("Enter the no of processes: ");
    scanf("%d", &n);
    printf("Enter the memory required for the processes: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &mp[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (mp[i] > ms)
        {
            printf("Process %d cannot be allocated\n", i + 1);
        }
        else
        {
            ef = ms - mp[i];
            tif += ef;
            printf("Process %d allocated with internal fragmentation %d\n", i + 1, ef);
            ms -= mp[i];
        }
    }
    printf("Total internal fragmentation: %d\n", tif);
    return 0;
}
