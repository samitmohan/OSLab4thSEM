// process system call

// pid_t -> process identification -> data type (just like integer but for process)
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    pid_t pid;
    pid = fork(); // create child process (pid stores 0 (child) or neg or pos (parent))
    if (pid < 0) {
        printf("Fork failed");
        exit(1);
    } else if (pid == 0) {
        execlp("whoami", "ls", NULL); // system call -> tells which user is running
        exit(0);
    } else { // parent process (positive) -> getpid()
        printf("Process id = %d \n", getpid());
        wait(NULL); // if multi[ple processes
        exit(0);
    }
}

// returns pid of child process