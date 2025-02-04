#include <stdio.h>
#include <stdlib.h>
// #include <stdbool.h>
// #include "fileread.h"

int main() {
FILE *fptr;
// Open a file in read mode
fptr = fopen("test.txt", "r");

// Store the content of the file
char myString[100];

// If the file exist
    if(fptr != NULL) {

    // Read the content and print it
    while(fgets(myString, 100, fptr)) {
        char ans[100];
        printf("%s", myString);
        printf("how are you doing?\n");   
        scanf("%s",ans);    
        printf("You entered: %s\n", ans); 
    }
       fclose(fptr);
// If the file does not exist
    } else {
        printf("Not able to open the file.");
    
    }
    

    // Close the file
//    char str[100];  // Declare a character array to store the string
//     printf("Enter a string: ");
//     scanf("%s", str);  // Read a string from the user

//     printf("You entered: %s\n", str);  
    return 0;
}
