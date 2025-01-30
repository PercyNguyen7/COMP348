#include <stdio.h>
// #include "point.h"
#include "point_utils.h"
#include "point_utils.h"

int main(int argc, char* argv[]) {
    Point p = new_point();
    printf("x: %d, y: %d\n", p.x, p.y);
    return 0;
}


// gcc main.c point_utils.c -o main