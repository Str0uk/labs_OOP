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
    T GetX(){return X;};
    T GetY(){return Y;};
    void type(){cout <<typeid (X).name() << endl;};

private:
    T X;
    T Y;
};


#endif // COORDINATES_H
