#include <unistd.h>
int main() {
 int a[30];
 int n = read(0, a, 10);
 write(1, a, n);
 return 0;
} 
