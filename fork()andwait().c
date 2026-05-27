#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main() {
 pid_t q;
 printf("before forks \n");
 q = fork();
 if (q < 0) {
 printf("error\n");
 } 

 else if (q == 0) {
 printf("i am a child having pid %d\n", getpid());
 printf("my parent's pid is %d\n", getppid());
 }
 else {
 wait(NULL); // parent waits for child to finish
 printf("my child's pid is %d\n", q);
 printf("i am parent having id %d\n", getpid());
 }
 printf("common\n");
 return 0;
} 


