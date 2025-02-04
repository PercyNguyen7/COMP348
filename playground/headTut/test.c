#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "h1.h"
#include "h2.h"
// #include "string_util.c"

// MACROS declaration, preprocessor step before compilation
// difference is when using a variable,
#define SIZE 5
#define PRODUCT(x,y) (x)*(y)
extern int var;
void counter() {
    static int count = 0;  // Initialized only once
    count++;
    printf("Count: %d\n", count);
}
int main(){
    // sum(3, 6);
    // h1Function(5);

    printf("%d",var);
    return 0;
}


