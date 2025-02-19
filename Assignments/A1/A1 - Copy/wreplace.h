#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int isNotAlphaNumeric(char c);
int confirmRes(int needConfirmation);
bool isSubstring(char* string, char* substring);
char *replace_word(char *orig, char *rep, char *with, int *wordCount) ;
char* censorWord(char* word);
char* toLowerCase(char* word);
void toLowerCaseInPl(char *str);
