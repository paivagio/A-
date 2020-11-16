//
// Created by lucas on 13/11/2020.
//

#ifndef ESTRELA_ARESTA_H
#define ESTRELA_ARESTA_H


#include "Vertice.h"

class Aresta {
public:
    Aresta(Vertice vizinho, int custo);

    virtual ~Aresta();

    int custo;
    Vertice vizinho;
};


#endif //ESTRELA_ARESTA_H
