#include <unistd.h> // for fork
#include <stdio.h>
#include <errno.h>
#include <assert.h>
#include <sys/wait.h>

int main() {
   for (size_t i = 0; i < 8; i++) {
        if (fork() == 0) exit(110+i);

       int status;
       pid_t pid = waitpid(-1, &status, 0);
       if (pid == -1) {assert(errno == ECHILD); break;}
       if (WIFEXITED(status)) {
           printf("child %d exit: status %d\n", pid, WEXITSTATUS(status));
       }
       else {
           printf("child %d exit abnormly\n", pid);
       }
   }
   return 0;
}

