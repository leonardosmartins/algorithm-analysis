#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define tam_balde 100
#define num_balde 10000
#define max 10

typedef struct {
    int topo;
    int balde[tam_balde];
}balde;


void bucketSort(int * vector, int size);

void showVector(int * vector, int size);

int belong(int * vector,int size, int element);

double average(double * vector);

void copyVector(int * vector, int * newVector, int size);

void generateRandomDCR(int size, int percentage,int * vector);

void generateRandomCRS(int size, int percentage, int * vector);

void insertionSort(int * original, int size);

void merge(int * vector, int start, int mid, int end);
void mergeSort(int * vector, int start, int end);

void rebuildHeap(int * vector, int limit, int pos);
void buildHeap(int * vector, int size);
void heapSort(int * vector, int size);

void quickSort(int * vector, int start, int end);

void radixSort(int * vector, int size);

void countingSort(int * vector, int size);

void bubbleSort(int * vector, int size);