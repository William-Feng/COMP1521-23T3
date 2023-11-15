// Using posix-spawn to create new processes (provided solutions)

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <spawn.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

// extern means the variable is defined somewhere else.
// In this case, the variable is defined by the system environment.
extern char **environ;

// Spawns a process and waits for it to die.
// Input is the argv array of the process function.
void spawn_and_wait(char *args[])
{
    pid_t pid;
    int spawn_status = posix_spawn(&pid, args[0], NULL, NULL, args, environ);
    // args[0] is the file path.
    // The array of arguments (args) must be NULL terminated.
    if (spawn_status != 0) {
        // Unsuccessful posix_spawn, so code other than 0 (success)

        // errno is a special global variable which describes the last error that occurred.

        // Usually, most library functions will set errno when they fail.
        // However, posix_spawn() returns its error code and doesn't set errno,
        // so we need to do this ourselves.
        errno = spawn_status;
        // perror prints out an appropriate error message depending on errno.
        perror("posix_spawn");
        exit(EXIT_FAILURE);
    }

    // waitpid(..) waits until the process changes state - in this case, waiting
    // for it to die.
    // waitpid returns -1 on error.

    // pid: The process ID of the process to wait for.
    // &spawn_exit_status: The exit status of the target process.

    int spawn_exit_status;

    if (waitpid(pid, &spawn_exit_status, 0) == -1) {
        perror("waitpid");
        // Prints waitpid: The error described by errno's error code
        exit(EXIT_FAILURE);
    }

    // If we wanted to print out the exit status of the process,
    // printf("Exited with status %d\n", WEXITSTATUS(spawn_exit_status));
}

int main(int argc, char *argv[])
{
    // Creates an array of strings for the input argv of each function.
    // NULL terminated to mark the end of the argument list.
    char *date_argv[] = {"/bin/date", "+%d-%m-%Y", NULL};
    // Run the date program with the argument "+%d-%m-%Y".
    spawn_and_wait(date_argv);

    char *time_argv[] = {"/bin/date", "+%T", NULL};
    // Run the time program with argument "+%T".
    spawn_and_wait(time_argv);

    char *user_argv[] = {"/usr/bin/whoami", NULL};
    // Run the whoami program without any arguments.
    spawn_and_wait(user_argv);

    char *hostname_argv[] = {"/bin/hostname", "-f", NULL};
    // Run the hostname program with the -f flag (prints full output).
    spawn_and_wait(hostname_argv);

    char *working_dir_argv[] = {"/usr/bin/realpath", ".", NULL};
    spawn_and_wait(working_dir_argv);
}