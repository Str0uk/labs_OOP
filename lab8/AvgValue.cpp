#include <iostream>
#include <vector>


template<typename T>
T AvgValue(std::vector<T> vec){
    T avg = 0;
    for (const auto &v: vec){
        avg += v;
    }
    avg = avg/vec.size();
    return avg;
}
