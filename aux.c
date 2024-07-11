#include "aux.h"

void troca(int *vetor, size_t a, size_t b) {
        int aux = vetor[a];
        vetor[a] = vetor[b];
        vetor[b] = aux;
}

void maxHeapify(int *heap, size_t raizSubArvore, size_t tam, u_int64_t *numComps) {
        size_t filhoEsq = (raizSubArvore << 1) + 1;
        size_t filhoDir = (raizSubArvore << 1) + 2;
        size_t maior;

        if (filhoEsq < tam && heap[filhoEsq] > heap[raizSubArvore])
                maior = filhoEsq;
        else
                maior = raizSubArvore;

        if (filhoDir < tam && heap[filhoDir] > heap[maior])
                maior = filhoDir;

        (*numComps) += 2;

        if (maior != raizSubArvore) {
                troca(heap, maior, raizSubArvore);
                maxHeapify(heap, maior, tam, numComps);
        }
}

void constroiMaxHeap(int *vetor, size_t tam, u_int64_t *numComps) {
        for (ssize_t i = (tam / 2) - 1; i >= 0; i--)
                maxHeapify(vetor, i, tam, numComps);
}