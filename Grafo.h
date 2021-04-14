#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>

using namespace std;

class No {
    public:
        int dado;

        // lista de nós adjacentes
        No *adjacentes[6];
        int size = 0;

        // bool da busca
        bool foivisitado = false;

        No(int elemento){
            this->dado = elemento;
        }

        void adicionarAdjacente(No *alvo) {
            adjacentes[size] = alvo;
            size++;

            return;
        }

        bool eAdjacente (No *alvo) {
            bool result = false;
            for (size_t i = 0; i < size; i++) {
                if (adjacentes[i] == alvo) {
                    result = true;
                }
            }

            return result;
        }

        No* percorreAdjacentes (int alvo) {
            No *resultado = nullptr;
            for (size_t i = 0; i < size; i++) {
                if (adjacentes[i]->dado == alvo) {
                    resultado = adjacentes[i];
                }
            }

            return resultado;
        }
};

class Grafo {
    public:
        No *primeiro;
        int tamanho; // quantidade de vértices

        Grafo(int tamanho, No *primeiro) {
            this->primeiro = primeiro;
            this->tamanho = tamanho;
        }

        void adicionarAresta (No *origem, No *destino) {
            if (!origem->eAdjacente(destino)) {  
                origem->adicionarAdjacente(destino);
                destino->adicionarAdjacente(origem);
            }

            return;
        };

        No* buscaLargura(int valor) {
            No *resultado = nullptr;
            if (primeiro->percorreAdjacentes(valor) != nullptr) {
                resultado = primeiro->percorreAdjacentes(valor);
            }
            
            // vai no primeiro da lista de adj
            // percorre lista de adjacentes

            // vai no segundo da lista de adj
            return resultado;
        }

};

#endif