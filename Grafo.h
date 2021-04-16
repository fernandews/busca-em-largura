#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class No {
    public:
        int dado;

        // lista de nós adjacentes
        std::vector <No *> adjacentes;
        bool foivisitado;

        No(int elemento){
            this->dado = elemento;
            this->foivisitado = false;
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
};

class Grafo {
    public:
        No *primeiro;
        std::queue<No *> filaDeBusca;

        Grafo(No *primeiro) {
            this->primeiro = primeiro;
            filaDeBusca.push(primeiro);
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
            
            if (filaDeBusca.front()->dado == valor) {
                resultado = filaDeBusca.front();
                return resultado;
            }
            else {
                for (size_t i = 0; i < filaDeBusca.front()->adjacentes.size(); i++) {
                    filaDeBusca.push(filaDeBusca.front()->adjacentes[i]);
                }
                filaDeBusca.pop();
                this->buscaLargura(valor);
            }
        }

};

#endif