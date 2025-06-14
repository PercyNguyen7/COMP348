#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "_qsort.h"

// function to swap elements
//https://stackoverflow.com/questions/28511621/how-to-swap-memory-between-two-void-pointers-in-c
static void swap(void *array, int i, int j, size_t size)
{
    void *pc; 
    if ((pc = malloc(size)) == NULL)
    {
        printf("Cannot allocate memory");
        return;
    }
    //https://stackoverflow.com/questions/6449935/increment-void-pointer-by-one-byte-by-two
    // In gcc there is an extension which treats the size of a void as 1. 
    // so one can use arithematic on a void* to add an offset in bytes, 
    // but using it would yield non-portable code.
    memcpy(pc, array + i*size, size); 
    memcpy(array + i*size, array + j*size, size);
    memcpy(array + j*size, pc, size);
}

// function to find the partition position
static int partition(void* array, int low, int high, size_t size, comparator comparator_fn)
{

    // select the rightmost element as pivot
    void* pivot = array + high * size;

    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++)
    {
        // if (array[j] <= pivot)
        if (comparator_fn((void*)(array + j*size), pivot) <= 0)
        {

            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            swap(array, i, j, size);
        }
    }

    // swap the pivot element with the greater element at i
    swap(array, i + 1, high, size);

    // return the partition point
    return (i + 1);
}

// modified from : https://www.programiz.com/dsa/quick-sort
void quickSort(void* array, int low, int high, size_t size, comparator comparator_fn) 
{
    if (low < high)
    {

        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int pi = partition(array, low, high, size, comparator_fn);

        // recursive call on the left of pivot
        quickSort(array, low, pi - 1, size, comparator_fn);

        // recursive call on the right of pivot
        quickSort(array, pi + 1, high, size, comparator_fn);
    }
}

void _qsort(void *array, int nitems, size_t size, comparator comparator_fn) 
{
    int low = 0;
    int high = nitems - 1;
    quickSort(array, low, high, size, comparator_fn);
}