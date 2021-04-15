#include <stdio.h>
#include "Grafo.h"

int main() {
	Grafo grafo = Grafo(5);

	// adicionando as arestas
    grafo.definirNo(0, 8);
    grafo.definirNo(1, 6);
    grafo.definirNo(2, 4);
    grafo.definirNo(3, 2);
    grafo.definirNo(4, 0);
	grafo.adicionarAresta(0, 1);
	grafo.adicionarAresta(0, 2);
	grafo.adicionarAresta(1, 3);
	grafo.adicionarAresta(1, 4);

	grafo.buscaLargura(0);

	return 0;
}