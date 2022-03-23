#ifndef ABSTRACTREADER_H
#define ABSTRACTREADER_H

#include <vector>


#include <employe.h>

class AbstractReader
{
public:
    AbstractReader();
    virtual std::vector<Employe> readAll() {std::vector<Employe> em; return em;};
    virtual bool is_open() const {return 1;};
};

#endif // ABSTRACTREADER_H
