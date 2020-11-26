#include <iostream>
#include <vector>
#include "GrafoArray.h"
#include "Vertice.h"

int main() {

    int x;
	cout << "\nA* by Giovanni P. M. Paiva , Lucas F. A. de Oliveira, Sarah G. Rodrigues" << "\n\n";
    cout << "0 -  Sair" << "\n";
    cout << "1 -  A*" << "\n";
    cout << "2 -  Dijkstra" << "\n";
    cout << "\nQual método deseja usar?";
    cin >> x;
    cout << "\n";

    if(x == 0)
        std::exit(0);

    static char nomes[] {'A', 'B', 'F', 'D', 'C', 'S','G','H'};

    auto *A = new Vertice(0,10.8,10.8);
    auto *B = new Vertice(1,15.6,10.8);
    auto *F = new Vertice(2,18.8,11.5);
    auto *D = new Vertice(3,13.9,7.7);
    auto *C = new Vertice(4,18.3,9.1);
    auto *S = new Vertice(5,17.2,6.4);
    auto *G = new Vertice(6,8.1,17.0);
    auto *H = new Vertice(7,22.0,20.0);

    auto grafo = new GrafoArray(8, true,x-1);

    //Devem ser inseridos em ordem numérica crescente!!! Levando em consideração o num do Vertice
    grafo->adicionarVertice(A);
    grafo->adicionarVertice(B);
    grafo->adicionarVertice(F);
    grafo->adicionarVertice(D);
    grafo->adicionarVertice(C);
    grafo->adicionarVertice(S);
    grafo->adicionarVertice(G);
    grafo->adicionarVertice(H);

    grafo->adicionarAresta(A, B, 3);
    grafo->adicionarAresta(A, D, 6);

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

    grafo->adicionarAresta(A, G, 2);
    grafo->adicionarAresta(G, B, 2);

    grafo->adicionarAresta(G, H, 1);
    grafo->adicionarAresta(H, G, 1);

    grafo->adicionarAresta(A, H, 1);
    grafo->adicionarAresta(H, A, 1);

    vector<int>* result = grafo->buscaRadial(A->getNum(), S->getNum());

    for (auto& vertice : *result)
        cout << nomes[vertice] << " ";
    cout << "\n";
}



