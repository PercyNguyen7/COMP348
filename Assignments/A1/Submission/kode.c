//Vinh Tuan Dat NGUYEN
//40180660 
//Assignment 1
//Prof Ali Jannatpour
#include <stdio.h>
#include "fileread.h"
#include "wreplace.h"
#include "ui.h"
// kode.c contains functions to verify the command and the word input.

//function verifies if the given command is valid
int verifyMode(char* command ){
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
        printf("\nThat is not a valid task command. Closing the application and returning code 3\n\n");
        return -1;
    }
}
// Function verify if the word only contains letters
int verifyWord(char* word){
    //loop over word and check if every char is a letter
    while (*word != '\0'){
        if (!isalpha(*word)){
            printf("\nInvalid word input. Word can only contain consecutive letters from the alphabet.\nClosing the application and returning code 3.\n\n");
            return -1;
        }
        word++;
    }
    return 0;
}

    // 0 - Changes made
    // 1 - Quit 
    // 2 - No matches 
    // 3 - Abnormal error (invalid command or word, FILE IO)
int main(int argc, char *argv[]) {
    int mode = verifyMode(argv[1]);
    char* file_name = argv[3];
    char* word = argv[2];

    // Check if mode or word invalid, then return 3.
    if( mode == -1 || verifyWord(word) == -1) return 3;
    int result = start_program(mode,word,file_name);
    exit(result);
}

