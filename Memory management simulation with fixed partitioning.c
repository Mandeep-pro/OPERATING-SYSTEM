// Memory management simulation with fixed partitioning
#include <stdio.h>
int main()
{
 int ms, bs, nob, ef, n, mp[10], tif = 0;
 int i, p =0;
 printf("Enter the memory size: "); 
    scanf("%d", &ms);
    printf("Enter the block size: ");
    scanf("%d", &bs);
    nob = ms / bs;
    printf("Enter the no of processes: ");
    scanf("%d", &n);
    printf("Enter the memory required for the processes: \n");  
    for (i = 0; i < n; i++)
    {
        scanf("%d", &mp[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (mp[i] > bs)
        {
            printf("Process %d cannot be allocated\n", i + 1);
        }
        else if (p < nob)
        {
            ef = bs - mp[i];
            tif += ef;
            printf("Process %d allocated to block %d with internal fragmentation %d\n", i + 1, p + 1, ef);
            p++;
        }
        else
        {
            printf("No more blocks available for process %d\n", i + 1);
        }
    }
    printf("Total internal fragmentation: %d\n", tif);
    return 0;
}
