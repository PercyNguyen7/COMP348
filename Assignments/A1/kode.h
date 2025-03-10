#pragma once
#include "state.h"
#include <stdbool.h>

enum MODES assign_mode(char *command);

void verify_all_input(char *command, char *word, char *file_name, char *extra);

int start_program(enum MODES mode, char *word, FILE *ftpr);
