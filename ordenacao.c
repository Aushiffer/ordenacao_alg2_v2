#include <stdint.h>
#include "ordenacao.h"
#include "aux.h"

void getNome(char nome[]) {
    // substitua por seu nome
    strncpy(nome, "Caio Eduardo Ferreira de Miranda", MAX_CHAR);
    // adicionada terminação manual para caso de overflow
    nome[MAX_CHAR - 1] = '\0';
}

// a função a seguir deve retornar o seu número de GRR
uint32_t getGRR() { return 20232359; }

uint64_t mergeSort(int vetor[], size_t tam) {
	uint64_t numComps = 0;

	mergeSortWrapper(vetor, 0, tam - 1, &numComps);

	return numComps;
}

uint64_t quickSort(int vetor[], size_t tam) {
	uint64_t numComps = 0;

	quickSortWrapper(vetor, 0, tam, &numComps);

	return numComps;
}

uint64_t heapSort(int vetor[], size_t tam) {
	uint64_t numComps = 0;

	constroiMaxHeap(vetor, tam, &numComps);

	for (ssize_t i = tam - 1; i > 0; i--) {
		troca(vetor, 0, i);
		maxHeapify(vetor, 0, i, &numComps);
	}

	return numComps;
}

uint64_t mergeSortSR(int vetor[], size_t tam) {
	Pilha *p = criaPilha();
	uint64_t numComps = 0;

	mergeSortSRWrapper(vetor, 0, tam - 1, p, &numComps);
	destroiPilha(p);

	return numComps;
}

uint64_t quickSortSR(int vetor[], size_t tam) {
	Pilha *p = criaPilha();
	uint64_t numComps = 0;

	quickSortSRWrapper(vetor, 0, tam, p, &numComps);
	destroiPilha(p);

	return numComps;
}

uint64_t heapSortSR(int vetor[], size_t tam) {
	uint64_t numComps = 0;

	constroiMaxHeap(vetor, tam, &numComps);

	for (ssize_t i = tam - 1; i > 0; i--) {
		troca(vetor, 0, i);
		maxHeapifySR(vetor, 0, i, &numComps);
	}

	return numComps;
}