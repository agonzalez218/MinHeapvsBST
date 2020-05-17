#ifndef MINHEAP_H
#define MINHEAP_H
 
typedef struct Heap{
  int *arr;
  int count;
  int capacity;
  int data;
} Heap;
 
Heap *createHeap(int capacity,int data);
void insertIntoMinHeap(Heap *h, int key);
void printHeap(Heap *h);
void heapBottomUp(Heap *h,int index);
void heapTopDown(Heap *h, int parent);
int getMinFromMinHeap(Heap *h);
int minFromMinHeap( int , int * );
 
#endif