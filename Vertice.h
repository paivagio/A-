#include <map>
#include <vector>

#ifndef ESTRELA_VERTICE_H
#define ESTRELA_VERTICE_H

class Vertice {
private:
    int num;
    double x;
    double y;

public:
    explicit Vertice(int num,double x, double y);
    //Desabilita a cópia: exclui o construtor de cópia e o operador de =
    Vertice(const Vertice& other) = delete;
    Vertice& operator = (const Vertice& other) = delete;

    int getNum() const;
    int getX() const;
    int getY() const;
    void setNum(int num);
    void setX(int x);
    void setY(int y) ;
};


#endif //ESTRELA_VERTICE_H
