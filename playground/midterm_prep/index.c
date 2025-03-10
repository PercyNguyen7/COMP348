#include <stdio.h>

#include <stdio.h>
void f(int *p, int *const q) {
  p = q;
  *p = 2;
}
void fun(int *ptr) { ptr++; }
int main() {
  //   char c[] = "GEEK2018";
  //   char *ptr = c;
  //   printf("Value of ptr is %c\n", *ptr);
  //   printf("ptr is %s, and strange: %c", ptr, *(ptr + ptr[3] - ptr[1]));

  // Q3
  //   int i = 0, j = 1;

  //   f(&i, &j);
  //   printf("%d %d", i, j);
  //   return 0;
  // Q4

  int y[] = {10, 20, 30};
  //   printf("ANSWER: %d", *y);
  fun(y);
  printf("ANSWER: %d", *(y + 1));
  return 0;
}
