#include "HeapFunctions.h"

int main(){
    Heap *requestsHeap = malloc(sizeof(Heap));
    printf("Now we want to insert the values in this heap!\n");
    requestsHeap = createTheHeap();
    requestsHeap = insertInHeapUtil(requestsHeap);
    int size = requestsHeap -> size;
    for(int i=0; i<size; i++){
        printf("%d ", requestsHeap -> heapArray[i]);
    }
    printf("\n");
    requestsHeap = heapsort(requestsHeap);
    for(int i=0; i<size; i++){
        printf("%d ", requestsHeap -> heapArray[i]);
    }
    return 0;
}