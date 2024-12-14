

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
    int pid;
    int num = 1;
    pid = fork();
    if (pid > 0) {
        num++;
        printf("in parent:num:%d addr:%x\n", num, &num);
    } else if (pid == 0) {
        printf("in child:num:%d addr:%x\n", num, &num);
    }
}