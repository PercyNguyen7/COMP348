
#pragma once
// #ifndef GRANDPARENT_H
// #define GRANDPARENT_H

extern char* candies[];
extern int candies_len;

extern int number;

void takeCandies(char* );

struct person{
    int age;
    char* name;
};

typedef struct{
    int age;
    char* name;
}  person2 ;

union package{
    int num;
    char* str;
};

typedef union{
    float num;
    char* arr[3];
} typePackage;



// static void staticFunc();

// #endif 
