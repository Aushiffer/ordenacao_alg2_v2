#include "aux.h"

void troca(int *vetor, size_t a, size_t b) {
        int aux = vetor[a];
        vetor[a] = vetor[b];
        vetor[b] = aux;
}

void maxHeapify(int *heap, size_t raizSubArvore, size_t tam, uint64_t *numComps) {
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

void constroiMaxHeap(int *vetor, size_t tam, uint64_t *numComps) {
        for (ssize_t i = (tam / 2) - 1; i >= 0; i--)
                maxHeapify(vetor, i, tam, numComps);
}

size_t particiona(int *vetor, size_t a, size_t b, uint64_t *numComps) {
        int pivo = vetor[b - 1];
        size_t indPivo = a;

        for (size_t i = a; i < b - 1; i++) {
                (*numComps)++;

                if (vetor[i] <= pivo) {
                        troca(vetor, i, indPivo);

                        indPivo++;
                }
        }

        troca(vetor, indPivo, b - 1);

        return indPivo;
}

void intercala(int *vetor, size_t a, size_t m, size_t b, uint64_t *numComps) {
        size_t tamVetorEsq = m - a + 1;
        size_t tamVetorDir = b - m;
        int *E = (int *)malloc(tamVetorEsq * sizeof(int));

        if (!E) {
                fprintf(stderr, "intercala(): erro de alocacao (E)\n");

                return;
        }

        int *D = (int *)malloc(tamVetorDir * sizeof(int));

        if (!D) {
                fprintf(stderr, "intercala(): erro de alocacao (D)\n");

                return;
        }

        for (size_t i = 0; i < tamVetorEsq; i++)
                E[i] = vetor[a + i];

        for (size_t j = 0; j < tamVetorDir; j++)
                D[j] = vetor[m + j + 1];

        size_t i = 0, j = 0, k = a;

        while (i < tamVetorEsq && j < tamVetorDir) {
                (*numComps)++;

                if (E[i] <= D[j]) {
                        vetor[k] = E[i];
                        i++;
                } else {
                        vetor[k] = D[j];
                        j++;
                }

                k++;
        }

        while (i < tamVetorEsq) {
                vetor[k] = E[i];
                i++;
                k++;
        }

        while (j < tamVetorDir) {
                vetor[k] = D[j];
                j++;
                k++;
        }

        free(E);
        free(D);
}

void preencheAleatorio(int *vetor, size_t tam) {
        int limAleatorio;

        printf("Entre com o valor pseudoaleatório máximo a ser considerado no vetor: ");
        scanf("%d", &limAleatorio);

        for (size_t i = 0; i < tam; i++)
                vetor[i] = rand() % limAleatorio;
}

void imprimeVetor(int *vetor, size_t tam) {
        for (size_t i = 0; i < tam; i++)
                printf("%d ", vetor[i]);

        printf("\n");
}