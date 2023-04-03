#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void* roll_dice() {
    int value = rand() % 6 + 1;
    int* result = malloc(sizeof(int));
    *result = value;

    return (void *)result;
}

int main(int argc, char* argv[]) {
    pthread_t th;
    srand(time(NULL));

    if (pthread_create(&th, NULL, &roll_dice, NULL) != 0) {
        return 1;
    }

    int* return_value = 0;
    if (pthread_join(th, (void**) &return_value) != 0) {
        return 2;
    }
    printf("%d\n", *return_value);
    free(return_value);

    return 0;
}