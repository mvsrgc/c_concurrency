#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int primes[10] = {2,3,5,7,11,13,17,19,23,29};

void* routine(int* num) {
    printf("%d ", *num);
}

int main(int argc, char const *argv[])
{
    pthread_t th[10];
    for (size_t i = 0; i < 10; i++)
    {
        if (pthread_create(&th[i], NULL, &routine, &primes[i]) != 0) {
            perror("Failed to create thread.");
        }
    }

    for (size_t i = 0; i < 10; i++)
    {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread.");
        }
    }
    
    return 0;
}
