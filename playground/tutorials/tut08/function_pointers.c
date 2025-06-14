#include <stdio.h>
#include <stdlib.h> // Default implementation of qsort()
#include <string.h>
#include "record.h"
#include "_qsort.h"

int main(int argc, char const *argv[])
{
    struct record records[5]= {
        {"Neverbean", "Seen"},
        {"Lazy", "Looser"},
        {"Couch", "King"},
        {"Nerd", "Herd"},
        {"Jelly", "Fish"}
    };

    printf("Before sorting -> \n");
    print_records(records, sizeof(records)/sizeof(records[0]));

    printf("After sorting by first name ->\n");
    _qsort(records, 5, sizeof(struct record), first_name_comparator);
    // qsort(records, 5, sizeof(struct record), first_name_comparator);
    print_records(records, sizeof(records)/sizeof(records[0]));

    printf("After sorting by last name ->\n");
    _qsort(records, 5, sizeof(struct record), last_name_comparator);
    // qsort(records, 5, sizeof(struct record), last_name_comparator);
    print_records(records, sizeof(records)/sizeof(records[0]));
    
    return 0;
}