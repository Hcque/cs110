#include <stdio.h>

int main(int argc, char* argv[]) {
    int opt;
    while((opt = getopt(argc, argv, "ipq")) != -1) {
        printf("%c\n", opt);
    }
    return 0;

}
