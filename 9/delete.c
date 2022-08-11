#include <stdio.h>
int main() {
    if (remove("abc.txt") == 0) { // doesnt exist
        printf("Deleted!"); 
    } else {
        printf("\n Unable to delete");
    }
    return 0;
}