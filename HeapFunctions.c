#include "HeapFunctions.h"

Heap *insertInHeapUtil(Heap *heap)
{
    int requests[9] = {10, 4, 29, 15, 44, 32, 36, 40, 39};
    for (int i = 0; i < 9; i++)
    {
        heap = insertInHeap(heap, requests[i]);
    }
    return heap;
}
int maximum(int a, int b, int c){
    int maxim = a;
    if(maxim < b){
        maxim = b;
    }
    if(maxim < c){
        maxim = c;
    }
    return maxim;
}
Heap *createTheHeap()
{
    Heap *requestsHeap = (Heap *)malloc(sizeof(Heap));
    requestsHeap->capacity = 250;
    requestsHeap->heapArray = (int *)malloc(sizeof(int) * requestsHeap->capacity);
    requestsHeap->size = 0;
    return requestsHeap;
}

Heap *insertInHeap(Heap *heap, int value)
{
    if (heap->capacity == heap->size)
    {
        heap->heapArray = (int *)realloc(heap->heapArray, sizeof(Heap) * heap->capacity * 2);
    }
    heap->heapArray[heap->size] = value;
    heap = upHeapify(heap, heap->size);
    heap->size++;
    return heap;
}

Heap *upHeapify(Heap *heap, int position)
{
    if (position < 0)
    {
        return heap;
    }
    if (heap->heapArray[position] > heap->heapArray[(position - 1) / 2])
    {
        int auxValue = heap->heapArray[position];
        heap->heapArray[position] = heap->heapArray[(position - 1) / 2];
        heap->heapArray[(position - 1) / 2] = auxValue;
        heap = upHeapify(heap, (position - 1) / 2);
    }
    return heap;
}

Heap *downHeapify(Heap *heap, int position){
    if(position > (heap -> size) / 2)
        return heap;
    int currentNode = heap->heapArray[position];
    int leftChild = heap->heapArray[position * 2 + 1];
    int rightChild = heap->heapArray[position * 2 + 2];
    int maximumValue = maximum(currentNode, leftChild, rightChild);
    if(maximumValue == currentNode){
        return heap;
    }
    else{
        int maximOfChild = (leftChild > rightChild)? leftChild:rightChild;
        int auxValue = heap->heapArray[position];
        if(maximOfChild == leftChild){
            heap -> heapArray[position] = leftChild;
            heap -> heapArray[position * 2 + 1] = auxValue;
            heap = downHeapify(heap, position * 2 + 1);
        }
        else if(maximOfChild == rightChild){
            heap -> heapArray[position] = rightChild;
            heap -> heapArray[position * 2 + 2] = auxValue;
            heap = downHeapify(heap, position * 2 + 2);
        }
    }
    return heap;
}

Heap *heapsort(Heap *thisHeap){
   // int *sortedArray = (int*)malloc(sizeof(int) * thisHeap -> size);
    int sizeOfHeap = thisHeap -> size;
    for(int i=sizeOfHeap - 1; i>=0; i--){
        int auxValue = thisHeap -> heapArray[i];
        thisHeap -> heapArray[i] = thisHeap -> heapArray[0];
        thisHeap -> heapArray[0] = auxValue;
        thisHeap -> size --;
        thisHeap = downHeapify(thisHeap, 0);
    }   
    return thisHeap;
}