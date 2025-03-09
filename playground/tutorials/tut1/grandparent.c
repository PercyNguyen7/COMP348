
#include "grandparent.h"
#include <stdio.h>

char* candies[] = {"sweet candy", "sour candy", "chewy candy"};
int candies_len = sizeof(candies) / sizeof(candies[0]);

int number =3;

void takeCandies(char* candy){
    printf("Taking %s\n", candy);
}



// static void staticFunc(){
//     printf("static called in GP");
// }