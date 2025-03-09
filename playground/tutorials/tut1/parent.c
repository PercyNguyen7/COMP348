
#include "parent.h"
// #include "grandparent.h"
#include <stdbool.h>
#include <string.h>         // For string manipulation functions like strstr()
#include <stdio.h>          // For printf()

// Function definition - the actual implementation of the function declared in the header file
bool contains_substring(const char* str, const char* substring) {
    // Use strstr() from string.h to check if 'substring' exists in 'str'
    if (strstr(str, substring) != NULL) {
        return true;  // Substring found
    }
    return false;  // Substring not found
}

// Example function to demonstrate usage
void print_result(const char* str, const char* substring) {
    if (contains_substring(str, substring)) {
        printf("'%s' contains the substring '%s'.\n", str, substring);
    } else {
        printf("'%s' does not contain the substring '%s'.\n", str, substring);
    }
}


struct person makePerson (char* name, int age){
    struct person p1;
    p1.age =3;
    p1.name = "Mayo";

    printf("Their name is %s, and they are %d years old.\n",p1.name, p1.age);
    return p1;
}



