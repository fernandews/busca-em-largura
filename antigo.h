#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>

using namespace std;

class No {
    public:
        int dado;

        // lista de nós adjacentes
        std::vector <No *> adjacentes;
        bool foivisitado = false;

        No(int elemento){
            this->dado = elemento;
        }

        void adicionarAdjacente(No *alvo) {
            adjacentes.push_back(alvo);

            return;
        }

        bool eAdjacente (No *alvo) {
            bool result = false;
            for (size_t i = 0; i < adjacentes.size(); i++) {
                if (adjacentes[i] == alvo) {
                    result = true;
                }
            }

            return result;
        }

        No *achaAdjacente (int alvo) {
            No *resultado = nullptr;

            for (size_t i = 0; i < adjacentes.size(); i++) {
                // adjacentes[i]->foivisitado = true;
                if (adjacentes[i]->dado == alvo) {
                    resultado = adjacentes[i];
                    break;
                }
            }
            return resultado;
        }
};

class Grafo {
    public:
        No *primeiro;
        int iterador = 0; 

        Grafo(No *primeiro) {
            this->primeiro = primeiro;
        }

        void adicionarAresta (No *origem, No *destino) {
            if (!origem->eAdjacente(destino)) {  
                origem->adicionarAdjacente(destino);
                destino->adicionarAdjacente(origem);
            }

            return;
        };

        No *buscaLargura(int valor) {
            No *resultado = nullptr;
            if (primeiro->achaAdjacente(valor) != nullptr) {
                resultado = primeiro->achaAdjacente(valor);
            }
            else {
                primeiro = primeiro->adjacentes[iterador];
                iterador++;
                this->buscaLargura(valor);
            }

            return resultado;
        }

};

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

    printf("%d \n", &no3);
    printf("%d", grafo->buscaLargura(2));
    
    return 0;
}

#endif