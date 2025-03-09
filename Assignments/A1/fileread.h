#pragma once
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
void check_file(FILE *fptr);

char* read_line(FILE *fptr);
void write_line(FILE *fptr, char* curr_str, char* new_str);
