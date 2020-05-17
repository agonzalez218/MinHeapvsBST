#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h> 
#include "BST.h"
#include "minheap.h"

#define MAX_SIZE 50000 // maximum array count, 
#define MIN_SIZE 10 // minimum array count
#define TEST_COUNT 4  // change amount of total tests with different array sizes done

void compareStructures();

int main()
{
  int i;
  srand( time( NULL ) );
  for( i = 0; i < TEST_COUNT; i++)
  {
    compareStructures();
    printf("\n");
  }
  
  return 0;
}

void compareStructures()
{
  clock_t start, end;
  int i, BSTMin = 0, MinHeapMin = 0;
  double time[4], average;
  int size = rand() % ( MAX_SIZE - MIN_SIZE + 1 ) + MIN_SIZE;
  int testData[size];
  for( i = 0; i < size; i++)
  {
    testData[ i ] = rand() % ( MAX_SIZE - 1 + 1 ) + 1;
  }
  for( i = 0; i < 4; i++)
  {
    start = clock();
    BSTMin = minFromBST(size, testData);
    end = clock();
    time[i] = (double)(end-start)/CLOCKS_PER_SEC;
  }
  average = (time[0]+time[1]+time[2]+time[3])/4;
  printf("Finding Minimum of Test Data with array size %d:\n", size);
  printf( "------------------------------------------------\n" );;
  printf("           Min       Test #1:       Test #2:       Test #3:       Time #4:      Average:\n");
  printf("BST:       %d         %lf       %lf       %lf       %lf      %lf\n", BSTMin, time[0], time[1], time[2], time[3], average);
  for( i = 0; i < 4; i++)
  {
    start = clock();
    MinHeapMin = minFromMinHeap(size, testData);
    end = clock();
    time[i] = (double)(end-start)/CLOCKS_PER_SEC;
  }
  average = (time[0]+time[1]+time[2])/3;
  printf("Min Heap:  %d         %lf       %lf       %lf       %lf      %lf\n", MinHeapMin, time[0], time[1], time[2], time[3], average);
}