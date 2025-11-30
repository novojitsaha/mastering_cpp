// Complete allocate_scalar_array function
// Accept size and multiplier parameters and
//  should allocate an array of size integers on the heap.
// Gracefully return NULL if the allocation fails.
// Initialize each element in the array to the index * multiplier.
//  (e.g. a multiplier of 2 would result in [0, 2, 4, 6, ...])
// Return a pointer to the allocated memory.
// Assume that the calling code will eventually call free on the returned pointer.

#include <stdlib.h>
#include <stdio.h>

int *allocate_scalar_array(int size, int multiplier)
{
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    return arr;
}