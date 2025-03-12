#include<stdio.h>

int main(int argc, char const *argv[])
{
     // Clockwise/spiral rule
    int int_var_1 = 5;              // can be reassigned
    int int_var_2 = 10;             
    const int const_int_var = 10;   // cannot be reassigned, compiler error
    
    // Regular pointer          
    int* ptr_int_var = &int_var_1;  // ptr can be reassigned, int value can be reassigned
    ptr_int_var = &int_var_2;       // re-assigning ptr to point to different int var
    *ptr_int_var = 20;              // re-assigning underlying int var

    // constant pointer to const int
    const int * const const_int_const_ptr = &const_int_var;    // note that the pointer can point to const / non-const (regular) int value  
    const_int_const_ptr = &int_var_2;   // ptr cannot be re-assigned
    *const_int_const_ptr = 10;          // int value cannot be reassigned

    // pointer to int constant (i.e. constant int)
    const int *ptr_int_const = 10;
    *ptr_int_const = 15;                // int value cannot be reassigned
    ptr_int_const = &int_var_1;         // ptr can be reassigned to non-const (regular) int
    ptr_int_const = &const_int_var;     // ptr can be reassgined to const int

    // pointer to constant int (same as the last case)
    int const * ptr_const_int = 20;
    *ptr_const_int = 15;                // int value cannot be reassigned
    ptr_const_int = &int_var_1;         // ptr can be reassigned to non-const (regular) int
    ptr_const_int = &const_int_var;     // ptr can be reassgined to const int

    // constant pointer to int      
    int * const const_ptr_int = 10;
    const_int_const_ptr = &int_var_1;   // ptr cannot be reassigned 
    *const_int_const_ptr = int_var_2;   // underlying int value can be reassigned    
    return 0;
    
}
