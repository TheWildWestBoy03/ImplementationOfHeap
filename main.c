#include "HeapFunctions.h"

int main(){
    Heap *requestsHeap = malloc(sizeof(Heap));
    requestsHeap -> size = 0;
    requestsHeap -> capacity = 250;
    printf("Now we want to insert the values in this heap!\n");
    insertInHeapUtil(requestsHeap);
}