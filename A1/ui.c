#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "ui.h"
#include "wreplace.h"
#include "fileread.h"

int confirmRes(int needConfirmation){
    if( needConfirmation == 0 ){
        return 3;
    } else if (needConfirmation == -1){
        return 4;
    } else if(needConfirmation == 1){
    // if needConfirmation is 1, meaning we do need it, then
        while(true){
            char res[100];
            scanf("%100s", res);
            toLowerCaseInPl(res); 
            if (strcmp(res,"yes") == 0 || strcmp(res,"y") == 0){
                return 1;
            } else if (strcmp(res,"no") == 0 || strcmp(res,"n") == 0){
                return 2;
            } else if (strcmp(res,"all") == 0 || strcmp(res,"a") == 0){
                
                return 3;
            } else if (strcmp(res,"quit") == 0 || strcmp(res,"q") == 0){
                return 4;
            } 
                printf("\nPlease input a valid answer (Yes, No, All, Quit)\n");
        } 
    }
    return 0;
}

//function 
void removeWordCaseSens( char* word, char* fileName){
    int needConfirmation = 1;
    //  int wordLen = strlen(word);
    int wordSwapCount = 0;
    int currLine = 0;
    int totalLineChanged = 0;
    int *ptWordSwapCount = &wordSwapCount;
    char* censoredWord = censorWord(word);
    int res;

    // printf("%s",censoredWord);
    char* currStr;
    // Looping through each line from given array
    while ((currStr = read_line(fileName, currLine)) != NULL) {
            char* newStr = replace_word(currStr,word,censoredWord,NULL);

        // IF word is substring
        if (strstr(currStr,word)) {
            if (needConfirmation == 1){
                printf("Changing line %d from\n%sto\n%sConfirm (Yes, No, All, Quit)? _\n", currLine, currStr, newStr);
            }
            res = confirmRes(needConfirmation);
            
            switch (res){
                case 1:
                // Yes
                    newStr = replace_word(currStr,word,censoredWord, ptWordSwapCount);
                    printf("The word(s) %s on line %d were redacted.\n\n",word,currLine);
                    totalLineChanged++;
                    write_line(fileName,currLine,newStr);
                    break; 
                case 2:
                     printf("No change was made.\n\n");
                    break;
                // No
                case 3:
                // Change all
                    printf("All remaining word(s) %s have been redacted.\n\n", word);
                    newStr = replace_word(currStr,word,censoredWord, ptWordSwapCount);                  
                    // currStr = newStr;
                    needConfirmation = 0;
                    totalLineChanged++;
                    break;
                case 4:
                // Quit - Print out the rest
                    needConfirmation = -1;
                    printf("Quitting without any further redaction.\n\n");
                    break;
            }
            if (res ==4) break;
            
        } else {
            printf("No change needed on line #%d!\n\n", currLine);   
        }
        currLine++;
        free(currStr);
    }
    printf("The program terminated and changed %d word(s) in %d line(s)\n", wordSwapCount,totalLineChanged);
}
void removeWordCaseInsens( char* word, char* fileName){
    int needConfirmation = 1;
    //  int wordLen = strlen(word);
    int wordSwapCount = 0;
    int currLine = 0;
    int totalLineChanged = 0;
    int *ptWordSwapCount = &wordSwapCount;
    char* censoredWord = censorWord(word);

    int res;

    // printf("%s",censoredWord);
    char* currStr;
    // Looping through each line from given array
    while ((currStr = read_line(fileName, currLine)) != NULL) {
        char* newStr = replace_word_ignorecase(currStr,word,censoredWord,NULL);
        // IF word is substring
        if (strstr(toLowerCase(currStr),toLowerCase(word))) {
            if (needConfirmation == 1){
                printf("Changing line %d from\n%sto\n%sConfirm (Yes, No, All, Quit)? _\n", currLine, currStr, newStr);
            }
            res = confirmRes(needConfirmation);
            
            switch (res){
                case 1:
                // Yes
                    newStr = replace_word_ignorecase(currStr,word,censoredWord, ptWordSwapCount);
                    printf("The word(s) %s on line %d were redacted.\n\n",word,currLine);
                    totalLineChanged++;
                    write_line(fileName,currLine,newStr);
                    break; 
                case 2:
                     printf("No change was made.\n\n");
                    break;
                // No
                case 3:
                // Change all
                    printf("All remaining word(s) %s have been redacted.\n\n", word);
                    newStr = replace_word_ignorecase(currStr,word,censoredWord, ptWordSwapCount);                  
                    // currStr = newStr;
                    needConfirmation = 0;
                    totalLineChanged++;
                    break;
                case 4:
                // Quit - Print out the rest
                    needConfirmation = -1;
                    printf("Quitting without any further redaction.\n\n");
                    break;
            }
            if (res ==4) break;
            
        } else {
            printf("No change needed on line #%d!\n\n", currLine);   
        }
        currLine++;
        free(currStr);
    }
    printf("The program terminated and changed %d word(s) in %d line(s)\n", wordSwapCount,totalLineChanged);
}
void decode_word(char* word, char* fileName){
    int needConfirmation = 1;
    //  int wordLen = strlen(word);
    int wordSwapCount = 0;
    int currLine = 0;
    int totalLineChanged = 0;
    int *ptWordSwapCount = &wordSwapCount;
    char* censoredWord = censorWord(word);

    int res;

    // printf("%s",censoredWord);
    char* currStr;
    // Looping through each line from given array
    while ((currStr = read_line(fileName, currLine)) != NULL) {
        char* newStr = decode_word_keep_case(currStr,word,NULL);
        // IF censoredWord is not a matched
        if (is_encoded_substring(currStr, censoredWord) ) {
            if (needConfirmation == 1){
                printf("Changing line %d from\n%sto\n%sConfirm (Yes, No, All, Quit)? _\n", currLine, currStr, newStr);
            }
            res = confirmRes(needConfirmation);
            
            switch (res){
                case 1:
                // Yes
                    newStr = decode_word_keep_case(currStr,word, ptWordSwapCount);
                    printf("The word(s) %s on line %d were decoded.\n\n",word,currLine);
                    totalLineChanged++;
                    write_line(fileName,currLine,newStr);
                    break; 
                case 2:
                     printf("No change was made.\n\n");
                    break;
                // No
                case 3:
                // Change all
                write_line(fileName,currLine,newStr);
                    printf("All remaining word(s) %s have been decoded.\n\n", word);
                    newStr = decode_word_keep_case(currStr,word, ptWordSwapCount);                  
                    
                    needConfirmation = 0;
                    totalLineChanged++;
                    break;
                case 4:
                // Quit - Print out the rest
                    needConfirmation = -1;
                    printf("Quitting without any further decoding.\n\n");
                    break;
            }
            if (res ==4) break;
        } else {
            printf("No change needed on line #%d!\n\n", currLine);   
        }
        currLine++;
        free(currStr);
    }
    printf("The program terminated and changed %d word(s) in %d line(s)\n", wordSwapCount,totalLineChanged);
}
