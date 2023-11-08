// If a file or directory is publically writeable,
// this program should change it so that it is no longer publically-writeable

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void chmod_if_publically_writeable(char *pathname);

int main(int argc, char *argv[]) {
    for (int arg = 1; arg < argc; arg++) {
        chmod_if_publically_writeable(argv[arg]);
    }
    return 0;
}

void chmod_if_publically_writeable(char *pathname) {
    // Get the metadata and error check
    struct stat s;
    int output = stat(pathname, &s);
    if (output != 0) {
        fprintf(stderr, "Cannot stat the file\n");
        perror(pathname);
        return;
    }
    
    // At this point, we can expect the metadata of the pathname
    // to be populated and stored inside the struct 's'
    
    mode_t mode = s.st_mode;
    
    // E.g. mode = 111 110 100      -rwxrw-r--
    // This mode above is NOT publically writeable so we don't need to do anything
    
    // Therefore, we need a way to check if the second-last bit is a 1
    // S_IWOTH == 000 000 010
    
    if (mode & S_IWOTH) {
        // Change the mode (negate the public writeable permission) and error check
        // Set the second last bit to 0 (either use XOR or the following line)
        mode_t new_mode = mode & ~S_IWOTH;
        
        if (chmod(pathname, new_mode)) {
            fprintf(stderr, "There was an error changing the permission of the file\n");
            perror(pathname);
            return;
        }
        
        printf("The file/directory permissions have been successfuly changed so that it's NOT publically writeable\n");
    } else {
        printf("The file/directory is currently NOT publically writeable and so nothing has changed\n");
    }
}
