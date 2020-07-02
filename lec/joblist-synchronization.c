#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static const int kForkFailed = 1;
static const int kExecFailed = 2;
static const int kWaitFailed = 4;
static const int kSignalFailed = 8;

static void reapProcesses(int sid) {
    while (1) {
        pid_t pid = waitpid(-1, NULL, WNOHANG);
        if (pid <= 0) break;
        printf("Job %d removed from the job list.\n", pid);

    }
}

char * const kArguments[] = {"date", NULL};
int main(int argc, char *argv[]) {
    signal(SIGCHLD, reapProcesses);
    for (size_t i = 0; i < 3; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            execvp(kArguments[0], kArguments);
        }
        //sleep(1);
        printf("job %d added to the job list.\n", pid);
    }
    return 0;
}

