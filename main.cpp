#include <iostream>
#include <vector>
#include "GrafoArray.h"
#include "Vertice.h"

int main() {
	
	cout << "\nA* by Giovanni P. M. Paiva , Lucas F. A. de Oliveira, Sarah G. Rodrigues\n";

    //Caso se deseje verificar o caminho realizado pelo método Dijkstra:
    //  * Sete o terceiro parâmetro do construtor de GrafoArray para 1
    //Para utilizar o método A*:
    //  * Sete o terceiro parâmetro do construtor de GrafoArray para 0

    static char nomes[] {'A', 'B', 'F', 'D', 'C', 'S','G','H'};

    Vertice *A = new Vertice(0,10.8,10.8);
    Vertice *B = new Vertice(1,15.6,10.8);
    Vertice *F = new Vertice(2,18.8,11.5);
    Vertice *D = new Vertice(3,13.9,7.7);
    Vertice *C = new Vertice(4,18.3,9.1);
    Vertice *S = new Vertice(5,17.2,6.4);
    Vertice *G = new Vertice(6,8.1,17.0);
    Vertice *H = new Vertice(7,22.0,20.0);

    auto grafo = new GrafoArray(8, true,0);

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



