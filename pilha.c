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

        if (!novoNodo) {
                fprintf(stderr, "empilha(): erro de criacao de nodo, retornando 1\n");

                return 1;
        }
        
        novoNodo->prox = p->topo;
        p->topo = novoNodo;
        p->tam++;

        return 0;
}

int desempilha(Pilha *p) {
        if (pilhaVazia(p)) {
                fprintf(stderr, "desempilha(): erro de stack underflow, retornando 0\n");

                return 0;       
        }
        
        int salvaDado = p->topo->dado;
        Nodo *aux = p->topo;
        p->topo = p->topo->prox;
        p->tam--;

        free(aux);

        return salvaDado;
}

void destroiPilha(Pilha *p) {
        while (!pilhaVazia(p))
                desempilha(p);

        free(p);
}

Pilha *criaPilha(void) {
        Pilha *novaPilha = (Pilha *)malloc(sizeof(Pilha));

        if (!novaPilha)
                return NULL;

        novaPilha->topo = NULL;
        novaPilha->tam = 0;

        return novaPilha;
}