// Simple factorial calculator

#include <stdio.h>

int main (void) {
    int n;
    printf("n  = ");
    scanf("%d", &n);

    int factorial = 1;

    // for (int i = 1; i <= n; i++) {
    //     factorial *= i;
    // }

    int i = 1;
    while (i <= n) {
        factorial *= i;
        i++;
    }

    printf ("n! = %d\n", factorial);
    return 0;
}