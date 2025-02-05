#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileread.h"

#define MAX_LINE_LENGTH 1024

char** read_file(int* size){// Close the file
    FILE *fptr;
    // Open a file in read mode
    fptr = fopen("test.txt", "r");
    
    // Store the content of the file
    char myString[MAX_LINE_LENGTH];
    char* str = malloc(MAX_LINE_LENGTH);
    if (str == NULL) {
        return NULL; // Handle allocation failure
    }
    // If the file exist
    if(fptr != NULL) {
    int counter =0;
    *size = 10; // Number of strings
  
    char** array = malloc(*size * sizeof(char*)); // Allocate array of char*

    if (array == NULL) return NULL; // Check allocation failure

    // Read the content and print it
    while(fgets(myString, MAX_LINE_LENGTH, fptr) != NULL) { 
        array[counter] = strdup(myString);
        counter++;
    }
      *size = counter;
       fclose(fptr);
       return array;
// If the file does not exist
    } else {
        printf("Not able to open the file.");
    }
    return NULL;
}
void write_file(char** arr,int size){
    FILE *file;
    // Open a file in read mode
    file = fopen("test.txt", "w");
    if (file == NULL){
        printf("File not found!\n");
    }
    
     for (int i = 0; i < size; i++) {
        fprintf(file,"%s", arr[i]);
         free(arr[i]); // Free each string
     }
      free(arr);// Free array of pointers
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
