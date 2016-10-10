#include <stdio.h>
#include <stdlib.h>
//simples
void SelectSort(int *, int, clock_t*);
void InsertSort(int *, int, clock_t*);
void BubbleSort(int *, int, clock_t*);
//complexos
void MergeSort(int*, int, clock_t*);
void MSort(int, int, int*, clock_t*);
void Merge(int*, int, int, int, clock_t*);

void ShellSort(int *, int);

void Partition(int, int, int *, int *, int *);
void QSort(int, int, int *);
void QuickSort(int *, int);

void Construct(int *, int);
void Reconstruct(int, int, int *);
void HeapSort(int *, int);
