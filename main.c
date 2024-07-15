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
		fprintf(stderr, "main(): erro de alocacao de memoria\n");
		
		return 1;
	}	

	preencheAleatorio(vetor, tamVetor);
	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());
	imprimeVetor(vetor, tamVetor);	

	numComps = heapSortSR(vetor, tamVetor);

	imprimeVetor(vetor, tamVetor);	
	printf("NumComps: %d\n", numComps);
	free(vetor);

	return 0;
}
