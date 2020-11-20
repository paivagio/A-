#include "Aresta.h"
#include <iostream>
#include "Vertice.h"

Aresta::Aresta(Vertice* vizinho, int custo) {
    if (custo < 0) {
        std::cout <<("Custo inválido!") << std::endl;
        return;
    }

    this->vizinho = vizinho;
    this->custo = custo;
}

Vertice Aresta::getVizinho() {
    return *vizinho;
}

int Aresta::getCusto() const {
    return custo;
}

Aresta::~Aresta() = default;

