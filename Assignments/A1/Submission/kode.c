//Vinh Tuan Dat NGUYEN
//40180660 
//Assignment 1
//Prof Ali Jannatpour
#include <stdio.h>
#include "fileread.h"
#include "wreplace.h"
#include "ui.h"
// kode.c contains functions to verify the command and the word input.
// program was personally tested with vanguard to prevent memory leaks

//function verifies if the given command is valid
int assign_mode(char* command ){
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
        exit(3);
    }
}
// Function verify if the word only contains letters
// int verifyWord(char* word){
//     //loop over word and check if every char is a letter
//     while (*word != '\0'){
//         if (!isalpha(*word)){
//             printf("\nInvalid word input. Word can only contain consecutive letters from the alphabet.\nClosing the application and returning code 3.\n\n");
//             return -1;
//         }
//         word++;
//     }
//     return 0;
// }


// function verifies if there are exactly 3 inputs in the command
void verify_all_input(char* command, char* word, char* file_name, char* extra){
    if(command == NULL ){
        printf("Missing command. Closing the application and returning code 3.\n");
        exit(3);
    }
    if(command == NULL ){
        printf("Missing word input. Closing the application and returning code 3.\n");
        exit(3);
    }
    if(word == NULL ){
        printf("Missing text file name. Closing the application and returning code 3.\n");
        exit(3);
    }
    if(extra != NULL ){
        printf("Too many arguments. Closing the application and returning code 3.\n");
        exit(3);
    }
}

    // 0 - Changes made
    // 1 - Quit 
    // 2 - No matches 
    // 3 - Abnormal error (invalid command or word, FILE IO)
int main(int argc, char *argv[]) {
    verify_all_input(argv[1],argv[2],argv[3],argv[4]);
    
    int mode = assign_mode(argv[1]);
    char* word = argv[2];
    char* file_name = argv[3];

    // Check if mode or word invalid, then return 3.
    int result = start_program(mode,word,file_name);
    exit(result);
}

