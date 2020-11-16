#include "Aresta.h"
#include "Vertice.h"
#include <iostream>

Vertice vizinho;
int custo;

Aresta::Aresta(Vertice vizinho, int custo) {
    if (custo < 0) {
        std::cout <<("Custo inválido!") << std::endl;
        return;
    }

    this->vizinho = vizinho;
    this->custo = custo;
}

Aresta::~Aresta() {

}

Vertice getVizinho() {
    return vizinho;
}

int getCusto() {
    return custo;
}


