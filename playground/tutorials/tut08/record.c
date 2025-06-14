#include "record.h"
#include <stdio.h>
#include <string.h>

void print_records(struct record *records, int number_of_records) {
  printf("------------------------\n");
  for (int i = 0; i < number_of_records; i++) {
    printf("%s %s\n", records[i].first_name, records[i].last_name);
  }
  printf("------------------------\n");
  printf("\n");
}

int first_name_comparator(const void *record1, const void *record2) {
  struct record *r1 = (struct record *)(record1);
  struct record *r2 = (struct record *)(record2);
  return strcmp(r1->first_name, r2->first_name);
}

int last_name_comparator(const void *record1, const void *record2) {
  struct record *r1 = (struct record *)(record1);
  struct record *r2 = (struct record *)(record2);
  return strcmp(r1->last_name, r2->last_name);
}
