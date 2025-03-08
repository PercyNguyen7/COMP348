//Vinh Tuan Dat NGUYEN
//40180660 
//Assignment 1
//Prof Ali Jannatpour
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
//helper functions
int isNotAlphaNumeric(char c);
void to_lowercase_in_place(char *str);
char* to_lowercase(char* word);
char* toUpperCase(char* word);
char* censorWord(char* word);
bool is_encoded_substring(char* string, char* substring);
bool substring_found(int mode, char* str, char* word);

//major functions
char* process_string(int mode, char* curr_string, char* word, int* pt_swap_count);
char *redact_word(char *str, char *word, int *wordCount);
char *redact_word_ignorecase(char *before, char *word,  int *pt_swap_count);
char *decode_word_keep_case(char *before, char *word,  int *pt_swap_count);
char *decode_word_match_case(char *before, char *word,  int *pt_swap_count);



