// Two infinite loops running together

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_run(void *data) {
    char *string = data;
    
    while (1) {
        printf("%s", string);
        sleep(1);
    }

    return NULL;
}

int main(void) {
    char *thread_message = "Hello\n";

    pthread_t thread;
    pthread_create(
        &thread,                // the pthread_t handle that will represent this thread
        NULL,                   // thread-attributes -- we usually just leave this NULL
        thread_run,             // the function that the thread should start executing
        thread_message          // data we want to pass to the thread -- this will be
                                // given in the `void *data` argument above
    );
    
    while (1) {
        printf("there\n");
        sleep(1);
    }

    return 0;
}
