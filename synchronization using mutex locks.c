// Synchronization using Mutex Locks in C
#include <stdio.h>
#include <pthread.h>

int shared = 1;
pthread_mutex_t l;

void* func1(void* args){
    pthread_mutex_lock(&l);
    shared++;
    pthread_mutex_unlock(&l);
    return NULL;
}
void* func2(void* args){
    pthread_mutex_lock(&l);
    shared--;
    pthread_mutex_unlock(&l);
    return NULL;
}

int main(){
    pthread_t t1, t2;
    pthread_mutex_init(&l, NULL); // mistake ssudhar ni hai 

    pthread_create(&t2, NULL , func2, NULL);
    pthread_create(&t1, NULL , func1, NULL);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("\nFinal value %d\n", shared);
    pthread_mutex_destroy(&l);


}
