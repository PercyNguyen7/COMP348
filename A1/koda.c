#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r+");
    // Open a file in read mode
    // for (int i = 0; i < argc; i++) {
    //     printf("Argument %d: %s\n", i, argv[i]);
    // }
    if (file == NULL){
        perror("Error opening file");
        return 1;
    }
    char ch;
    while ( (ch = fgetc(file)) != EOF) {
        printf("%c", ch);
        printf("*");
        //  putchar(ch);
    }
    fclose(file);


    // argc is the number of arguments, including the program name
    // argv is an array of strings (char arrays) representing the arguments
    // for (int i = 0; i < argc; i++) {
    //     printf("Argument %d: %s\n", i, argv[i]);
    // }

    // return 0;
}
