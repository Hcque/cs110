#include <stdio.h>
#include <stdlib.h> // for exit
#include <stdarg.h> // for va_list, etc.
#include <sys/stat.h> // for stat
#include <string.h> // for strlen, strcmp, strcpy
#include <assert.h>
#include <dirent.h> // for DIR, struct dirent

static const size_t kMaxPath = 1024;

static void listMatches(char path[], size_t length, const char *name) {

    
}

int main(int argc, char *argv[]) {
    assert(argc == 3);
    const char *directory = argv[1];
    struct stat st;
    lstat(directory, &st);
    assert(S_ISDIR(st.st_mode));
    //printf("%d\n", st.st_mode);

    const char *pattern = argv[2];

    return 0;
}

