#include<stdbool.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>

static const int kWrongArgumentCount = 1;

int main(int argc, char *argv[]) {
    int 
    int fdout = open(argv[1], O_WRONLY | O_CREAT | O_EXCL, 0644);
    while (true) {
        char buffer[1024];
        ssize_t bytesRead = read(stdin, buffer, sizeof(buffer));
        if (bytesRead == 0) break;
        ssize_t bytesWritten = 0;
        while (bytesWritten < bytesRead) {
            bytesWritten += write(fdout, buffer, bytesRead - bytesWritten);
        }
    }
    close(fdout);
    return 0;
}

                



                

