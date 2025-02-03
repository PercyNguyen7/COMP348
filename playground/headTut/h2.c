#include <stdio.h>
#include <stdlib.h>

#include "h2.h"
Point new_point() {
    Point p = {
        .x = 1,
        .y = 1,
    };
    return p;
}

int sum(int a, int b){

    int sum  = a + h1Function(b);
    printf("Sum is %d\n", sum);
    return 0;
}