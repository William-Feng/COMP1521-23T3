// Sum 2 numbers using function calls

#include <stdio.h>

int add_nums(int x, int y);

int main(void) {
    int x = 10;
    int y = 5;
    
    int sum = add_nums(x, y);
    printf("%d\n", sum);
    printf("%d\n", x);
    
    return 0;
}

int add_nums(int x, int y) {
    int random = x + y;
    return random;
}
