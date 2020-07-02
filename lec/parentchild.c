#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    srandom(time(NULL));
    printf("I am unique,print once.\n");
    pid_t pid = fork();
    int parent = pid != 0;
    if ((random() % 2 == 0) == parent) sleep(1);
    if (parent) waitpid(pid, NULL, 0);
    printf("I get printed twice (this one is from %s)\n", parent ? "parent" : "child");
    return 0;

}

