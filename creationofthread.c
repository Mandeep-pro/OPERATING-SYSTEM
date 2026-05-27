// creation of thread in c
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
void*run_thread(void* arg){
    printf("\n Inside thr main thread \n");
    for(int i = 20; i<25; i++){
        printf("%d ",i);
        sleep(1);
    }
    return NULL;
}

int main(){
    pthread_t thread;
    pthread_create(&thread,NULL, run_thread, NULL);

    pthread_join(thread, NULL);

     printf("\n Back to the main memory\n");
     return 0;
}
