#include <stdio.h>
// #include <string.h>
void f(int *p, int *const q) {
  p = q;
  *p = 2;
}
void fun(int *ptr) {
  ptr++;
  printf("FUN: %d\n", *ptr);
}

int v_count_in_arr(int arr[], int size, int v) {
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] == v)
      count++;
  }
  return count;
}

void change_arg_val(int x) { x = 30; };

const char *strchr(const char *s, int c) {
  //   printf("This function is working: \n");
  for (; *s; s++) {
    if (*s == c)
      return s;
  }
  return NULL;
}
// void test(const char *s, int c) { printf("Current iteration: %d\n", c); }
const char *nvl(const char *s) {
  if (s == NULL) {
    printf("S IS NULL, s is |%s|And after\n", s);
  } else {
    printf("S IS NOT NULL, s is |%s|after\n", s);
  }
  return s == NULL ? "NULL" : s;
}

int main() {
  //   char c[] = "GEEK2018";
  //   char *ptr = c;
  //   printf("Value of ptr is %c\n", *ptr);
  //   printf("ptr is %s, and strange: %c", ptr, *(ptr + ptr[3] - ptr[1]));

  // Q3
  // LESSON
  // int *const p => constant integer pointer, may not be reassign to another
  // memory address, WHILE const *int p => integer pointer to a constant.
  // pointed value may not change
  //   int i = 0, j = 1;

  //   f(&i, &j);
  //   printf("%d %d", i, j);
  //   return 0;

  // Q4
  // LESSON: if you pass an int pointer and change its value, the original
  // pointer will remain the same.
  // int y[] = {10, 20, 30};
  // printf("MAIN: %d\n", *(y));
  // fun(y);
  // printf("MAIN: %d\n", *(y + 1));
  // return 0;

  // Q5 -------------------------
  // A. Write a function in C that receives three arguments: an array of
  // integers,
  // an integer representing the size of the array, and an arbitrary integer
  // value v. The function returns how many times the value v is presented in
  // the given array.

  // B. Declare an array of five numbers, two of which are zeros. Call the above
  // function and print the number of zeros.

  //   int arr[] = {1, 3, 0, 1, 0};
  //   int size = 5;
  //   printf("V's appearance is %d\n", v_count_in_arr(arr, size, 3));

  //   int arr[] = {10, 20, 30, 40, 50, 60};
  //   int *ptr1 = arr;
  //   int *ptr2 = arr + 3;
  //   printf("ptr1 is %p\n", ptr1);
  //   printf("ptr2 is %p\n", ptr2);
  //   printf("Difference: %ld\n", (ptr2 - ptr1));
  //   printf("In bytes: %ld\n", (char *)ptr2 - (char *)ptr1);

  // Q7
  //   char *ptr = "helloworld";
  //   char *ptr2 = "string 2";
  //   printf("%s\n", ptr + 1);

  // Q8
  //   int y = 20;
  //   change_arg_val(y);
  //   printf("After changing, it remains the same: %d\n", y);

  // strchr(123,0) points to the NULL terminator, so the resulting char would be
  // the null terminator \0, which IS NOT NULL
  //   printf("\nstrchr(123,0): %s\n", strchr("123sdzgweywery", 0));
  //   printf("This%s||\n", nvl(strchr("123", 0)));

  // int num = 3;
  // int *const ptr_num = &num;

  // *ptr_num = 4;
  // printf("Num is %d", num);
  char *string = "Hey THere!";
  string[2] = 'u';
  printf("string[] is %c", string[2]);
  return 0;
}
