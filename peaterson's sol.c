// Peaterson's sol
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int shared = 1;
int flag[2];
int turn = 0;
void* func1(void* arg){
    flag[0] = 1;
    turn = 1;
    while(flag[1] == 1 && turn == 1);
    shared++;
    flag[0] = 0;
    return NULL;
}

void* func2(void* arg){
    flag[1] = 1;
    turn = 0;
    while(flag[1] == 0 && turn == 0);
    shared++;
    flag[1] = 0;
    return NULL;
}

int main(){
    pthread_t t1, t2;

    pthread_create(&t1, NULL, func1, NULL);
    pthread_create(&t2, NULL, func2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("\nFinal value %d\n", shared);
    return 0;
}
