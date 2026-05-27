// synchronization using semaphores

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int shared = 1;
sem_t s;

void* func1(void* arg){
    sem_wait(&s);
    shared++;
    sem_post(&s);
    return NULL;
}

void* func2(void* arg){
    sem_wait(&s);
    shared--;
    sem_post(&s);
    return NULL;
}

int main(){

    pthread_t t1, t2;
    sem_init(&s, 0,1);
    pthread_create(&t1, NULL, func1, NULL);
    pthread_create(&t2, NULL, func2, NULL);

    pthread_join(t1,NULL); 
    pthread_join(t1,NULL);

    printf("\n Final value : %d\n", shared);
    sem_destroy(&s);

}
