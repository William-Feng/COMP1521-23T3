// Print the contents of the file $HOME/.diary to stdout

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // Get the environment variable for $HOME
    char *home_pathname = getenv("HOME");

    // Construct the pathname $HOME/.diary
    char *diary_filename = ".diary";
    
    // Total length needs to cover the slash and the null terminator
    int pathname_length = strlen(home_pathname) + strlen(diary_filename) + 1 + 1;
    
    // The 'pathname' string is going to hold the final output
    char *pathname = malloc(pathname_length);
    
    snprintf(pathname, pathname_length, "%s/%s", home_pathname, diary_filename);
    
    // Open the file at that pathname for reading and do error checking
    FILE *fp = fopen(pathname, "r");
    if (fp == NULL) {
        perror(pathname);
        free(pathname);
        return 1;
    }
    
    // Loop through the file byte by byte and print out the contents
    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        fputc(ch, stdout);
    }
    
    fclose(fp);
    free(pathname);
    return 0;
}
