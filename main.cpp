#include <stdio.h>
#include "Grafo.h"

int main() {
    No no1 = No(3);
    No no2 = No(5);
    No no3 = No(2);
    No no4 = No(7);
    No no5 = No(9);

// cria um grafo de 5 vértices, com aparencia de casinha
    Grafo *grafo = new Grafo(&no1);
    grafo->adicionarAresta(&no1, &no2);
    grafo->adicionarAresta(&no1, &no5);
    grafo->adicionarAresta(&no2, &no5);
    grafo->adicionarAresta(&no2, &no3);
    grafo->adicionarAresta(&no3, &no4);
    grafo->adicionarAresta(&no4, &no5);

    printf("%d \n", &no5);
    printf("%d", grafo->buscaLargura(9));
    
    return 0;
}