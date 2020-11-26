#include <sys/time.h>
#include <stdio.h>
#include "philo_one.h"

int counter; 
pthread_mutex_t lock;

void *dosomething(void *arg)
{
    pthread_mutex_lock(&lock);

    unsigned long i = 0;
    counter += 1;
    
    printf("\n%d\n", (int)pthread_self());
   printf("\n Job %d started\n", counter);
    for (i = 0; i <(0xFFFFFFF); i++);
    printf("\n Job %d finished \n", counter);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    // time_stamp();
    int i = 0;
    pthread_t tid[5];
    int err;

    pthread_mutex_init(&lock, NULL);

    while (i < 2){
        err = pthread_create(&(tid[i]), NULL, &dosomething, NULL);
        // printf("%d\n", (int)(tid[i] = pthread_self()));
        if (err != 0)
            printf("\n can't create thread: [%s]\n", strerror(err));
        i++;
        // sleep(1);
    }
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_mutex_destroy(&lock);
    return (0);
}