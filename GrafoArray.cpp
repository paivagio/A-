#include "GrafoArray.h"

#include <iostream>
#include <array>
#include "Aresta.h"

using namespace std;

GrafoArray::GrafoArray(int vertices,bool direcionado) {
    this->direcionado = direcionado;
    this->arestas = new int*[vertices];

    for(int i = 0; i < vertices; i ++) {
      this->arestas[i] = new int[vertices];
    }

    for(int i = 0; i < vertices; i++) {
      for(int j = 0; j < vertices; j++) {
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

int GrafoArray::maisPerto(int* custo, vector<int> naoVisitados) const {
    int menorCusto = this->infinito;
    int minIndice = 0;
    for (int v = 0; v < length; v++){
        if (custo[v] < menorCusto) {
            menorCusto = custo[v];
            minIndice = v;
        }
    }
    return minIndice;
}

vector<int>* GrafoArray::listarCaminho(int* antecessor, int para) const {
    stack<int> caminho;
    caminho.push(para);
    while (antecessor[para] != this->indefinido) {
        caminho.push(antecessor[para]);
        para = antecessor[para];
    }

    vector<int> lista;
    for (int v = 0; v < length; v++) {
        lista.push_back(caminho.top());
        caminho.pop();
    }
    return &lista;
}


vector<int>* GrafoArray::buscaRadial(int de, int para){
        //Inicialização
        //-------------
        auto custo = new int[getTamanho()];
        auto antecessor = new int[getTamanho()];
        auto naoVisitados = vector<int>(getTamanho());

        for (auto v = 0; v < getTamanho(); v++) {
            custo[v] = infinito;
            antecessor[v] = indefinido;
            naoVisitados.insert(naoVisitados.begin()+v, v);
        }
        custo[de] = 0;

        //Algoritmo
        //---------
        while (!naoVisitados.empty()) {
            int perto = maisPerto(custo, naoVisitados);
            auto indicePerto = 0;
            for (auto v = 0; v < getTamanho(); v++) {
                if(naoVisitados.at(v) == perto)
                    indicePerto = v;
            }
            if (indicePerto == -1) break;
            naoVisitados.erase(naoVisitados.begin()+indicePerto);
            for (auto vizinho : getVizinhos(perto)) {
                auto custoTotal = custo[perto] + getCusto(perto, vizinho);
                if (custoTotal < custo[vizinho]) {
                    custo[vizinho] = custoTotal;
                    antecessor[vizinho] = perto;
                }
            }

            //Achou?
            if (perto == para) {
                return listarCaminho(antecessor, perto);
            }
        }
        return new vector<int>();
    }


//um delete por linha e um geral

//for (int i = 0; i < 15; i++) {
   //delete [] aresta[i];
//} 
//delete [] aresta;
