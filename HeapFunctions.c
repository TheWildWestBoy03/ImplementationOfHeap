#include "HeapFunctions.h"

Heap *insertInHeapUtil(Heap *heap){
    int requests[] = {10, 4, 29, 15, 44, 32, 36, 40, 39};
    for(int i=0; i<9; i++){
        printf("Where the segfault?\n");
        heap = insertInHeap(heap, requests[i]);
    }
    return heap;
}
Heap *insertInHeap(Heap *heap, int value){
    heap -> heapArray = (int*)malloc(sizeof(Heap) * heap -> capacity);
    if(heap -> capacity == heap -> size){
        heap -> heapArray = (int*)realloc(heap -> heapArray, sizeof(heap) * heap -> capacity * 2);
    }
    heap -> heapArray[heap->size ++] = value;
    heap = upHeapify(heap, heap -> size - 1);
    return heap;
}

Heap *upHeapify(Heap *heap, int position){
    if(position == 0){
        return heap;
    }
    if(heap -> heapArray[position] > heap -> heapArray[(position-1)/2]){
        int auxValue = heap -> heapArray[position];
        heap -> heapArray[position] = heap -> heapArray[(position-1)/2];
        heap -> heapArray[(position-1)/2] = auxValue;
        heap = upHeapify(heap, (position-1)/2);
    }
    return heap;
}
