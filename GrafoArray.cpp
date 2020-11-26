#include "GrafoArray.h"

#include <iostream>
#include <algorithm>
#include <cmath>
#include "Vertice.h"

using namespace std;

GrafoArray::GrafoArray(int vertices,bool direcionado, int metodo) {
    //Determina se o Grafo é direcionado ou não
    this->direcionado = direcionado;

    //Instancia uma matriz vertices x vertices
    this->arestas = new int*[vertices];

    for(int i = 0; i < vertices; i ++) {
        this->arestas[i] = new int[vertices];
    }

    //Popula a matriz com "indefinido"
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            arestas[i][j] = this->indefinido;
        }
    }
    this->length = vertices;
    //Escolhe o método de procura (Dijkstra ou A*)
    this->metodo = metodo;
}

int GrafoArray::getTamanho(){
    return this->length;
}

void GrafoArray::adicionarAresta(Vertice *v1, Vertice *v2, int custo) {

    if(custo < 0) {
        cout << "Custo Inválido!!";
        return;
    }

    arestas[v1->getNum()][v2->getNum()] = custo;
    if(!direcionado) arestas[v2->getNum()][v1->getNum()] = custo;
}

void GrafoArray::adicionarVertice(Vertice *v) {
    vertices.push_back(v);
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

int GrafoArray::maisPerto(const int* custo, const vector<int>& naoVisitados) const {
    int menorCusto = this->infinito;
    int minIndice = 0;

    for (auto v : naoVisitados) {
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
    vector<int>* lista;
    int size = caminho.size();
    int arr[size];
    for (int v = 0; v < size; v++) {
        arr[v] = caminho.top();
        caminho.pop();
    }

    int n = sizeof(arr) / sizeof(arr[0]);

    lista = new vector<int>(arr, arr + n);

    return lista;
}

int GrafoArray::distanciaEuclidiana(int de, int para) {

    Vertice *v1 = vertices.at(de); //vizinho
    Vertice *v2 = vertices.at(para); //ponto final

    double X = pow(v2->getX() - v1->getX(),2); //(x1 - x0)^2
    double Y = pow(v2->getY() - v1->getY(),2); //(y1 - y0)^2

    double sum = X + Y; //soma
    double root = sqrt(sum); //tira a raiz
    int distance = round(root); //arredonda

    return metodo == 0 ? distance : 0; //Só retorna a distância se estive no método A*
}

vector<int>* GrafoArray::buscaRadial(int de, int para){
    char nomes[] {'A', 'B', 'F', 'D', 'C', 'S','G','H'};

    //Inicialização
    //-------------
    auto custo = new int[getTamanho()];
    auto antecessor = new int[getTamanho()];
    auto naoVisitados = vector<int>(getTamanho());

    int arr[getTamanho()];
    for (int v = 0; v < getTamanho(); v++)
        arr[v] = v;

    int n = sizeof(arr) / sizeof(arr[0]);
    naoVisitados = vector<int>(arr, arr + n);

    for (auto v = 0; v < getTamanho(); v++) {
        custo[v] = infinito;
        antecessor[v] = indefinido;
    }
    custo[de] = 0;
    //Algoritmo
    //---------

    cout << "\nMetodo " << (metodo == 0 ? "A*" : "Dijkstra") << "\n";
    while (!naoVisitados.empty()) {
        //Pega o vizinho mais perto
        int perto = maisPerto(custo, naoVisitados);
        cout << "\nPassou pelo Vertice " << nomes[perto];
        //Pega o indice do vizinho mais perto
        auto indicePerto = 0;
        for (auto v = 0; v < naoVisitados.size(); v++) {
            if(naoVisitados.at(v) == perto) {
                indicePerto = v;
            }
        }
        if (indicePerto == -1) break;
        //Apaga do naoVisitados
        naoVisitados.erase(naoVisitados.begin()+indicePerto);
        //
        for (auto vizinho : getVizinhos(perto)) {
            //Calcula o custo = custo ate ponto inicial + custo ate o ponto final
            auto custoTotal = custo[perto] + getCusto(perto, vizinho) + distanciaEuclidiana(vizinho,para);
            if (custoTotal < custo[vizinho]) {
                custo[vizinho] = custoTotal;
                antecessor[vizinho] = perto;
            }
        }
        //Achou?
        if (perto == para) {
            cout << "\n\nCaminho Existe" << "\n";
            vector<int>* result = listarCaminho(antecessor, perto);
            return result;
        }
    }

    cout << "\nCaminho Não Existe" << "\n";
    return new vector<int>();
}

GrafoArray::~GrafoArray() = default;
