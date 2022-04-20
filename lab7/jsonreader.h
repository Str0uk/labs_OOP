#ifndef JSONREADER_H
#define JSONREADER_H

#include "abstractreader.h"
#include <json.hpp>

#include <fstream>

class JSONReader : public AbstractReader
{
    std::ifstream fin;

public:
    JSONReader(const QString& filename);

    virtual std::vector<Employe> readAll();
    virtual bool is_open() const {return fin.is_open(); };
    virtual AbstractReader& operator>> (Employe &em);

    virtual operator bool (){
        return this->is_open();
    }

private:
    int index = 0;
    nlohmann::json json;
};


#endif // JSONREADER_H
