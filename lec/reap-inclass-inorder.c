#include <unistd.h> // for fork
#include <stdio.h>
#include <errno.h>
#include <assert.h>
#include <sys/wait.h>

int main() {
   int children[8];
   for (size_t i = 0; i < 8; i++) {
        if (( children[i] = fork()) == 0) exit(110+i);

   }
   for (int i = 0; i < 8; i++) { 
       int status;
       pid_t pid = waitpid(children[i], &status, 0);
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

