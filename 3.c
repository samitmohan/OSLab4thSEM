// design develop implement program to change current working directory and display inode details for each file
#include <stdio.h>

int main(int argc, char *argv[]) {
    char d[50];
    if (argc == 2) {
        bzero(d, sizeof(d)); // bzero -> erases data (writes zeroes of size d)
        strcat(d, "ls "); // destination, source (adds and stores in d)
        strcat(d, "-i ");
        strcat(d, argv[1]); // d = ls -i and then arg -> terminal
        system(d); // pass commands to terminal
    } else {
        printf("Invalid number of inputs");
    }
}

/*
mkdir dd
cd dd
cat > file
hello
^c
gcc 3.c
./a.out dd

inode value will be printed
*/