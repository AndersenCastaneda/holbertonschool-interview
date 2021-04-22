#ifndef HEAP_SORT
#define HEAP_SORT

#include <stdlib.h>

void print_array(const int *array, size_t size);

void heap_sort(int *array, size_t size);
void heapify(int *array, size_t s, size_t root, size_t size);

#endif
