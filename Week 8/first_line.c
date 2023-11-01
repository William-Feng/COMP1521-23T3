// Open a file and print out the first line

#include <stdio.h>

int main(int argc, char *argv[]) {
    
    // Usage: ./first_line secret.txt
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    // Open the file for reading
    FILE *fp = fopen(argv[1], "r");
    
    // Handle error if it could not read the file
    if (fp == NULL) {
        perror(argv[1]);
        return 1;
    }
    
    // Loop through the file byte by byte until there's none left
    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        fputc(ch, stdout);
        // Exit the loop once we have printed out the newline character
        if (ch == '\n') {
            break;
        }
    }
    
    fclose(fp);
    return 0;
}