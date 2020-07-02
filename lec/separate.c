#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    printf("before\n");
    pid_t pid = fork();
    printf("after\n");

    if (pid == 0) {
        printf("i am the child\n");
        int *a = NULL;
        *a = 5;
        return 110;
    }
    int status;
    waitpid(pid, &status, 0);
    if (WIFEXITED(status)){
        printf("child exit with status %d\n", WEXITSTATUS(status));
    } else {
        printf("child terminaled abnormornly\n");
    }
    //printf("I am the parent atr last\n");
    return 0;


}

