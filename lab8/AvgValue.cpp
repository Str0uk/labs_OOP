#include <iostream>
#include <vector>


template<typename T>
T AvgValue(std::vector<T> vec){
    T avg{};
    for (const auto &v: vec){
        avg = avg + v;
    }
    T ans = avg/vec.size();
    return ans;
}
