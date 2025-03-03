//Vinh Tuan Dat NGUYEN
//40180660 
//Assignment 1
//Prof Ali Jannatpour
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileread.h"

#define MAX_LINE_LENGTH 4096

// read_line returns the curr. string or NULL if target line cannot be found (target_line > number of lines in txt file)
char* read_line(char* file_name, int target_line){// Close the file
    FILE *fptr;
    // Open a file in read mode
    fptr = fopen(file_name, "r");
   
    int curr_line= -1;
    // Store the content of the file
    char buffer[MAX_LINE_LENGTH];
    int str_len = 0;
    // If the file exist
    if(fptr != NULL) {
        while (fgets(buffer, sizeof(buffer), fptr) != NULL) {
            // printf("%s\n", buffer);    
            curr_line++;    
            if (curr_line == target_line) {
                str_len = strlen(buffer); // Use str_len instead of sizeof
                // If the last character isn't '\n', add it
                if (str_len > 0 && buffer[str_len - 1] != '\n') {
                    buffer[str_len] = '\n';
                    buffer[str_len + 1] = '\0';  // Null-terminate the string
                }
                break;
            } 
        }
        // If target_line doesn't exist, then I return null
        if(curr_line != target_line){
            fclose(fptr);
            return NULL;
        }

        char *str = (char *)malloc(str_len* sizeof(char) +1); 
        strcpy(str,buffer);
       fclose(fptr);
       return str;
// If the file does not exist
    } else {
        perror("Error opening file: ");
        printf("Exiting program with code 3.\n");
        exit(3);
    }
}
//function takes in a line and the line number, then write that string on the specified line of the file
void write_line(char *file_name, int target_line, char* new_text) {
    FILE *fptr = fopen(file_name, "r+"); // Open the file for both reading and writing
    if (fptr == NULL) {
        printf("Could not open file for reading and writing.\n");
        return;
    }

    char buffer[MAX_LINE_LENGTH];
    int curr_line = 0;

    // read line, then write one by one
    while (fgets(buffer, sizeof(buffer), fptr)) {
        //once reached the target line
        if (curr_line == target_line) {
            // move pointer backward into the beginning of the line
            fseek(fptr, -(long)strlen(buffer), SEEK_CUR); 
            fputs(new_text, fptr); 
            break; // Exit the loop after modifying the line
        }
        curr_line++;
    }
    fclose(fptr);
}