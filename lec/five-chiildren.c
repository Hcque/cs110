#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

static const int kSignalFailed = 1;
static const int kForkFailed = 2;
static const int kWaitFailed = 3;

static const size_t kNumChildren = 5;
static size_t numChildrenDonePlaying = 0;
static void reapChild(int sig) {
    //while (1) {
        pid_t pid = waitpid(-1, NULL, WNOHANG);
        if (pid <= 0) return;
        numChildrenDonePlaying++;
    //}
    printf("num of children Done: %zu\n", numChildrenDonePlaying);
}

int main(int arhc, char *argv[]) {
    printf("let my five children play while I take a nap.\n");
    signal(SIGCHLD, reapChild);
    for (size_t kid = 1; kid <= 5; kid++) {
        if (fork() == 0) {
            //sleep(3 * kid);
            sleep(3);
            printf("Child %zu time ... return to dad. \n", kid);
            return 0;
        }
    }
    while (numChildrenDonePlaying < kNumChildren) {
        printf("At least one child is still playing, so dad nods off.\n");
        sleep(5);
        printf("dad waken up\n");
    }
    printf("All children accounted, good job dad!\n");
    return 0;

}


