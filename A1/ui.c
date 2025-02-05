#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "ui.h"
#include "wreplace.h"

int confirmRes(int needConfirmation){
    if( needConfirmation == 0  ){
        return 3;
    } else if (needConfirmation == -1){
        return 4;
    } else if(needConfirmation == 1){
    // if needConfirmation is 1, meaning we do need it, then
        while(true){
            char* res = malloc(5 * sizeof(char));
            scanf("%5s", res);
            toLowerCase(res); 
            if (strcmp(res,"yes") == 0 || strcmp(res,"y") == 0){
                return 1;
            } else if (strcmp(res,"no") == 0 || strcmp(res,"n") == 0){
                return 2;
            } else if (strcmp(res,"all") == 0 || strcmp(res,"a") == 0){
                return 3;
            } else if (strcmp(res,"quit") == 0 || strcmp(res,"q") == 0){
                return 4;
            } 
                printf("Please input a valid answer (Yes, No, All, Quit)\n");
        } 
    }
    return 0;
}

void removeWordCaseSens(char** arr, int size){
    int needConfirmation = 1;
    char* word = "apple";
     int len = strlen(word);
     printf("RESULT %s", toLowerCase2("YoMOM"));
    char* censoredWord = censorWord(word);
    
    // char censoredWord[] = 

    // Looping through each line from given array
    for (int i = 0; i < size; i++) {
            // toLowerCase(arr[i]);
            // printf("%s", arr[i]);
        if (strstr(arr[i], word) != NULL) {

            if (needConfirmation == 1){
                printf("Changing line %d from\n%sto\n%sConfirm (Yes, No, All, Quit)? _\n", i+1, arr[i],replace_word(arr[i],word,censoredWord));
            }
            int res = confirmRes(needConfirmation);
            
            switch (res){
                case 1:
                   
                    char* newStr = replace_word(arr[i],word,censoredWord);
                    // int n = 0;
                    // while (arr[i][n] != "\0") {           
                    //     arr[i][n] = newStr[n];  
                    //     n++;                  
                    // }
                    arr[i] = newStr;
                    // printf("%s",arr[i]);
                    break;
               
                // Yes
                case 2:
                    break;
                // No
                case 3:
                // Change all
                    newStr = replace_word(arr[i],word,censoredWord);                  
                    arr[i] = newStr;
                    needConfirmation = 0;
                    break;
                case 4:
                // Quit - Print out the rest
                    needConfirmation = -1;
                    break;
            }
            if (res ==4) break;
        } else {
            // printf("\tNO CHANGE '%s'.\n", word);
        }
    }
        
      
      
}