cmake_minimum_required(VERSION 3.17)
project(Estrela)

set(CMAKE_CXX_STANDARD 14)

add_executable(Estrela main.cpp Vertice.cpp Vertice.h Aresta.cpp Aresta.h Grafo.h GrafoArray.cpp GrafoArray.h)