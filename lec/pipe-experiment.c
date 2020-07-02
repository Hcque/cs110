#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int fds[2];
    pipe(fds);
    
    pid_t pid = fork();
    if (pid == 0) {
        close(fds[1]);
        char buffer[6];
        read(fds[0], buffer, sizeof(buffer));
        printf("read from the pipe: %s. \n", buffer);
        close(fds[0]);
        return 0;
    }

    // parent
    close(fds[0]);
    write(fds[1], "hello", 6);
    waitpid(pid, NULL, 0);
    close(fds[1]);
    return 0;
}
