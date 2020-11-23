//
// Created by lucas on 13/11/2020.
//

#ifndef ESTRELA_GRAFO_H
#define ESTRELA_GRAFO_H

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
    virtual int maisPerto(int* custo, vector<int> naoVisitados);
    virtual vector<int> listarCaminho(int* antecessor, int para);
    virtual ~Grafo() = default;

};

#endif //ESTRELA_GRAFO_H
