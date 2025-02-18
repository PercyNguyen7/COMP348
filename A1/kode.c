#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <stdbool.h>

#include "fileread.h"
#include "wreplace.h"
#include "ui.h"

int assignMode(char* command ){
    // strcpy(command,argv[1]);
    if( strcmp(command,"RC") ==0) {
        
        return 1;
    } else  if( strcmp(command,"RI") ==0) {
        
        return 2;
    } else if( strcmp(command,"UK") ==0) {
        
        return 3;
    } else if( strcmp(command,"UM") ==0) {
   
        return 4;
    } else{
        printf("That is not a valid command");
        return 0;
    }
}

    // MAIN RETURNS
    // Abnormal error - 3
    // Quit - 1
    // No matches - 2
    // Changes made - return 0
int main(int argc, char *argv[]) {
    char* fileName = argv[3];
    char* word = argv[2];
    // Read the command
    int mode= assignMode(argv[1]);
    switch (mode) {
        case 1:
        // readFileLines(argv[3]);
        // printf("%s",read_line(argv[3],0));
            removeWordCaseSens(word,fileName);
            break;
        case 2:
            removeWordCaseInsens(word,fileName);
            break;
        case 3:
            decode_word(word,fileName);
            break;
        case 4:
            decode_word_special(word,fileName);
            break;

    } 
    return 0;
    
    // Close the file
//    char str[100];  // Declare a character array to store the string
//     printf("Enter a string: ");
//     scanf("%s", str);  // Read a string from the user

//     printf("You entered: %s\n", str);  


    // int arrSize;
   
    // char** array = read_file(&arrSize, argv[3]);    // this is the pointer to pointer of character i.e array 

    // if (array) {
    //     for (int i = 0; i < arrSize; i++) {
    //         printf("%s", array[i]);
    //         free(array[i]); // Free each string
    //     }
    //     free(array); // Free array of pointers
    // }
    // write_file(array, arrSize);
    return 0;
}

// void write_and_read_file() {
//     // Open the file in "w+" mode: reading and writing, file is truncated if exists
//     FILE* file = fopen("funny.txt", "w+");
//     if (file == NULL) {
//         perror("File opening failed");
//         return;
//     }

//     // Write some data to the file
//     fprintf(file, "Hello, World!\nThis is a test file.\n");

//     // Go back to the beginning of the file to read its content
//     // fseek(file, 0, SEEK_SET);

//     // Read and print the content of the file
//     char buffer[256];
//     while (fgets(buffer, arrSizeof(buffer), file)) {
//         printf("Read from file: %s", buffer);
//     }

//     // Close the file
//     fclose(file);
// }

// int main() {
//     const char* filename = "testfile.txt";
//     write_and_read_file(filename);
//     return 0;
// }
// Approach
// Reading line by line and return an array 
//