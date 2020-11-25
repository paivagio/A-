#include "Vertice.h"

Vertice::Vertice(int num, double x, double y) {
    this->num = num;
    this->x = x;
    this->y = y;
}

int Vertice::getNum() const {
    return num;
}

int Vertice::getX() const {
    return x;
}

int Vertice::getY() const {
    return y;
}

void Vertice::setNum(int num){
    this->num = num;
}

void Vertice::setX(int x) {
    this->x = x;
}

void Vertice::setY(int y){
    this->y = y;
}
