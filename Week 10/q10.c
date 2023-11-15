// Using atomic types to prevent race conditions

#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>

atomic_int global_total = 0;

void *add_50000_to_counter(void *data) {
    for (int i = 0; i < 50000; i++) {
        // Sleep for 1 nanosecond
        nanosleep (&(struct timespec){.tv_nsec = 1}, NULL);
        
        // Increment the global total by 1 (critical region)
        global_total++;
        
        /*
        Note:
        
        global_total++ is an atomic operation
        global_total += 1 is an atomic operation
        global_total = global_total + 1 is NOT an atomic operation
        */
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
