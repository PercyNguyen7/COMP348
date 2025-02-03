#include <stdio.h>
#include <stdlib.h>
// #include <stdbool.h>
#include <ctype.h>
#include "fileread.h"

int main(int argc, char *argv[]) {

    char* text = read_file();
    printf("%s", *text);
    // *********** scan logic
    // char charAns;
    // printf("Enter an integer: ");
    // scanf("%c", &charAns);  // Reading an integer
    // charAns = tolower(charAns);
   
    // printf("You entered: %c\n", charAns);
    // return 0;


    // argc is the number of arguments, including the program name
    // argv is an array of strings (char arrays) representing the arguments
    // for (int i = 0; i < argc; i++) {
    //     printf("Argument %d: %s\n", i, argv[i]);
    // }

    // return 0;
}
