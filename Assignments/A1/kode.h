#pragma once
#include <stdbool.h>
#include "state.h"
// #include "fileread.h"
// #include "wreplace.h"
// #include "ui.h"

// void switch()
enum MODES assign_mode(char* command);
void verify_all_input(char* command, char* word, char* file_name, char* extra);

int start_program(enum MODES mode, char* word, char* file_name);
