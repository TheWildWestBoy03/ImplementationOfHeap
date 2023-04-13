#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Heap{
    int capacity, *heapArray, size;
}Heap;
Heap *heapsort(Heap *thisHeap);
Heap *createTheHeap();
Heap *insertInHeapUtil(Heap *heap);
Heap *insertInHeap(Heap *heap, int value);
Heap *upHeapify(Heap *heap, int position);