//
// Created by lucas on 13/11/2020.
//

#ifndef ESTRELA_GRAFO_H
#define ESTRELA_GRAFO_H

#include <vector>
#include "Vertice.h"

using namespace std;

class Grafo {
public:
    static const int SEM_ARESTA = -1;

    virtual int getTamanho() = 0;

    virtual void adicionarAresta(Vertice *v1, Vertice *v2, int custo) = 0;
    virtual void removerAresta(int v1, int v2) = 0;
    virtual int getCusto(int v1, int v2) = 0;
    virtual std::vector<int> getVizinhos(int vertice) = 0;
    virtual ~Grafo() = default;
};

#endif //ESTRELA_GRAFO_H
