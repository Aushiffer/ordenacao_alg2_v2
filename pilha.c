#include "pilha.h"

Nodo *criaNodo(int x) {
        Nodo *novoNodo = (Nodo *)malloc(sizeof(Nodo));

        if (!novoNodo)
                return NULL;

        novoNodo->dado = x;
        novoNodo->prox = NULL;

        return novoNodo;
}

unsigned char pilhaVazia(Pilha *p) {
        if (p->tam == 0)
                return 1;
        
        return 0;
}

unsigned char empilha(Pilha *p, int x) {
        Nodo *novoNodo = criaNodo(x);

        if (!novoNodo)
                return 1;
        
        novoNodo->prox = p->topo;
        p->topo = novoNodo;
        p->tam++;

        return 0;
}

Nodo *desempilha(Pilha *p) {
        if (pilhaVazia(p))
                return NULL;

        Nodo *salvaTopo = p->topo;
        p->topo = p->topo->prox;
        p->tam--;

        return salvaTopo;
}

Pilha *criaPilha(void) {
        Pilha *novaPilha = (Pilha *)malloc(sizeof(Pilha));

        if (!novaPilha)
                return NULL;

        novaPilha->topo = NULL;
        novaPilha->tam = 0;

        return novaPilha;
}