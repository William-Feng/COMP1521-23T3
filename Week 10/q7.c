// Infinitely printing message while waiting for input

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_BYTES 1024

void *thread_run(void *data) {
    while (true) {
        printf("feed me input!\n");
        sleep(1);
    }
    
    return NULL;
}

int main(void) {
    pthread_t thread;
    pthread_create(
        &thread,    // the pthread_t handle that will represent this thread
        NULL,       // thread-attributes -- we usually just leave this NULL
        thread_run, // the function that the thread should start executing
        NULL        // data we want to pass to the thread -- this will be
                    // given in the `void *data` argument above
    );
    
    char line[MAX_BYTES];
    while (fgets(line, MAX_BYTES, stdin) != NULL) {
        printf("you entered %s", line);
    }
    
    // Although not strictly necessary, we can terminate the thread here
    pthread_cancel(thread);

    return 0;
}
