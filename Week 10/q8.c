// Program that causes race conditions, a concurrency problem

#include <stdio.h>
#include <pthread.h>

int global_total = 0;

void *add_50000_to_counter(void *data) {
    for (int i = 0; i < 50000; i++) {
        // Sleep for 1 nanosecond
        nanosleep (&(struct timespec){.tv_nsec = 1}, NULL);
        
        // Increment the global total by 1
        global_total++;
        
        /*
        When we call global_total++, there are actually 3 underlying operations
        1. lw      $t0, global_total
        2. addi    $t0, $t0, 1
        3. sw      $t0, global_total
        
        
        First time this runs:
        Thread 1: read global_total as 0
        Thread 1: increment global_total to become 1
        
        Thread 2: read global_total as 0
        Thread 2: increment global_total to become 1
        Thread 2: store global_total as 1 into memory
        
        Thread 1: store global_total as 1 into memory
        
        However we expected global_total to be 2!
        So we've lost an increment!
        This is a race condition
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
