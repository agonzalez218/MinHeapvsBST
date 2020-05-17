#include <stdio.h>
#include <stdlib.h>
#include "minheap.h"

Heap *createHeap(int capacity, int data)
{
  Heap *h = (Heap *)malloc(sizeof(Heap));
  h->data = data;
  h->count = 0;
  h->capacity = capacity;
  h->arr = (int *) malloc(capacity*sizeof(int));
  return h;
}

void insertIntoMinHeap(Heap *h, int key){
  if( h->count < h->capacity)
  {
    h->arr[h->count] = key;
    heapBottomUp(h, h->count);
    h->count++;
  }
}

void heapBottomUp(Heap *h, int index){
  int temp;
  int parent = (index-1)/2;
  if(h->arr[parent] > h->arr[index])
  {
    temp = h->arr[parent];
    h->arr[parent] = h->arr[index];
    h->arr[index] = temp;
    heapBottomUp(h,parent);
  }
}

void heapTopDown(Heap *h, int parent){
  int left = parent*2+1, right = parent*2+2;
  int min, temp;
  if(left >= h->count || left < 0)
  {
    left = -1;
  }
  if(right >= h->count || right < 0)
  {
    right = -1;
  }
  if(left != -1 && h->arr[left] < h->arr[parent])
  {
    min=left;
  }
  else
  {
    min =parent;
  }
  if(right != -1 && h->arr[right] < h->arr[min])
  {
    min = right;
  }
  if(min != parent)
  {
    temp = h->arr[min];
    h->arr[min] = h->arr[parent];
    h->arr[parent] = temp;
    heapTopDown(h, min);
  }
}

int getMinFromMinHeap(Heap *h)
{
  int pop;
  pop = h->arr[0];
  return pop;
}

int minFromMinHeap( int size, int *data )
{
  int i = 0, min;
  Heap *heap = createHeap(size, 0);
  for(i = 0; i < size; i++)
  {
    insertIntoMinHeap(heap, data[i]);
  }
  min = getMinFromMinHeap(heap);
  free(heap->arr);
  free(heap);
  return min;
}