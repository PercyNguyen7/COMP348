#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  // Calling strlen on a string that has '\0'
  char *string = "abcd\0abcd";
  printf("Length of abcd\\0abcd: %d\n", strlen(string));
  // Question: What will be the output of : printf("%s", string)?
  // Question: Can char strings be used to store binary data, say an image file?
  // Question: How can we work with strings that have '\0' in them? -> UNICODE
  // (utf-8 is backward compatible with ASCII)

  // Using a short buffer for strcpy

  char str1[9] = "12345678";
  // printf("Before\n");
  // printf("str1: %s\n", str1);
  char str2[9]; // Change this from 5 to 9 during demo
  strcpy(&str2, &str1);
  printf("After\n");
  printf("str1: %s\n", str1);
  printf("str2 (copy): %s\n", str2);
  // This seems to work.. so what is the problem here?
  // Printing str1 reveals the problem
  // Since enough memory wasn't allocated to str2, the overflow messed up str1

  // strncpy ensures this sort of problem doesn't occur
  char test_str_1[9] = "abcdefgh";
  char test_str_2[2];
  strcpy(test_str_2, test_str_1);
  printf("test_str_1: %s\n", test_str_1);
  printf("test_str_2 (copy): %s\n", test_str_2);

  return 0;
}
