#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <list>  //lista para no
#include <queue> // fila da busca

using namespace std;

class Grafo {
	int tamanho; // número de vértices

    // cada vértice é um nó
    // a posição 0 contem o dado e as demais os adjacentes
	std::vector<std::list<int>> *listadeNos;

public:
	Grafo(int vertices) {
        this->tamanho = vertices; // número de vértices       
    }

    void definirNo (int posicao, int dado) {
        if(listadeNos[posicao].empty()) {
            listadeNos[posicao].push_back(dado);
        }
    }

	void adicionarAresta(int v1, int v2) {
    // adiciona vértice v2 à lista de vértices no de v1 se não estiver vazio
        if(!listadeNos[v1].empty()) {
            listadeNos[v1].push_back(v2);
        }
    }

	void buscaLargura(int vertice) {
        queue<int> fila; // fila para visitar
        bool visitados[tamanho]; // checks

    // setar tudo no vetor para false
        for(int i = 0; i < tamanho; i++) {
            visitados[i] = false;
        }
		
        printf("Visitando vertice %d \n", vertice);
	    visitados[vertice] = true;

	    while(true) {
		    list<int>::iterator iterador;

		    for(iterador = listadeNos[vertice].begin(); iterador != listadeNos[vertice].end(); iterador++) {
			    if(!visitados[*iterador]) {
                    printf("Visitando vertice %d \n", *iterador);
				    visitados[*iterador] = true; 
				    fila.push(*iterador); // bota na fila
                }
            }

            // verifica se a fila NÃO está vazia
            if(!fila.empty()) {
                vertice = fila.front(); // obtém o primeiro elemento
                fila.pop(); // remove da fila
            } else {
                break;
            }
	    }
    }
};

#endif