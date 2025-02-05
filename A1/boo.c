#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Convert a word to lowercase (modifies in-place)
void toLowerCaseInPlace(char* word) {
    while (*word) {
        *word = tolower((unsigned char)*word);
        word++;
    }
}

// Finds case-insensitive occurrences of rep in orig
char* replace_word_ignore_case(char* orig, char* rep, char* with) {
    if (!orig || !rep) return NULL;

    int len_rep = strlen(rep);
    if (len_rep == 0) return NULL; // Prevent infinite loop
    if (!with) with = "";

    int len_with = strlen(with);

    // Create a lowercase copy of orig and rep for case-insensitive search
    char* orig_lower = strdup(orig);
    char* rep_lower = strdup(rep);
    if (!orig_lower || !rep_lower) return NULL;

    toLowerCaseInPlace(orig_lower);
    toLowerCaseInPlace(rep_lower);

    // Count occurrences of rep in orig (ignoring case)
    char* ins = orig_lower;
    int count = 0;
    char* tmp;
    while ((tmp = strstr(ins, rep_lower))) {
        count++;
        ins = tmp + len_rep;
    }

    // Allocate memory for the new string
    tmp = malloc(strlen(orig) + (len_with - len_rep) * count + 1);
    if (!tmp) return NULL;

    char* result = tmp;
    char* ins_orig = orig; // Original case-preserving pointer
    ins = orig_lower; // Lowercase pointer for searching

    while (count--) {
        char* pos = strstr(ins, rep_lower);
        int len_front = pos - ins;

        // Copy text before the match
        tmp = strncpy(tmp, ins_orig, len_front) + len_front;
        // Copy the replacement word
        tmp = strcpy(tmp, with) + len_with;

        // Move forward
        ins_orig += len_front + len_rep;
        ins += len_front + len_rep;
    }

    // Copy remaining part of orig
    strcpy(tmp, ins_orig);

    // Free temporary lowercase buffers
    free(orig_lower);
    free(rep_lower);
    return result;
}

int main() {
    char orig[] = "Hello WORLD! The world is a nice place.";
    char* new_str = replace_word_ignore_case(orig, "HEllo", "EARTH");

    if (new_str) {
        printf("Modified String: %s\n", new_str);
        free(new_str); // Free allocated memory
    }

    return 0;
}
