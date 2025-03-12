#include <stdio.h>
#include <string.h>

/* Function to print string slice from i'th character*/
void print_str_slice(char* str, int i) {
    // The arguments are the same as (char str[], int i)
    if (i > (strlen(str)-1))
        printf("ERROR");
    else {
        printf("Sliced string: %s", &str[i]);   
    }
}

int main(int argc, char const *argv[])
{
    printf("-------------------\n");
    printf("C Strings (ASCIIZ - null terminated character arrays\n");
    
    // Declaring strings
    char declared_str[5];
    
    //Initializing strings
    char initialized_str[] = "abcde";   // string literal, compiler places \0
    char initialized_str_2[] = {'a','b','c','d','e','\0'}; 
    // printf("%d", sizeof(initialized_str));
    
    // Reading a string from console input
    printf("Enter a string (<20chars): ");
    char console_ip_str[20];
    scanf("%s", console_ip_str);
    // scanf("%s", &console_ip_str[0]);

    // String is printed with a "%s" format specifier
    printf("Received string: %s\n", console_ip_str);
    fprintf(stdout, "Received string: %s\n", console_ip_str);
    fprintf(stderr, "Received string: %s\n", console_ip_str);

    // Passing a string to a function as a char pointer
    char* test = "Example of a sliced string";
    printf("%d", sizeof(test));
    print_str_slice(test, 13);
    
    printf("\n");
    return 0;
}
