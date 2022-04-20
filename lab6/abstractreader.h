#ifndef ABSTRACTREADER_H
#define ABSTRACTREADER_H

#include <vector>
#include <fstream>

#include <employe.h>

using namespace std;

class AbstractReader
{
public:
    AbstractReader();
    virtual std::vector<Employe> readAll() = 0;
    virtual bool is_open() const = 0;
    virtual operator bool () = 0;
    virtual AbstractReader& operator>> (Employe &em) = 0;

//    Employe employee;
//    employee.id = std::stoi(v[0]);
//    employee.full_name = QString::fromStdString(v[1]);
//    employee.birth_year = std::stoi(v[2]);
//    employee.sex = static_cast<Sex>(std::stoi(v[3]));
};

#endif // ABSTRACTREADER_H
