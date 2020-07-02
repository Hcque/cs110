/**
  *File: mysystem.c
  */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

static int mysystem(const char *command) {
   pid_t pid = fork();
   if (pid == 0) {
       char* arguements[] = {"/bin/sh", "-c",(char*)command, NULL};
       execvp(arguements[0], arguements);
       printf("failed to invoke sh.\n");
       exit(0);
   }
   int status;
   waitpid(pid, &status, 0);
   return WIFEXITED(status) ? 100 : -100;

}

int main(int argc, char* argv[]) {
    char cmd[1024];
    while (1) {
        printf(">");
        fgets(cmd, sizeof(cmd), stdin);
        if (feof(stdin)) break;
        cmd[strlen(cmd)-1] = '\0';
        printf("%s\n", cmd);
        printf("retun %d\n",mysystem(cmd));
    }
    return 0;
}
