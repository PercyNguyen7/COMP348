//Vinh Tuan Dat NGUYEN
//40180660 
//Assignment 1
//Prof Ali Jannatpour
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "ui.h"
#include "wreplace.h"
#include "fileread.h"

//confirm_response processes user's response and return a number corresponding to an action
//1: YES, 2: NO, 3: ALL, 4: QUIT
//If confirmation is 0, always return 3 (ALL)
int confirm_response(int confirmation){
    
    if( confirmation == 0 ){
        return 3;
    } else if(confirmation == 1){
    // if confirmation is 1, meaning we do need it, then
        while(true){
            char res[100];
            scanf("%20s", res);
            to_lowercase_in_place(res); 
            if (strcmp(res,"yes") == 0 || strcmp(res,"y") == 0){
                return 1;
            } else if (strcmp(res,"no") == 0 || strcmp(res,"n") == 0){
                return 2;
            } else if (strcmp(res,"all") == 0 || strcmp(res,"a") == 0){
                return 3;
            } else if (strcmp(res,"quit") == 0 || strcmp(res,"q") == 0){
                return 4;
            } 
                printf("\nPlease input a valid answer (Yes (y), No (n), All (a), Quit (q))\n");
        } 
    }
    return 0;
}

//start_program executes the entire logic of the program
int start_program(int mode, char* word, char* file_name){
    bool allChosen = false;    
    int confirmation = 1; // 1 means yes, 0 means all, and -1 means no.
    int swap_count = 0;
    int curr_line = 0;
    int total_line_changed = 0;
    int *pt_swap_count = &swap_count;
    int user_response;
    bool matchFound = false;
    char* curr_str;
    
    // Looping through each line from given array
    while ((curr_str = read_line(file_name, curr_line)) != NULL) {
        //doesnt pass in pointer because we are not tracking swap count here
        char* newStr = process_string(mode,curr_str,word,NULL);

        // IF the word/encoded word can be replaced!
        if (substring_found(mode,curr_str,word)) {
            matchFound = true;
            if (confirmation == 1){
                printf("Changing line %d from\n%sto\n%sConfirm (Yes (y), No (n), All (a), Quit (q))? _\n", curr_line, curr_str, newStr);
            }
            
            user_response = confirm_response(confirmation);
            switch (user_response){
                 // YES
                case 1:
                free(newStr);
                    newStr = process_string(mode,curr_str,word, pt_swap_count);
                    printf("The word(s) %s on line %d were changed.\n\n",word,curr_line);
                    total_line_changed++;
                    write_line(file_name,curr_line,newStr);
                    break; 
                // NO
                case 2:
               
                    printf("No change was made.\n\n");
                    break;
                 // ALL
                case 3:
                free(newStr);
                    if(!allChosen){
                        printf("All remaining word(s) %s have been changed.\n\n", word);
                        allChosen = true;
                    }   
                    newStr = process_string(mode,curr_str,word,pt_swap_count);                  
                    confirmation = 0;
                    total_line_changed++;
                    write_line(file_name,curr_line,newStr);
                    break;
                // QUIT
                case 4:
                // Quit - Print out the rest
                    free(curr_str);
                    free(newStr);
                    printf("Quitting without any further changes.\n\n");
                    printf("Changed %d word(s) in %d line(s). Returning code 1.\n\n", swap_count,total_line_changed);
                    return 1;
            }
        } else {
            if(!allChosen){
                 printf("No change needed on line #%d!\n\n", curr_line);   
             }
        }
        curr_line++;
        free(curr_str);
        free(newStr);
    }
    matchFound ? printf("Changed %d word(s) in %d line(s). Returning code 0.\n\n", swap_count,total_line_changed) : printf("No match found. Returning code 2.\n\n");
    return matchFound ? 0 : 2;
}

