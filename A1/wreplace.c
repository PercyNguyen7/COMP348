#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
char* censorWord(char* word){
  // Making censored word from input word
   int len = strlen(word);
   char *censoredWord = (char *)malloc((len + 1) * sizeof(char));
   if (censoredWord == NULL) {
       // Memory allocation failed
       printf("Memory allocation failed!\n");
       return NULL;
   }
   // Change each character to a * 
   for (int i =0; i < len; i++){
       censoredWord[i] = '*';
       if( i == len-1){
           censoredWord[i+1] ='\0' ;
       }
   }
   return censoredWord;
}

int isNotAlphaNumeric(char c) {
    return !isalnum(c);  // Non-alphanumeric characters are considered word boundaries
}
// Using the first char pointer and changing its character to lowercase
void toLowerCaseInPl(char *word) {
    while (*word) {           
        *word = tolower(*word);  
        word++;                  
    }
}
// second one return a dynamic string that is lower case
char* toLowerCase(char* word){
    int len = 0;
    while (word[len] != '\0') len++;

    char* lowerCaseWord = (char*)malloc(len);

    for (int i = 0; i < len; i++) {
        lowerCaseWord[i] = tolower(word[i]); // Convert each char
    }
    lowerCaseWord[len] = '\0';
    return lowerCaseWord;
}
// Loop over word, compare if str2 is a substring of str1
bool is_encoded_substring(const char* str1, const char* str2) {
    const char* temp = str1;
    size_t len2 = strlen(str2);
    
    while (*temp) {
        // Check if the substring from current position matches str2
        if (strncmp(temp, str2, len2) == 0) {
            // Ensure that the match is a whole word
            if ((temp == str1 || *(temp - 1) != '*' ) && *(temp+len2) !='*' ) {
                return true;
            }
        }
        temp++;
    }
    return false;
}
// bool isSubstring(const char* str1, const char* str2) {
//   const char* temp = str1;
//   size_t len2 = strlen(str2);
  
//   while (*temp) {
//       // Check if the substring from current position matches str2
//       if (strncmp(temp, str2, len2) == 0) {
//           // Ensure that the match is a whole word
//           if ((temp == str1 || isNotAlphaNumeric(*(temp - 1))) && (isNotAlphaNumeric(temp[len2]))) {
//               return true;
//           }
//       }
//       temp++;
//   }
//   return false;
// }

char *replace_word(char *before, char *old_word, char *new_word, int *swapCount){
  // get the lengths of the before string, old substring and new substring
  int old_length = strlen(old_word);
  int new_length = strlen(new_word);
  int before_length = strlen(before);
  
  // stores pointer to the dynamically allocated after string
  char *after;
  
  // if the length of the old substring is the same as the new substring, 
  // we can allocate space for the after string without doing any analysis 
  // of the before string beforehand
  if (old_length == new_length)
  {
    // allocate the same amount of space for the after string as the before
    // string (the +1 is for the null terminator)
    after = malloc((before_length + 1) * sizeof(char));
  }
  
  // i will keep track of our current index in the before string
  int i = 0;

  // j will keep track of our current index in the after string that we will 
  // now build
  int j = 0;
  
  // again we loop through the before string, just as above, but now we 
  // will build the after string as we do so
  while (i < strlen(before))
  {
    // if the first occurrence of the old substring in the before string 
    // from index i onwards occurs at index i, then we have found an 
    // occurrence of the substring at index i 
    if (strstr(&before[i], old_word) == &before[i] )
    {
        // printf("it worked at index %d\n", i);
      // we now copy into the after string AT INDEX J the new substring
      strcpy(&after[j], new_word);

      // we skip over old substring's amount of characters in the before string
      i += old_length;

      // but we add the new substring's amount of characters to j, because the 
      // length of the old and new substring's may be different... j may be less
      // or more than i, but we'll use it to keep track of where we are writing 
      // next into the after string
      j += new_length;
      if(swapCount != NULL) *swapCount +=1;
    }
    // if we did not find an occurrence of the old substring at index i in the 
    // before string, we copy the next character from the before string into the
    // after string (using the respective variables), and we increment the 
    // the indexes by 1 to move onto the next element in each array
    else
    {
      after[j] = before[i];
      i++;
      j++;
    }
  }
   // put a null terminator at the end of the after string
   after[j] = '\0';
   
   // return a pointer to the after string
   return after;
 }

