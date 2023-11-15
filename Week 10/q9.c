// Using mutual exclusion to prevent race conditions

#include <stdio.h>
#include <pthread.h>

int global_total = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *add_50000_to_counter(void *data) {
    for (int i = 0; i < 50000; i++) {
        // Sleep for 1 nanosecond
        nanosleep (&(struct timespec){.tv_nsec = 1}, NULL);
        
        // Lock the critical region (so that only 1 thread happens at one point in time)
        pthread_mutex_lock(&lock);
        
        // Increment the global total by 1 (critical region)
        global_total++;
        
        // Unlock the critical region (so that other threads can now run)
        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

int main(void) {
    pthread_t thread1;
    pthread_create(&thread1, NULL, add_50000_to_counter, NULL);

    pthread_t thread2;
    pthread_create(&thread2, NULL, add_50000_to_counter, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // If program works correctly, should print 100000
    printf("Final total: %d\n", global_total);
}
