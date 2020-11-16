//
// Created by lucas on 13/11/2020.
//

#ifndef GRAFOS_GRAFO_H
#define GRAFOS_GRAFO_H

#include <vector>

using namespace std;

class Grafo {
public:
    static const int SEM_ARESTA = -1;

    virtual int getTamanho() = 0;

    virtual void adicionarAresta(int v1, int v2, int custo) = 0;
    virtual void removerAresta(int v1, int v2) = 0;
    virtual int getCusto(int v1, int v2) = 0;
    virtual std::vector<int> getVizinhos(int vertice) = 0;
    virtual ~Grafo() {}
};

#endif //GRAFOS_GRAFO_H