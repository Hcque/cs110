#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

typedef struct subprocess_t {
    pid_t pid;
    int supplyfd;
} subprocess_t;

subprocess_t subprocess(const char *command) {
    int fds[2];
    pipe(fds);
    subprocess_t process = { fork(), fds[1] };
    if (process.pid == 0) {
        close(fds[1]);
        dup2(fds[0], STDIN_FILENO);
        close(fds[0]);
        char *args[] = {"/bin/sh", "-c", (char*)command, NULL};
        execvp(args[0], args);
    }
    close(fds[0]);
    return process;
}

int main (int argc, char *argv[]) {
    subprocess_t sp = subprocess("/usr/bin/sort");
    const char *words[] = {
        "felicity", "umbrage", "susurration", "halyon",
        "pulchritude", "ablution", "samnolent", "indefatigable"
    };
    for (size_t i = 0; i < sizeof(words) / sizeof(words[0]); i++) {
        dprintf(sp.supplyfd, "%s\n", words[i]);
    }
    close(sp.supplyfd);
    int status;
    pid_t pid = waitpid(sp.pid, &status, 0);
    return pid == sp.pid && WIFEXITED(status) ? WEXITSTATUS(status) : -100;

}

