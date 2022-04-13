#ifndef STUDENT_H
#define STUDENT_H

#include "employe.h"

class Student : public Employe
{
public:
    int curs;
    Student();

    QString to_string();
};

#endif // STUDENT_H
