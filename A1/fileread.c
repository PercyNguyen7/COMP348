#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileread.h"

#define MAX_LINE_LENGTH 1024

// This function return the line, or NULL if target line cannot be found (targetline > number of lines in txt file)
char* read_line(char* fileName, int targetLine){// Close the file
    FILE *fptr;
    // Open a file in read mode
    fptr = fopen(fileName, "r");
   
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
    // //Read the content and print it
    // // while(fgets(myString, MAX_LINE_LENGTH, fptr) != NULL) {        
    // //     array[counter] = strdup(myString);
    // //      printf("LINE:%s",myString);
    // //     counter++;
    // // }
       fclose(fptr);
       return str;
// If the file does not exist
    } else {
        printf("Not able to open the file.");
    }
    return NULL;
}



// void write_line(char* fileName, int targetLine, char* str){
//     FILE *fptr;
//     // Open a file in read mode
//     fptr = fopen(fileName, "r+");
//     if (fptr == NULL){
//         printf("File not found!\n");
//     }
//     char buffer[MAX_LINE_LENGTH];
//     int currLine = -2;
//     while (fgets(buffer, sizeof(buffer), fptr) != NULL) {    
//         currLine++;    
//         if (currLine == targetLine){
//             fprintf(fptr,"%s", str);
//             break;
//         } 
//     }
    
//       fclose(fptr);
// }
void write_line(char *filename, int line_num,char* new_text ) {
    FILE *file = fopen(filename, "r+"); // Open the file for both reading and writing
    if (file == NULL) {
        printf("Could not open file for reading and writing.\n");
        return;
    }

    // Read the file into a buffer
    char **lines = NULL;
    char buffer[512];
    int line_count = 0;

    // Read each line and store it in the lines array
    while (fgets(buffer, sizeof(buffer), file)) {
        lines = realloc(lines, sizeof(char*) * (line_count + 1));
        lines[line_count] = strdup(buffer); // Copy the line into memory
        line_count++;
    }

    // Make sure the line_num is valid
    if (line_num >= 0 && line_num < line_count) {
        // Free the old line and assign the new text
        free(lines[line_num]);
        lines[line_num] = strdup(new_text); // Replace the line content
    }

    // Move the file pointer to the beginning
    fseek(file, 0, SEEK_SET);

    // Write all lines back to the file
    for (int i = 0; i < line_count; i++) {
        fputs(lines[i], file); // Write each line to the file
        free(lines[i]); // Free the memory
    }

    // Clean up
    free(lines);
    fclose(file);
}
// char** get_strings(int* size) {
//     *size = 10; // Number of strings
//     char** array = malloc(*size * sizeof(char*)); // Allocate array of char*

//     if (array == NULL) return NULL; // Check allocation failure

//     array[0] = strdup("Hello");
//     array[1] = strdup("Dynamic");
//     array[2] = strdup("World");

//     return array; // Return the array of strings
// }