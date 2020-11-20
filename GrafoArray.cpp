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

int GrafoArray::maisPerto(int custo, vector<Aresta> naoVisitados) {
    int menorCusto = this->infinito;
    int minIndice = 0;
    for (int v = 0; v < length; v++){
        if (custo < menorCusto) {
            menorCusto = custo;
            minIndice = v;
        }
    }
    return minIndice;
}

vector<int> GrafoArray::listarCaminho(int antecessor, int para) {
    auto *caminho = new stack<int>();
    caminho->push(para);
    while (antecessor != this->indefinido) {
        caminho->push(antecessor);
        para = antecessor;
    }

    auto *lista = new vector<int>();
    //lista->adicionarTodos(caminho);
    return *lista;
}

/*
 public Lista<Integer> buscaRadial(int de, int para) {
        //Inicialização
        //-------------
        var custo = new int[getTamanho()];
        var antecessor = new int[getTamanho()];
        var naoVisitados = new ListaArray(getTamanho());

        Arrays.fill(custo, INFINITO);
        custo[de] = 0;
        Arrays.fill(antecessor, INDEFINIDO);
        for (var v = 0; v < getTamanho(); v++) {
            naoVisitados.adicionar(v);
        }

        //Algoritmo
        //---------
        while (!naoVisitados.isVazia()) {
            int perto = maisPerto(custo, naoVisitados);
            var indicePerto = naoVisitados.indice(perto);
            if (indicePerto == -1) break;
            naoVisitados.remover(indicePerto);

            for (var vizinho : getVizinhos(perto)) {
                var custoTotal = custo[perto] + getCusto(perto, vizinho);
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
        return new ListaArray<>();
    }
 */

//um delete por linha e um geral

//for (int i = 0; i < 15; i++) {
   //delete [] aresta[i];
//} 
//delete [] aresta;
