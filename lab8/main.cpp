#include <iostream>
#include <vector>

#include "AvgValue.cpp"
#include "coordinates.h"

using namespace std;

int main()
{
    //Пример float
    std::vector<float> vect;

    vect.push_back(1.2);
    vect.push_back(2.2);
    vect.push_back(3.3);
    vect.push_back(4.5);
    vect.push_back(5.0);
    vect.push_back(6.9);

    float avg = AvgValue(vect);
    cout<<avg<<endl;

    //Пример Int
    std::vector<int> vect_int;

    vect_int.push_back(1);
    vect_int.push_back(2);
    vect_int.push_back(3);
    vect_int.push_back(4);
    vect_int.push_back(5);
    vect_int.push_back(6);

    int avg_int = AvgValue(vect);
    cout<<avg_int<<endl;



    //Пример Int
    int x = 1;
    int y = 2;

    Coordinates<int> cor(x, y);

    cor.type();


    //Пример float
    float x_f = 1.1;
    float y_f = 2.1;

    Coordinates<float> cor_f(x_f, y_f);
    cor_f.type();


    // points on the flat
    std::vector<Coordinates<int>> points{{11, -2},{4, 5},{-3, 6}};
    // получим отдельно векторы значений координат точки
    auto pointAvg = AvgValue(points);
    std::cout << "point Average coordinates: " << "x = " << pointAvg.GetX() << " " << "y = " << pointAvg.GetY() << std::endl;

    return 0;
}

