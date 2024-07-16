#ifndef __PILHA__
#define __PILHA__

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

/* Nodo da pilha, guarda um inteiro e um ponteiro para o próximo nodo */
typedef struct Nodo {
        struct Nodo *prox;
        int dado;
} Nodo;

/* Pilha de inteiros */
typedef struct {
        Nodo *topo;
        uint64_t tam;
} Pilha;

/* Cria um novo nodo */
Nodo *criaNodo(int x);

/* Cria uma pilha que acomoda nodos */
Pilha *criaPilha(void);

/* Desempilha o topo da pilha */
int desempilha(Pilha *p);

/* Empilha um nodo com um dado 'x' no topo da pilha. Retorna 0 se executar com sucesso e 1 se isso não ocorrer */
unsigned char empilha(Pilha *p, int x);

/* Checa se a pilha está vazia */
unsigned char pilhaVazia(Pilha *p);

/* Libera toda a memória usada pela pilha */
void destroiPilha(Pilha *p);

#endif // __PILHA__