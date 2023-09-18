// Identifying error with functions

#include <stdio.h>
#include <stdlib.h>

int *get_num_ptr(void);

int main(void) {
    // A pointer is a variable (stored on the stack)
    // that references the address of another variable
    
    int *num = get_num_ptr();

    printf("%d\n", *num);
    
    free(num);
}

int *get_num_ptr(void) {
    int *x = malloc(sizeof(int));
    *x = 42;
    return x;
}
