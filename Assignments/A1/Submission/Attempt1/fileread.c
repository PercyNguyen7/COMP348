//Vinh Tuan Dat NGUYEN
//40180660 
//Assignment 1
//Prof Ali Jannatpour
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileread.h"

#define MAX_LINE_LENGTH 4096

// read_line returns the curr. string or NULL if target line cannot be found (targetline > number of lines in txt file)
char* read_line(char* file_name, int targetLine){// Close the file
    FILE *fptr;
    // Open a file in read mode
    fptr = fopen(file_name, "r");
   
    int currLine= -1;
    // Store the content of the file
    char buffer[MAX_LINE_LENGTH];
    int strLength = 0;
    // If the file exist
    if(fptr != NULL) {
        while (fgets(buffer, sizeof(buffer), fptr) != NULL) {
            // printf("%s\n", buffer);    
            currLine++;    
            if (currLine == targetLine) {
                strLength = strlen(buffer); // Use strLength instead of sizeof
                // If the last character isn't '\n', add it
                if (strLength > 0 && buffer[strLength - 1] != '\n') {
                    buffer[strLength] = '\n';
                    buffer[strLength + 1] = '\0';  // Null-terminate the string
                }
                break;
            } 
        }
        // printf("\ncurr %d and %d target\n",currLine, targetLine);
        // If targetLine doesn't exist, then I return null
        if(currLine != targetLine)return NULL;
      
        char *str = (char *)malloc(strLength* sizeof(char) +1); 
        strcpy(str,buffer);

       fclose(fptr);
       return str;
// If the file does not exist
    } else {
        perror("Error opening file!");
        exit(3);
    }
    return NULL;
}
//function takes in a line and the line number, then write that string on the specified line of the file
void write_line(char *file_name, int target_line, char* new_text) {
    FILE *file = fopen(file_name, "r+"); // Open the file for both reading and writing
    if (file == NULL) {
        printf("Could not open file for reading and writing.\n");
        return;
    }

    char buffer[MAX_LINE_LENGTH];
    int curr_line = 0;

    // read line, then write one by one
    while (fgets(buffer, sizeof(buffer), file)) {
        //once reached the target line
        if (curr_line == target_line) {
            // move pointer backward into the beginning of the line
            fseek(file, -(long)strlen(buffer), SEEK_CUR); 
            fputs(new_text, file); 
            break; // Exit the loop after modifying the line
        }
        curr_line++;
    }
    fclose(file);
}