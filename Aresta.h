//
// Created by lucas on 13/11/2020.
//

#ifndef ESTRELA_ARESTA_H
#define ESTRELA_ARESTA_H

class Vertice;

class Aresta {
private:
    Vertice* vizinho;
    int custo;

public:
    Aresta(Vertice* vizinho, int custo);
    virtual ~Aresta();
    Vertice getVizinho();
    int getCusto();
};

#endif //ESTRELA_ARESTA_H
