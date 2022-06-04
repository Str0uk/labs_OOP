#ifndef COORDINATES_H
#define COORDINATES_H

#include <typeinfo>
#include <iostream>

using namespace std;

template<typename T>
class Coordinates
{
public:
    Coordinates(T X, T Y){
        this->X = X;
        this->Y = Y;
    };
    Coordinates() : X(0), Y(0) {}
    T GetX(){return X;};
    T GetY(){return Y;};
    void type(){cout <<typeid (X).name() << endl;};

    Coordinates<T> operator + (Coordinates p){
        return Coordinates<int>(this->X + p.X, this->Y + p.Y);
    }

    Coordinates<T> operator / (int count){
        return Coordinates<T>(this->X / count, this->Y / count);
    }

private:
    T X;
    T Y;
};


#endif // COORDINATES_H
