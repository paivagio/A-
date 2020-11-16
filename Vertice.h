//
// Created by paiva on 13/11/2020.
//

#ifndef ESTRELA_VERTICE_H
#define ESTRELA_VERTICE_H

#include <map>
#include "Aresta.h"
#include <vector>


class Vertice {
private:
    int num;
    std::map<int, Aresta> arestas;

public:
    Vertice(int num);
    void ligar(Vertice vizinho, int custo);
    void desligar(Vertice vertice);
    std::vector<int> getVizinhos() const;
    std::vector<Aresta> getArestas() const;
    int getCusto(int vizinho) const;
    int getCusto(Vertice vizinho) const;
    int getNum() const;

};


#endif //ESTRELA_VERTICE_H
