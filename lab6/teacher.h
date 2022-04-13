#ifndef TEACHER_H
#define TEACHER_H

#include "employe.h"

class Teacher : public Employe
{
public:
    int countOfClasses;
    Teacher();

    QString to_string();
};

#endif // TEACHER_H
