//
// Created by paiva on 13/11/2020.
//

#include <algorithm>
#include "Vertice.h"
#include "Grafo.h"


Vertice::Vertice(int num) {
    this->num = num;
}

void Vertice::ligar(Vertice* vizinho, int custo) {
    arestas.insert(std::pair<int,Aresta*>(vizinho->getNum(),new Aresta(vizinho, custo)));
}

void Vertice::desligar(Vertice* vertice) {
    arestas.erase(vertice->getNum());
}

/*
std::vector<int> Vertice::getVizinhos() const {
    std::vector<int> vizinhos (arestas.size());
    auto it = arestas.begin();

    std::for_each(arestas.begin(), arestas.end(),[&vizinhos](const std::pair<int, Aresta>& element){
          // Accessing KEY from element
          int n = element.first;

          vizinhos.insert(vizinhos.begin(), n);
      });

    return vizinhos;
}

std::vector<Aresta> Vertice::getArestas() const {
    std::vector<Aresta> vizinhos (arestas.size());
    auto it = arestas.begin();

    std::for_each(arestas.begin(), arestas.end(),[&vizinhos](const std::pair<int, Aresta>& element){
        // Accessing VALUE from element
        Aresta ar = element.second;

        vizinhos.insert(vizinhos.begin(), ar);
    });

    return vizinhos;
}
*/

int Vertice::getCusto(int vizinho) const {
    auto aresta = arestas.at(vizinho); //usar at(index)
    if (aresta == nullptr)
        return -1;
    return aresta->getCusto(); //aresta.first
}


int Vertice::getCusto(Vertice* vizinho) const {
    return getCusto(vizinho->getNum());
}

int Vertice::getNum() const {
    return num;
}


