#include <string>
#include <bits/stdc++.h> 

using namespace std;

#ifndef ED05_GRAFOARRAY_H
#define ED05_GRAFOARRAY_H

class GrafoArray : public Grafo {

private:

  int **arestas;
  bool direcionado;
  int length;
  static int indefinido = -1;
  static int infinito = INT_MAX;
  
public:
    explicit GrafoArray(int vertices,bool direcionado);

    //Desabilita a cópia: exclui o construtor de cópia e o operador de =
    GrafoArray(const GrafoArray& other) = delete;
    GrafoArray& operator = (const GrafoArray& other) = delete;

    virtual int getTamanho() override;
    virtual void adicionarAresta(int v1, int v2, int custo) override;
    virtual void removerAresta(int v1, int v2) override;
    virtual int getCusto(int v1, int v2) override;
    virtual vector<int> getVizinhos(int vertice) override;

    virtual ~GrafoArray();
};

#endif //ED05_GRAFOARRAY_H
