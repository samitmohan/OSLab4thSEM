// parent process child process relationship
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// fork returns -> 0 (child process) or +1 (positive -> parent process) or -1 (if child process not created);

int main() { // parent process
    int i;
    for (i = 0; i < 5; i++) {
        if (fork() == 0) { // child process exists
            printf("[son] pid %d from [parent] pid %d \n", getpid(), getppid());
            exit(0);
        } 
    }
    // also wait after every call (process has more than one child) = program is mutually exclusive
    for (i = 0; i < 5; i++) {
        wait(NULL);
    }
}