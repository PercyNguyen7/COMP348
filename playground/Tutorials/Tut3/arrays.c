#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[]) {
  printf("------------------\n");
  printf("Arrays\n");
  printf("------------------\n");

  // static memory allocation at compile-time
  int array_static[5] = {1, 2, 3, 4, 5};
  // dynamic memory allocation at run-time
  int n = 5;
  int *array_dynamic = (int *)malloc(sizeof(int) * n);
  // By default values are initialized to zero
  for (int i = 0; i < n; i++) {
    array_dynamic[i] = i;
  }

  // array_dynamic = {0, 1, 2, 3, 4}

  printf("Accessing using idx: \n");
  printf("array_static[2]: %d\n", array_static[2]);
  printf("array_dynamic[0]: %d\n", array_dynamic[0]);
  printf("Accessing using ptr: \n");
  // pointer arithmetic - integer pointer when incremented by n is actually
  // moved up by (n* sizeof(int)) number of bytes
  printf("array_static[3]: %d\n", *(array_static + 3));
  printf("array_dynamic[1]: %d\n", *(array_dynamic + 1));
  printf("------------------\n");

  // C exposes raw memory, no bounds checking
  printf("Accessing beyond the bounds of array: \n");
  printf("array_static[10] = %d\n", *(array_static + 4)); // using index
  //   printf("array_dynamic[15] = %d\n",
  //          *(array_dynamic + 15)); // using pointer arithmetic

  // Note: Why does dynamically allocated array show 0 for almost any index?
  //-> Heap allocation: on linux kernel, heap is zero-initialized for security
  printf("------------------\n");
  return 0;
}
