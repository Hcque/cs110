#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
static const char* kTrailing = "abcd";

int main() {
    printf("My process id is %d\n", getpid());

    for (int i = 0; i < 4; i++) {
        printf("%c\n", kTrailing[i]);
        fork();
}
    int status;
    waitpid(-1, &status, 0);

    return 0;
}

