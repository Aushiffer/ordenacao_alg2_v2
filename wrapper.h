#ifndef __WRAPPER__
#define __WRAPPER__

#include "aux.h"
#include "pilha.h"

/* Wrapper do merge sort, criado para facilmente ordenar o vetor */
void mergeSortWrapper(int *vetor, size_t a, size_t b, uint64_t *numComps);

/* Wrapper do quicksort, criado para facilmente ordenar o vetor */
void quickSortWrapper(int *vetor, size_t a, size_t b, uint64_t *numComps);

/* Wrapper do merge sort sem recursão, criado para facilmente ordenar o vetor */
void mergeSortSRWrapper(int *vetor, size_t a, size_t b, Pilha *p, uint64_t *numComps);

/* Wrapper do quicksort sem recursão, criado para facilmente ordenar o vetor */
void quickSortSRWrapper(int *vetor, size_t a, size_t b, Pilha *p, uint64_t *numComps);

#endif // __WRAPPER__