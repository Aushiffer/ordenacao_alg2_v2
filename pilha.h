#ifndef __PILHA__
#define __PILHA__

#include <stdio.h>

typedef struct Nodo {
        struct Nodo *prox;
        int dado;
} Nodo;

typedef struct {
        Nodo *topo;
        size_t tam;
} Pilha;

Nodo *criaNodo(int x);

Pilha *criaPilha(void);

void destroiPilha(Pilha *p);

#endif // __PILHA__