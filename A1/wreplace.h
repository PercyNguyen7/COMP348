#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
int isNotAlphaNumeric(char c);
int confirmRes(int needConfirmation);
bool is_encoded_substring(char* string, char* substring);
char *replace_word(char *orig, char *rep, char *with, int *wordCount);
char *replace_word_ignorecase(char *orig, char *rep, char *with, int *wordCount);
char *decode_word_keep_case(char *before, char *word,  int *swapCount);
char *decode_word_match_case(char *before, char *word,  int *swapCount);
char* censorWord(char* word);
char* toLowerCase(char* word);
char* toUpperCase(char* word);

void toLowerCaseInPl(char *str);
