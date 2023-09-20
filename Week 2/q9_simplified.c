// Simple factorial calculator - using goto

#include <stdio.h>

int main (void) {
    int n;
    printf("n  = ");
    scanf("%d", &n);

factorial_init:
    int factorial = 1;
    int i = 1;

factorial_cond:
    if (i > n) goto factorial_end;

factorial_body:
    factorial = factorial * i;

factorial_step:
    i = i + 1;
    goto factorial_cond;

factorial_end:
    printf("n! = %d\n", factorial);
    return 0;
}