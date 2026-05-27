// Round Robin Scheduling Algorithm Implementation in C 
#include <stdio.h>

int main(){
    int n, i,time_quantum;
    printf("Enter no of processes : ");
    scanf("%d",&n);
    int bt[n],rt[n],wt[n], tat[n];
    printf("Enter burst time of the processes : ");
    for(i=0;i<n;i++){
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
    }
    printf("Enter time quantum : ");
    scanf("%d",&time_quantum);

    int t=0;
    while(1){
        int done=1;
        for(i=0;i<n;i++){
            if(rt[i]>0){
                done=0;
                if(rt[i]>time_quantum){
                    t+=time_quantum;
                    rt[i]-=time_quantum;
                }else{
                    t+=rt[i];
                    wt[i]=t-bt[i];
                    rt[i]=0;
                }
            }
        }
        if(done==1){
            break;
        }
    }
    for(i=0;i<n;i++){
        tat[i]=bt[i]+wt[i];
    }
    int total_wt=0,total_tat=0;
    for(i=0;i<n;i++){
         total_wt+=wt[i];
         total_tat+=tat[i];
    }
    float avg_wt =(float)total_wt/n;
    float avg_tat =(float)total_tat/n;  
    printf("total wt : %d\n",total_wt);
    printf("Avg wt : %f",avg_wt);
    printf("total tat : %d\n",total_tat);
    printf("Avg tat : %f",avg_tat);
    return 0;
}
