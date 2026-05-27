// race condition using the thread and shared variable in c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int shared =1;

void* func1(void* arg){
    int x = shared;
    sleep(1);
    shared = x+1;
    return NULL;
}

void* func2(void* arg){
    int x = shared;
    sleep(1);
    shared = x-1;
    return NULL;
}

int main(){
    pthread_t t1, t2;

    pthread_create(&t1, NULL, func1, NULL);
    pthread_create(&t2, NULL, func2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("\nFinal value %d\n", shared);


}
