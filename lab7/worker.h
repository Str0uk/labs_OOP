#ifndef WORKER_H
#define WORKER_H

#include "employe.h"

class Worker : public Employe
{
public:
    int experience;
    Worker();

    QString to_string();
};

#endif // WORKER_H
