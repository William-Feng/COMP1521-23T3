// Demonstrating command line arguments

#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("argc=%d\n", argc);
    // for (int i = 0; i < argc; i++) {
    //     printf("argv[%d]=%s\n", i, argv[i]);
    // }
    
    // The above for loop is equivalent to this while loop
    int i = 0;
    while (i < argc) {
        printf("argv[%d]=%s\n", i, argv[i]);
        i++;
    }
    return 0;
}
