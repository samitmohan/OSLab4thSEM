// file management system calls
// create a file
// copy file to another
// delete a file

// creating a file
#include <stdio.h>
int main() {
    FILE *fp;
    fp = fopen("data.txt", "w");

    return 0;
}