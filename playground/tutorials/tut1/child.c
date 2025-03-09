// #include <stdio.h>

// #include "grandparent.h"
#include "parent.h"
#include "child.h"
// static void staticFunc();

int main () {

    // // ******************HEADERS**********************
    const char* text = "Hello, world!";
    const char* sub = "world";
    
    // Call the function defined in string_utils.c
    print_result(text, sub);

   // // SCAN AND PRINT
    // int a;
    // int b;
    // printf("Please input two inting numbers\n");
    // printf("First int:");
    // scanf("%d", &a);
    // printf("Second int:");
    // scanf("%d", &b);
    // printf("Result: %d\n", sum(a,b));
    
    // // STRUCT
    // struct person p1 = makePerson("Your Mom",45);
    // printf("THEIR name is %s, and they are %d years old.\n",p1.name, p1.age);

    // // ********************* STATIC *******************************
    // STATIC FUNCTION
    // FUNCTION from this file:
    // staticFunc() of the same name can be both in grandparent.c and grandparent.h
    // staticFunc();

    // // STATIC LOCAL VAR
    // Static local variable's value persits until the end of the program
    // countLocalStatic();
    // countLocalStatic();
    // countLocalStatic();

   // //********************* EXTERN ***************************
    // EXTERN
    // Extern keyword allows you variables to be accessed by other c files

   // // THE BELOW WON'T WORK, because at this point of calculation, candies is an incomplete type, it's just a pointer to the array
    // int candy_num = sizeof(candies) / sizeof(candies[0]);

    // EXTERN VARIABLE
    // Therefore we must store the array length separately
    // for( int i =0; i < candies_len; i++ ){
    //     printf("%s\n",candies[i]);
    // }

    // // EXTERN VAR
    // int number;
    // printf("%d",sum(number,3));
    
    // // EXTERN FUNCTION (NOT NEEDED), FUNCTIONS ARE EXTERNAL BY DEFAULT
    // takeCandies(candies[0]);
    // printf("This is: %d\n",sum(5,3));

    // // RECURSION
    // printf("%ld\n",factorial(4));

    // // ******************** UNIONS **********************
    // // LIKE STRUCTURE, but CAN ONLY HOLD ONE VARIABLE AT A TIME
    // union package pack1;
    // pack1.num = 5;
    // pack1.str = "Hey there Delilah";

    // printf("%d\n",pack1.num);  // result in garbage value, because memory used for num is now used for str
    // printf("%s\n",pack1.str); // work as usual

    // // UNIONS w/ TYPEDEF - REPLACE union package with u2
    // typePackage pack2;
    // pack2.num = 5.325;
    // pack2.arr[0] = "Donald";
    // pack2.arr[1] = "Duck";
    // pack2.arr[2] = "CrayCray";
    // printf("%f\n", pack2.num);
    // printf("%s\n", pack2.arr[0]);

    // // ******************** STRUCTURE **********************
    // // Can't have methods of their own
    // struct person donald;
    // donald.name = "Donald Duck";
    // donald.age = 32;
    // printf("%s's age is %d\n",donald.name,donald.age);

    // struct person alice = {25,"Alice"};
    // printf("%s's age is %d\n",alice.name,alice.age);
    // // printf("size of person2 is %ld\n",sizeof(alice));  // give 16, 4 for int, 8 for str, 4 extra
    
    // // POINTER to STRUCTURE
    // struct person *ptr_person = &alice;

    // // DEREFERENCE to read attributes 
    // printf("Pointer's person name is: %s\n", (*ptr_person).name);
    // printf("Pointer's person age is: %d\n", (*ptr_person).age);

    // // ALTERNATIVE DEREFERENCE to read attributes
    // printf("Pointer's person name is: %s\n", ptr_person->name);
    // printf("Pointer's person age is: %d\n", ptr_person->age);

    // // REASSIGN pointer's value to Donald person 
    // printf("Reassigning pointer from Alice to Donald\n\n");
    // (*ptr_person) = donald;
    // printf("Pointer's person name is: %s\n", ptr_person->name);
    // printf("Pointer's person age is: %d\n", ptr_person->age);


}

// // static void staticFunc(){
//     printf("static called in main");
// }

// int sum(int a, int b){
//     return a+b;
// };

// void countLocalStatic(){
//     static int count = 0;
//     printf("Count: %d\n",count++);
// }

// RECURSIVE
// long factorial(long n){
//     if (n ==0) return 1;
//     return n*factorial(n-1);
// }



