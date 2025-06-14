#include<stdio.h>

void print_var_with_ptr(const void* var_ptr, char t) {
    // Switch on value of t
    // Type-cast the void* pointer  <type>* pointer where type can be int, float or char
    // Deference the type-casted pointer with * (type-casting indicates the number of bits to be accessed, more about that in memory allocation)

    switch(t) {
        case 'i':
            int* int_ptr = (int *)var_ptr;
            printf("int_var: %d, &int_var: %p\n", *int_ptr, int_ptr);   
            break;
        case 'f':
            float* float_ptr = (float *)var_ptr;
            printf("float_var: %f, &float_var: %p\n", *float_ptr, float_ptr);
            break;
        case 'c':
            char* char_ptr = (char *)var_ptr;
            printf("char_var: %c, &char_var: %p\n", *char_ptr, char_ptr);
            break;
    }
}

int main(int argc, char const *argv[])
{
    printf("--------------------------------\n");
    printf("Pointers\n");
    printf("--------------------------------\n");

    int int_var = 10;
    float float_var = .5e-2;
    char char_var = 'b';

    int *ptr_int_var = &int_var;
    float *ptr_float_var = &float_var;
    char *ptr_char_var = &char_var;

    // Size of types and their pointers 
    printf("Size of types and their pointers\n");
    printf("sizeof(int): %ld, sizeof(int*):%ld\n", sizeof(int), sizeof(int*));
    printf("sizeof(float): %ld, sizeof(float*):%ld\n", sizeof(float), sizeof(float*));
    printf("sizeof(char): %ld, sizeof(char*):%ld\n", sizeof(char), sizeof(char*));
    printf("--------------------------------\n");

    // Pointer are used to pass arguments to functions by reference
    // function can be called as print_var_with_ptr (&t_var, "t") or (ptr_t_var, "t")
    printf("Passing function arguments as references\n");
    print_var_with_ptr(&int_var, 'i');  
    print_var_with_ptr(ptr_float_var, 'f');
    print_var_with_ptr(&char_var, 'c');  
    printf("--------------------------------\n");  
    
    return 0;
}
