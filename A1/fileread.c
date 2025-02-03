#include <stdio.h>
#include <stdlib.h>

char* read_file(){
    FILE *file = fopen("test.txt", "r");  // Open the file in read mode
    if (file == NULL) {
        // Handle file opening failure
        perror("Error opening file");
        return "";
    }
    char text[] = "yourrrr mom what is going on oh boyy";
    char line[256];  // Buffer to store each line
   
    char* greeting= malloc(50 * sizeof(char));
    // Read each line of the file
    // while (fgets(line, sizeof(line), file)) {
    //     // printf("Changing line %d from\n", i);
    //     // printf("%s", line);  // Print the line
    //     // i++;

    //     strcat(text,line);
    // }

    fclose(file);  // Close the file
    return greeting;
}