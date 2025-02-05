#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int confirmRes(int needConfirmation);
char *replace_word(char *orig, char *rep, char *with, int *wordCount) ;
char* censorWord(char* word);
char* toLowerCase(char* word);
void toLowerCaseInPl(char *str);
