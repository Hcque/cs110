/* -----------------------
 * Very simpe example basic threads functionality.
 */

#include <pthread.h>
#include <stdio.h> // printf is threads safe

static void *recharge(void *args) {
    printf("I recharge by spending time alone. \n");
    return NULL;
}

static const size_t kNumIntro = 6;
int main(int argc, char argv[]) {
    printf("let's hear from %zu introverts. \n", kNumIntro);
    pthread_t introverts[kNumIntro];
    for (size_t i = 0; i < kNumIntro; i++ ) {
        pthread_create(&introverts[i], NULL, recharge, NULL);
    }
    for (size_t i = 0; i < kNumIntro; i++ ) {
        pthread_join(introverts[i], NULL);
    }
    printf("Everyone is recharged.\n");
    return 0;


}




