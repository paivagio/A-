#include <string>
#include <bits/stdc++.h>
#include "Grafo.h"
#include "Aresta.h"

using namespace std;

#ifndef ED05_GRAFOARRAY_H
#define ED05_GRAFOARRAY_H

class GrafoArray : public Grafo {

private:

  int **arestas;
  bool direcionado;
  int length;
  int indefinido = -1;
  int infinito = INT_MAX;
  
public:
    explicit GrafoArray(int vertices,bool direcionado);

    //Desabilita a cópia: exclui o construtor de cópia e o operador de =
    GrafoArray(const GrafoArray& other) = delete;
    GrafoArray& operator = (const GrafoArray& other) = delete;

    int getTamanho() override;
    void adicionarAresta(int v1, int v2, int custo) override;
    void removerAresta(int v1, int v2) override;
    int getCusto(int v1, int v2) override;
    vector<int> getVizinhos(int vertice) override;
    int maisPerto(const int* custo, const vector<int>& naoVisitados) const;
    vector<int>* listarCaminho(int* antecessor, int para) const;
    vector<int>* buscaRadial(int de, int para);

    ~GrafoArray() override;
};

#endif //ED05_GRAFOARRAY_H
