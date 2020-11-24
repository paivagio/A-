#include <iostream>
#include <vector>
#include "GrafoArray.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    static int A = 0;
    static int B = 1;
    static int F = 2;
    static int D = 3;
    static int C = 4;
    static int S = 5;

    static char nomes[] {'A', 'B', 'F', 'D', 'C', 'S'};

    auto grafo = new GrafoArray(6, true);
    grafo->adicionarAresta(A, B, 3);
    grafo->adicionarAresta(A, D, 30);

    grafo->adicionarAresta(B, A, 4);
    grafo->adicionarAresta(B, C, 3);

    grafo->adicionarAresta(C, B, 3);
    grafo->adicionarAresta(C, D, 4);
    grafo->adicionarAresta(C, S, 14);

    grafo->adicionarAresta(D, C, 7);
    grafo->adicionarAresta(D, D, 1);
    grafo->adicionarAresta(D, S, 4);

    grafo->adicionarAresta(F, B, 5);
    grafo->adicionarAresta(F, C, 3);

    vector<int>* result = grafo->buscaRadial(A, S);

    for (auto& vertice : *result)
        cout << vertice << " ";
    cout << "\n";
}



