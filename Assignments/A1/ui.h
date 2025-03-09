
#pragma once
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
#include <stdbool.h>

#include "state.h"

enum USER_RESPONSE get_response();
void display_welcome_msg(enum MODES mode);
void display_summary(bool match_found, int total_swap_count, int total_line_changed, enum EXIT_TYPE exit_type);