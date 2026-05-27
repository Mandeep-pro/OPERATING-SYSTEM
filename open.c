#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int main() {
    int n, fd , fd1;
    char buf[50];
    fd = open("test.txt", O_RDONLY);
    n = read(fd,buf,10);
    fd1 = open("target.txt", O_APPEND | O_WRONLY | O_CREAT, 0644);
    write(fd1, buf , n);
    close(fd);
    close(fd1);

    return 0;

}
