#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  printf("----------------------------\n");
  printf("String operations\n");
  printf("----------------------------\n");

  // Length of a string
  char *str = "foobar";
  printf("Length of 'foobar': %d\n", strlen(str));
  printf("----------------------------\n");

  // Compare two strings for equality
  char str1[12] = "Hello";
  char str2[12] = "World!";

  printf("Comparing strings: %s and %s\n", str1, str1);
  if (strncmp(str1, str1, strlen(str1)) == 0)
    printf("Strings are equal\n");
  else
    printf("Strings are not equal\n");
  printf("----------------------------\n");

  printf("Comparing strings: %s and %s\n", str1, str2);
  if (strcmp(str1, str2) == 0) {
    printf("Strings are equal\n");
  } else if (strcmp(str1, str2) < 0) {
    printf("First string has smaller length\n");
  } else {
    printf("Second string has smaller length\n");
  }
  printf("----------------------------\n");

  // Copying string
  char str3[6];
  strcpy(str3, str1);
  printf("Copied '%s' into str3: '%s'\n", str1, str3);

  printf("----------------------------\n");

  // Concatenating strings
  char str4[12];
  strcpy(str4, str1);
  strcat(str4, str2);
  printf("Concatenating '%s' and '%s' into str4: '%s'\n", str1, str2, str4);

  printf("----------------------------\n");

  // Find a character in string
  const char string[] = "HelloWorld!";
  const char character = 'Hello';
  char *ret;
  ret = strchr(string, character);
  printf("String after |%c| is - |%s|\n", character, ret);

  printf("----------------------------\n");

  return 0;
}
