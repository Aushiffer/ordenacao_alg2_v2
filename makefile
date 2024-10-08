parametrosCompilacao= -g -Wall #-Wshadow
nomePrograma= trab2grr20232359

all: $(nomePrograma)

$(nomePrograma): main.o ordenacao.o aux.o wrapper.o pilha.o
	gcc -o $(nomePrograma) main.o ordenacao.o aux.o wrapper.o pilha.o $(parametrosCompilacao)

main.o: main.c
	gcc -c main.c $(parametrosCompilacao)

ordenacao.o: ordenacao.h ordenacao.c
	gcc -c ordenacao.c $(parametrosCompilacao)

aux.o: aux.h aux.c
	gcc -c aux.c $(parametrosCompilacao)

wrapper.o: wrapper.h wrapper.c
	gcc -c wrapper.c $(parametrosCompilacao)

pilha.o: pilha.h pilha.c
	gcc -c pilha.c $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
