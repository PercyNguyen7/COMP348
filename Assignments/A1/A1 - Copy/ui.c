#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "ui.h"
#include "wreplace.h"

int confirmRes(int needConfirmation){
    if( needConfirmation == 0 ){
        return 3;
    } else if (needConfirmation == -1){
        return 4;
    } else if(needConfirmation == 1){
    // if needConfirmation is 1, meaning we do need it, then
        while(true){
            char* res = malloc(5 * sizeof(char));
            scanf("%5s", res);
            toLowerCaseInPl(res); 
            if (strcmp(res,"yes") == 0 || strcmp(res,"y") == 0){
              free(res);
                return 1;
            } else if (strcmp(res,"no") == 0 || strcmp(res,"n") == 0){
              free(res);
                return 2;
            } else if (strcmp(res,"all") == 0 || strcmp(res,"a") == 0){
                free(res);
                return 3;
            } else if (strcmp(res,"quit") == 0 || strcmp(res,"q") == 0){
               free(res);
                return 4;
            } 
            
                printf("\nPlease input a valid answer (Yes, No, All, Quit)\n");
        } 
    }
    return 0;
}

//function 
void removeWordCaseSens(char** arr, int size, char* word){
    int needConfirmation = 1;
    // char* word = "Apple";
    //  int wordLen = strlen(word);
    int wordSwapCount = 0;
    int lineCount = 0;
    int *ptWordSwapCount = &wordSwapCount;
    char* censoredWord = censorWord(word);
    // printf("%s",censoredWord);

    // Looping through each line from given array
    for (int i = 0; i < size; i++) {
            // toLowerCaseInPl(arr[i]);
            
            char* pt = strstr(arr[i],word);
            char* pt2 = replace_word(arr[i],word,censoredWord,NULL);
        // IF word is substring
        if (isSubstring(arr[i],word)) {
   
            if (needConfirmation == 1){
                printf("\nChanging line %d from\n%sto\n%sConfirm (Yes, No, All, Quit)? _\n", (i+1), arr[i], pt2);
            }
            int res = confirmRes(needConfirmation);
            
            switch (res){
                case 1:
                // Yes
                    char* newStr = replace_word(arr[i],word,censoredWord, ptWordSwapCount);
                    // int n = 0;
                    // while (arr[i][n] != "\0") {           
                    //     arr[i][n] = newStr[n];  
                    //     n++;                  
                    // }
                    arr[i] = newStr;
                    lineCount++;
                    // printf("%s",arr[i]);
                    break;
               
                
                case 2:
                    break;
                // No
                case 3:
                // Change all
                    newStr = replace_word(arr[i],word,censoredWord, ptWordSwapCount);                  
                    arr[i] = newStr;
                    needConfirmation = 0;
                    lineCount++;
                    break;
                case 4:
                // Quit - Print out the rest
                    needConfirmation = -1;
                    break;
            }
            if (res ==4) break;
        } else {
            printf("\nNo change needed on line #%d!\n", lineCount);
        }
    }  
    printf("The program terminated and changed %d word(s) in %d line(s)\n", wordSwapCount,lineCount);
}