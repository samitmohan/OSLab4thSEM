// copy 1 file to another
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr1, *fptr2;
    char filename[100], c;
    printf("Enter file name to open for reading : ");
    scanf("%s", filename);
    fptr1 = fopen(filename, "r");
    if (fptr1 == NULL) {
        printf("Cannot open file %s \n", filename);
        exit(0);
    }
    // otherwise -> it contains contents
    printf("Enter filename for writing : ");
    scanf("%s", filename);
    fptr2 = fopen(filename, "w");
    if (fptr2 == NULL) {
        printf("Cannot open file %s \n", filename);
        exit(0);
    }

    // actual copying
    c = fgetc(fptr1);
    while (c != EOF) {
        fputc(c, fptr2); // read from f1 and write in f2
        c = fgetc(fptr1); // next char
    }
    printf("\n Contents copied!! to %s", filename);
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}