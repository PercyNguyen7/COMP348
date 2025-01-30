#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "headers/string_util.h"

// #include "string_util.c"

// Macros declaration, preprocessor step before compilation
// difference is when using a variable,
#define SIZE 5
#define PRODUCT(x,y) (x)*(y)


int main(){
    sayHi(5);
    //********************MACROS*********************************
    // int i;
    // int arr [SIZE];
    // for (i = 0; i< SIZE; i++){
    //     arr[i] = i*2;
    //     printf("%d ", arr[i]);
    // }

    // int a =2, b =6;
    // printf("%d\n", PRODUCT(a+1,b));

// ******************** VARIABLES ****************************
    // char a = 'C';       // single char
    // char b[] = "Bro";   // array of char, must be in double quotations
    
    // float C = 3.141592;          // 4 bytes - 6-7 digits 
    // double d =3.141592653589783; // 8 bytes 15-16 digits %lf

    // bool e = false;              // 1 byte (T or F) %d

    // char f = 120;  // DEFAULT        1 byte (-128 to 127) %d or %c
    // unsigned char g = 255;        // 1 byte (0 to 255) %d or %c

    // short int h = 32767;            // 2 bytes (-32 768 to 32 767) %d
    // unsigned short int i = 65535;   // 2 bytes (0 to 65 535) %d

    // int j = 2147483647;            // 4 bytes (-2 billion - 2 billion) %d
    // unsigned int k = 4000000000;    // 4 bytes (0 to 4 billion) %u

    // long long int l = 9223372036854775807; // 8 bytes (-9 quintillion to 9 quintillion) %lld
    // unsigned long long int m = 18446744073709551615; // 8 bytes (0 to 18 quintillion) %llu

    int age;
    age = 24;   // 4 bytes, %d, (0 to 65 535) 
    float gpa = 3.65;   // 4 bytes, %f, 6-7 digits
    double gpaD = 3.65324195921; // 8 bytes, %lf, 15-16 digits
    char grade ='A';    // 1 byte, %c
    char name[] = "Percival"; // 8 bytes, %s
    printf("Name's %s, I am %d years old. My gpa is %.2f with the letter grade %c\n",name, age, gpa, grade);
    
    return 0;
}