char *replace_word_ignorecase(char *before, char *old_word, char *new_word, int *swapCount){
  // get the lengths of the before string, old substring and new substring
  int old_length = strlen(old_word);
  int new_length = strlen(new_word);
  int before_length = strlen(before);

  char* lower_old_word = toLowerCase(old_word);
  char* lower_before = toLowerCase(before);

  // stores pointer to the dynamically allocated after string
  char *after;

  if (old_length == new_length)  {

    after = malloc((before_length + 1) * sizeof(char));
  }
 
  // i will keep track of our current index in the before string
  int i = 0;

  // j will keep track of our current index in the after string that we will 
  // now build
  int j = 0;
  
  // again we loop through the before string, just as above, but now we 
  // will build the after string as we do so
  while (i < strlen(before))
  {
    // if the first occurrence of the old substring in the before string 
    // from index i onwards occurs at index i, then we have found an 
    // occurrence of the substring at index i 
    if (strstr(&lower_before[i], lower_old_word) == &lower_before[i] )
    {
        // printf("it worked at index %d\n", i);
      // we now copy into the after string AT INDEX J the new substring
      strcpy(&after[j], new_word);

      // we skip over old substring's amount of characters in the before string
      i += old_length;

      // but we add the new substring's amount of characters to j, because the 
      // length of the old and new substring's may be different... j may be less
      // or more than i, but we'll use it to keep track of where we are writing 
      // next into the after string
      j += new_length;
      if(swapCount != NULL) *swapCount +=1;
    }
    // if we did not find an occurrence of the old substring at index i in the 
    // before string, we copy the next character from the before string into the
    // after string (using the respective variables), and we increment the 
    // the indexes by 1 to move onto the next element in each array
    else
    {
      after[j] = before[i];
      i++;
      j++;
    }
  }
   // put a null terminator at the end of the after string
   after[j] = '\0';
   // return a pointer to the after string
   return after;
 }

char *decode_word_keep_case(char *before, char *word,  int *swapCount){
  // get the lengths of the before string, old substring and new substring

  int wordLen = strlen(word);
 char* censoredWord = censorWord(word);
  int before_length = strlen(before);
  
  // stores pointer to the dynamically allocated after string
  char *after;

  after = malloc((before_length + 1) * sizeof(char));
  int i = 0;
  int j = 0;
  
  while (i < strlen(before)) {

    if (strstr(&before[i], censoredWord) == &before[i] && before[i-1] != '*' && before[i+ wordLen] != '*') {
        // printf("it worked at index %d\n", i);
      // we now copy into the after string AT INDEX J the new substring
      strcpy(&after[j], word);
      i += wordLen;
      j += wordLen;

      if(swapCount != NULL) *swapCount +=1;
    }
    else {
      after[j] = before[i];
      i++;
      j++;
    }
  }
   // put a null terminator at the end of the after string
   after[j] = '\0';
   
   // return a pointer to the after string
   return after;
 }
// char *replace_word(char *before, char *old_word, char *new_word, int *swapCount){
//   // get the lengths of the before string, old substring and new substring
//   int old_length = strlen(old_word);
//   int new_length = strlen(new_word);
//   int before_length = strlen(before);
  
//   // stores pointer to the dynamically allocated after string
//   char *after;
  
//   // if the length of the old substring is the same as the new substring, 
//   // we can allocate space for the after string without doing any analysis 
//   // of the before string beforehand
//   if (old_length == new_length)
//   {
//     // allocate the same amount of space for the after string as the before
//     // string (the +1 is for the null terminator)
//     after = malloc((before_length + 1) * sizeof(char));
//   }
//   // otherwise we need to figure out how many times does the old substring 
//   // occur in the before string, and use that information to allocate enough
//   // space for the after string
//   else
//   {
//     // keeps track of occurrences of the old substring in the before string
//     int occurrences = 0;
    
