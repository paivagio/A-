//
// Created by paiva on 13/11/2020.
//

#include "Vertice.h"
#include "map"
#include "Grafo.h"


Vertice::Vertice(int num) {
    this->num = num;
}

void Vertice::ligar(Vertice vizinho, int custo) {
    arestas.adicionar(vizinho.getNum(), new Aresta(vizinho, custo));
}

void Vertice::desligar(Vertice vertice) {
    arestas.remover(vertice.getNum());
}

std::vector<int> Vertice::getVizinhos() const {
    //std::vector<int> vizinhos = new std::vector<int>(arestas.getTamanho());
    //arestas.chaves().forEach(vizinhos::adicionar);
    return vizinhos;
}

std::vector<Aresta> Vertice::getArestas() const {
    //std::vector<Aresta> vizinhos = new std::vector<Aresta>(arestas.getTamanho());
    //arestas.valores().forEach(vizinhos::adicionar);
    return vizinhos;
}

int Vertice::getCusto(int vizinho) const {
    Aresta aresta = arestas.get(vizinho);
    if (aresta == nullptr) return Grafo.SEM_ARESTA;
    return aresta.getCusto();
}

int Vertice::getCusto(Vertice vizinho) const {
    return getCusto(vizinho.getNum());
}

int Vertice::getNum() const {
    return num;
}
