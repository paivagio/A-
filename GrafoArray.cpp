#include "GrafoArray.h"

#include <iostream>
#include <array>

using namespace std;

GrafoArray::GrafoArray(int vertices,bool direcionado) {
    this->direcionado = direcionado;
    this->arestas = new int*[vertices];

    for(int i = 0; i < vertices; i ++) {
      this->arestas[i] = new int[vertices];
    }

    for(int i = 0; i < vertices; i++) {
      for(int j = 0; j < vertices; i++) {
        arestas[i][j] = this->indefinido;
      }
    }

    this->length = vertices * vertices;
}

int GrafoArray::getTamanho(){
  return this->length;
}

void GrafoArray::adicionarAresta(int v1, int v2, int custo) {

  if(custo < 0) {
    cout << "Custo Inválido!!";
    return;
  }

  arestas[v1][v2] = custo;
  if(!direcionado) arestas[v2][v1] = custo;
}

void GrafoArray::removerAresta(int v1, int v2) {
  arestas[v1][v2] = this->indefinido;
  if(!direcionado) arestas[v2][v1] = this->indefinido;
}

int GrafoArray::getCusto(int v1, int v2) {
  return arestas[v1][v2];
}

vector<int> GrafoArray::getVizinhos(int vertice) {
    vector<int> vizinhos;
    for (int i = 0; i < length; i++) {
        if (arestas[vertice][i] != this->indefinido) {
            vizinhos.push_back(i);
        }
    }
    return vizinhos;
}

//um delete por linha e um geral

//for (int i = 0; i < 15; i++) {
   //delete [] aresta[i];
//} 
//delete [] aresta;