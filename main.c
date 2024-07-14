#include <time.h>
#include "ordenacao.h"

int main(void) {
	char nome[MAX_CHAR];
	int numComps;	
	uint64_t tamVetor;

	srand(time(NULL));
	printf("Entre com o tamanho do vetor: ");
	scanf("%lu", &tamVetor);
	getchar();

	int *vetor = (int *)malloc(tamVetor * sizeof(int));

	if (!vetor) {
		printf("Falha fatal. Impossível alocar memoria.");
		
		return 1;
	}	

	preencheAleatorio(vetor, tamVetor);
	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());
	imprimeVetor(vetor, tamVetor);	

	numComps = heapSort(vetor, tamVetor);

	printf("NumComps: %d\n", numComps);
	imprimeVetor(vetor, tamVetor);	
	free(vetor);

	return 0;
}
