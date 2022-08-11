// Design and develop a program that creates child and parent process
// writes data to pipe and child process reads data from pipe, printing on screen
// creates file[0] and file[1] file descripters for comm
// fd[0] -> used for reading, fd[1] -> used for writing
// pipe error returns -1;
// pipe() -> unidir data channel (1 to read and 1 to write)

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int file[2]; // 2 arr elements
    char input_str[100];
    pid_t p;
    if (pipe(file) == -1) {
        fprintf(stderr, "Pipe Failed");
        return 1;
    }
    printf("Enter the string\n");
    scanf("%s", input_str);
    p = fork();                                           // create process
    if (p < 0) {
        fprintf(stderr, "Fork failed");
        return 1;
    }
    // else write
    else if (p > 0) {                                     // parent
        close(file[0]);                                   // close read file descripter
        write(file[1], input_str, strlen(input_str) + 1); // open write fd
        close(file[1]);                                   // close write fd
        wait(NULL);                                       // mutual exclusion
    }
    else {                                                // read
        close(file[1]);
        printf("Child reading parent from data pipe\n");
        char parent_str[100];                             // create parent string to cpy elements from read to parent_str
        read(file[0], parent_str, 100);                   // file, parent_str, sizeof(parent_str);
        printf("Read string : %s \n", parent_str);
        close(file[0]);
        exit(0);
    }
}