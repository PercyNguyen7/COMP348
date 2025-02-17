#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wreplace.h"
 int confirmRes(int needConfirmation);
void removeWordCaseSens(char* word, char* fileName);
void removeWordCaseInsens(char* word, char* fileName);
void decode_word(char* word, char* fileName);