// Add 42 to each negative element of an array and print it out

#include <stdio.h>
#define N_SIZE 10

int main(void) {
    int i = 0;
    int numbers[N_SIZE] = {0, 1, 2, -3, 4, -5, 6, -7, 8, 9};

    while (i < N_SIZE) {
        if (numbers[i] < 0) {
            numbers[i] += 42;
        }
        printf("%d\n", numbers[i]);
        i++;
    }
    
    return 0;
}