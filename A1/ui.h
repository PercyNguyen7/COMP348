#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wreplace.h"
 int confirmRes(int needConfirmation);
int removeWordCaseSens(char* word, char* fileName);
int removeWordCaseInsens(char* word, char* fileName);
int decode_word(char* word, char* fileName);
int decode_word_special(char* word, char* fileName);