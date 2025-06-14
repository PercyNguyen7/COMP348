#ifndef RECORD_H
#define RECORD_H

struct record {
    char first_name[20];
    char last_name[20];
};

void print_records(struct record * records, int number_of_records);

int first_name_comparator(const void *record1, const void *record2);
int last_name_comparator(const void *record1, const void *record2);

#endif // RECORD_H