//     // use i as the current position in the before string and loop through 
//     // the string until we reach the end of the string
//     int i = 0;
//     while (i < before_length)
//     {
//       // if the first occurrence of the old substring in the before string 
//       // from index i onwards occurs at index i, then we have found an 
//       // occurrence of the substring at index i
//       if ((strstr(&before[i], old_word) == &before[i]) )
//       {
//         // we increment the number of occurrences, and increment i by the 
//         // length of the old substring to skip over the old substring characters
//         occurrences++;
//         i += old_length;
//       }
//       // otherwise if we did not find an occurrence, increment i by 1 to check
//       // for an occurrence at the next index
//       else i++;
//     }
//      // IF wordCount isnt null, add it up!
  
//     // calculate the difference between the new and old substring lengths
//     int sub_diff = new_length - old_length;

//     // use the before string's length as a starting point for the after 
//     // string's length
//     int after_length = before_length;
    
//     // and now adjust the after string's length by the number of occurrences 
//     // in the before string multipled by the difference in length between 
//     // the new substring and the old substring (and keep in mind if the new 
//     // substring is less length than the old substring, it will be negative 
//     // and as appropriate after_length will be less than before_length)
//     after_length += occurrences * sub_diff;
    
//     // allocate space for the after string, accounting for the null terminator
//     after = malloc((after_length + 1) * sizeof(char));
//   }
  
//   // i will keep track of our current index in the before string
//   int i = 0;

//   // j will keep track of our current index in the after string that we will 
//   // now build
//   int j = 0;
  
//   // again we loop through the before string, just as above, but now we 
//   // will build the after string as we do so
//   while (i < strlen(before))
//   {
//     // if the first occurrence of the old substring in the before string 
//     // from index i onwards occurs at index i, then we have found an 
//     // occurrence of the substring at index i 
//     if (strstr(&before[i], old_word) == &before[i] && isNotAlphaNumeric(before[i-1])  && isNotAlphaNumeric(before[i+ old_length]))
//     {
//         // printf("it worked at index %d\n", i);
//       // we now copy into the after string AT INDEX J the new substring
//       strcpy(&after[j], new_word);

//       // we skip over old substring's amount of characters in the before string
//       i += old_length;

//       // but we add the new substring's amount of characters to j, because the 
//       // length of the old and new substring's may be different... j may be less
//       // or more than i, but we'll use it to keep track of where we are writing 
//       // next into the after string
//       j += new_length;
//       if(swapCount != NULL) *swapCount +=1;
//     }
//     // if we did not find an occurrence of the old substring at index i in the 
//     // before string, we copy the next character from the before string into the
//     // after string (using the respective variables), and we increment the 
//     // the indexes by 1 to move onto the next element in each array
//     else
//     {
//       after[j] = before[i];
//       i++;
//       j++;
//     }
//   }
//    // put a null terminator at the end of the after string
//    after[j] = '\0';
   
//    // return a pointer to the after string
//    return after;
//  }
// char *replace_word(char *orig, char *rep, char *with, int *wordCount) {
//     char *result; // the return string
//     char *ins;    // the next insert point
//     char *tmp;    // varies
//     int len_rep;  // length of rep (the string to remove)
//     int len_with; // length of with (the string to replace rep with)
//     int len_front; // distance between rep and end of last rep
//     int count;    // number of replacements
//     // sanity checks and initialization
//     if (!orig || !rep)
//         return NULL;
//     len_rep = strlen(rep);
//     if (len_rep == 0)
//         return NULL; // empty rep causes infinite loop during count
//     if (!with)
//         with = "";
//     len_with = strlen(with);
//     // count the number of replacements needed
//     ins = orig;
//     for (count = 0; (tmp = strstr(ins, rep)); ++count) {
//         ins = tmp + len_rep;
//     }
//     // IF wordCount isnt null, add it up!
//     if( wordCount != NULL) *wordCount+= count;
//     // Make space for tmp and result
//     tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);
//     if (!result)
//         return NULL;
//     // first time through the loop, all the variable are set correctly
//     // from here on,
//     //    tmp points to the end of the result string
//     //    ins points to the next occurrence of rep in orig
//     //    orig points to the remainder of orig after "end of rep"  
//     while (count--) {
//         ins = strstr(orig, rep);
//         len_front = ins - orig;
//         tmp = strncpy(tmp, orig, len_front) + len_front;
//         tmp = strcpy(tmp, with) + len_with;
//         orig += len_front + len_rep; // move to next "end of rep"
//     }
//     strcpy(tmp, orig);
//     return result;
// }





