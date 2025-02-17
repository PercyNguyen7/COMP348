#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileread.h"
char* read_line(char* fileName, int targetLine);
void write_line(char* fileName, int targetLine, char* str);
char** get_strings(int*);
void readFileLines(const char* fileName);
