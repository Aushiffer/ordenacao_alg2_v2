#ifndef __WRAPPER__
#define __WRAPPER__

#include <sys/types.h>
#include "aux.h"

/* Wrapper do merge sort, criado para facilmente ordenar o vetor */
void mergeSortWrapper(int *vetor, size_t a, size_t b, u_int64_t *numComps);

/* Wrapper do quicksort, criado para facilmente ordenar o vetor */
void quickSortWrapper(int *vetor, size_t a, size_t b, u_int64_t *numComps);

#endif // __WRAPPER__