#ifndef __AUX__
#define __AUX__

#include <stdio.h>
#include <sys/types.h>

/* Troca vetor[a] com vetor[b] */
void troca(int *vetor, size_t a, size_t b);

/* 'Max-heapifica' um vetor */
void maxHeapify(int *heap, size_t raizSubArvore, size_t tam, u_int64_t *numComps);

/* Constrói uma max-heap a partir de um vetor */
void constroiMaxHeap(int *vetor, size_t tam, u_int64_t *numComps);

/* Particiona um vetor e retorna o índice do pivô selecionado */
size_t particiona(int *vetor, size_t a, size_t b, u_int64_t *numComps);

/* Preenche um vetor com valores pseudoaleatórios */
void preencheAleatorio(int *vetor, size_t tam);

/* Imprime um vetor para a saída padrão */
void imprimeVetor(int *vetor, size_t tam);

#endif // __AUX__