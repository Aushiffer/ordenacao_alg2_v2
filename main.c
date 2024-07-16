#include <stdio.h>
#include <time.h>
#include "aux.h"
#include "ordenacao.h"

int main(void) {
	char nome[MAX_CHAR];
	uint64_t numComps;	
	uint64_t tamVetor;
	short seletor;
	unsigned char imprimir;
	int *vetor;

	srand(time(NULL));
	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());

	do {
		printf("\nSelecione uma opcao\n\n");
		printf("1: Quicksort recursivo\n");
		printf("2: Quicksort iterativo\n");
		printf("3: Merge sort recursivo\n");
		printf("4: Merge sort iterativo\n");
		printf("5: Heapsort recursivo\n");
		printf("6: Heapsort iterativo\n");
		printf("7: Encerrar\n");
		scanf("%hd", &seletor);
		getchar();

		if (seletor < 7 && seletor > 0) {
			printf("\nEntre com o tamanho do vetor: ");
			scanf("%lu", &tamVetor);
			getchar();
			printf("O vetor deve ser impresso antes e depois da ordenacao? (S para SIM): ");
			scanf("%c", &imprimir);
			getchar();

			vetor = (int *)malloc(tamVetor * sizeof(int));

			if (!vetor) {
				fprintf(stderr, "main(): falha fatal, impossivel alocar memoria\n");

				return 1;
			}
		
			preencheAleatorio(vetor, tamVetor);

			if (imprimir == 's' || imprimir == 'S') {
				printf("\n");
				imprimeVetor(vetor, tamVetor);
			}
		}

		switch (seletor) {
			case 1:
				numComps = quickSort(vetor, tamVetor);

				if (imprimir == 's' || imprimir == 'S')
					imprimeVetor(vetor, tamVetor);
				
				free(vetor);
				printf("\nComparacoes: %lu\n", numComps);
				printf("Pressione ENTER para continuar");
				getchar();

				break;
			
			case 2:
				numComps = quickSortSR(vetor, tamVetor);

				if (imprimir == 's' || imprimir == 'S')
					imprimeVetor(vetor, tamVetor);
				
				free(vetor);
				printf("\nComparacoes: %lu\n", numComps);
				printf("Pressione ENTER para continuar");
				getchar();

				break;

			case 3:
				numComps = mergeSort(vetor, tamVetor);

				if (imprimir == 's' || imprimir == 'S')
					imprimeVetor(vetor, tamVetor);
				
				free(vetor);
				printf("\nComparacoes: %lu\n", numComps);
				printf("Pressione ENTER para continuar");
				getchar();

				break;

			case 4:
				numComps = mergeSortSR(vetor, tamVetor);

				if (imprimir == 's' || imprimir == 'S')
					imprimeVetor(vetor, tamVetor);
				
				free(vetor);
				printf("\nComparacoes: %lu\n", numComps);
				printf("Pressione ENTER para continuar");
				getchar();

				break;
			
			case 5:
				numComps = heapSort(vetor, tamVetor);

				if (imprimir == 's' || imprimir == 'S')
					imprimeVetor(vetor, tamVetor);
				
				free(vetor);
				printf("\nComparacoes: %lu\n", numComps);
				printf("Pressione ENTER para continuar");
				getchar();

				break;

			case 6:
				numComps = heapSortSR(vetor, tamVetor);

				if (imprimir == 's' || imprimir == 'S')
					imprimeVetor(vetor, tamVetor);
				
				free(vetor);
				printf("\nComparacoes: %lu\n", numComps);
				printf("Pressione ENTER para continuar");
				getchar();

				break;

			case 7:
				break;
			
			default:
				printf("\nOpcao invalida\n");

				break;
		}
	} while (seletor != 7);

	return 0;
}
