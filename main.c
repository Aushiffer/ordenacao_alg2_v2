#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

int main() {
    char nome[MAX_CHAR];
    int numComp;

    int tamVetor = 4;
    int *vetor = (int *)malloc(tamVetor * sizeof(int));
    if (vetor == NULL) {
        printf("Falha fatal. Impossível alocar memoria.");
        return 1;
    }

    vetor[0] = 12;
    vetor[1] = 10;
    vetor[2] = 1;
    vetor[3] = 2;

    getNome(nome);
    printf("Trabalho de %s\n", nome);
    printf("GRR %u\n", getGRR());

    numComp = heapSort(vetor, tamVetor);

    printf("NumComp: %d\n", numComp);
    imprimeVetor(vetor, tamVetor);

    free(vetor);

    return 0;
}
