// Correcting error in program

#include <stdio.h>

int main(void) {
    char str[10];
    str[0] = 'H';
    str[1] = 'i';
    
    // Don't forget to end strings with a null terminator
    str[2] = '\0';
    
    printf("%s", str);
    return 0;
}
