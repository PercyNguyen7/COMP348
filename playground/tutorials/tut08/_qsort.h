#ifndef QSORT_H
#define QSORT_H

typedef int (*comparator)(const void *, const void *);

void _qsort(void *array, int nitems, size_t size, comparator comparator_fn) ;

#endif // QSORT_H