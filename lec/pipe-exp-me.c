#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
   int fds[2];
   pipe(fds);
   pid_t pid = fork();
   if (pid == 0) { // child
       close(fds[1]);
       dup2(STDOUT_FILENO, fds[0]);
       char buf[16];
       int n = read(fds[0], buf, sizeof(buf));
       //write(1, buf, n);
       //printf("in private buffer: %s\n", buf);
       close(fds[0]);
       exit(0);
   }
   write(fds[1], "hello\nagood\n", 13);
   waitpid(pid, NULL, 0);
   return 0;
}
