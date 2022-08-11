// how two process thread share variable using semaphores

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t *mux; // int mutex

void *thread(void *arg) {
    // wait
    sem_wait(&mux);
    printf("Entered \n");
    // cs
    sleep(4);
    // signal
    printf("Just exiting \n");
    sem_post(&mux);
}

int main() {
    sem_init(&mux,0,1); // binary semaphore
    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread, NULL);
    sleep(2);
    pthread_create(&t2, NULL, thread, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    sem_destroy(&mux);
    return 0;
}