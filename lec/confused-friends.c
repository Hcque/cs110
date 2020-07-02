#include <pthread.h>
#include <stdio.h> // printf is threads safe

static const char *kFriends[] = {
    "Jack", "Mi", "Luis", "Richard", "Jor"
    };
static const size_t kNumFriends = sizeof(kFriends) / sizeof(kFriends[0]);

static void *meetup(void *args) {
    const char *name = kFriends[*(size_t*)args];
    printf("%s\n",(char*) name);
    printf("I am %s meet you\n", name);
    return NULL;
}


int main(int argc, char argv[]) {
    printf("lets hear %zu frineds.\n", kNumFriends);
    pthread_t friends[kNumFriends];
    for (size_t i = 0; i < kNumFriends; i++) {
        pthread_create(&friends[i], NULL, meetup, &i);
    }
    for (size_t i = 0; i < kNumFriends; i++) {
        pthread_join(friends[i], NULL);
    }
    printf("is everyone do it?\n");
    return 0;

}




