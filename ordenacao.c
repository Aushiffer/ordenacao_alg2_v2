#include <string.h>
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
	uint64_t numComps = 0;
	size_t meio, b;
	
	for (size_t i = 1; i <= tam - 1; i *= 2) {
		for (size_t a = 0; a < tam - 1; a += i * 2) {
			meio = ((a + i - 1) < tam - 1) ? a + i - 1 : tam - 1;
			b = ((a + i * 2 - 1) < tam - 1) ? a + i * 2 - 1 : tam - 1;

			intercala(vetor, a, meio, b, &numComps);
		}
	}

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

	constroiMaxHeapSR(vetor, tam, &numComps);

	for (ssize_t i = tam - 1; i > 0; i--) {
		troca(vetor, 0, i);
		maxHeapifySR(vetor, 0, i, &numComps);
	}

	return numComps;
}