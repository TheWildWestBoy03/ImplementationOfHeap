#include "HeapFunctions.h"

int main(){
    Heap *requestsHeap = malloc(sizeof(Heap));
    int numberOfInserts = 0, goodReq = 0;
    float sum = 0.0;
    printf("Now we want to insert the values in this heap!\n");
    requestsHeap = createTheHeap();
    requestsHeap = insertInHeapUtil(requestsHeap);
    int size = requestsHeap -> size;
    requestsHeap = heapsort(requestsHeap, &numberOfInserts);
    for(int i=0; i<size; i++){
        printf("%d ", requestsHeap -> heapArray[i]);
    }
    printf("\n");
    int i = size - 1;
    while(i > 0){
        if(sum + requestsHeap -> heapArray[i] < 176.10){
            sum += requestsHeap -> heapArray[i];
            goodReq ++;
        }
        i --;
    }
    float percent = goodReq * 1.00 / size;
    printf("%.3f", percent);
    return 0;
}