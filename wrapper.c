#include "wrapper.h"

void mergeSortWrapper(int *vetor, size_t a, size_t b, uint64_t *numComps) {
        if (a >= b)
                return;

        size_t meio = a + (b - a) / 2;

        mergeSortWrapper(vetor, a, meio, numComps);
        mergeSortWrapper(vetor, meio + 1, b, numComps);
        intercala(vetor, a, meio, b, numComps);
}

void quickSortWrapper(int *vetor, size_t a, size_t b, uint64_t *numComps) {
        if (a >= b)
                return;

        size_t indPivo = particiona(vetor, a, b, numComps);

        quickSortWrapper(vetor, a, indPivo, numComps);
        quickSortWrapper(vetor, indPivo + 1, b, numComps);
}