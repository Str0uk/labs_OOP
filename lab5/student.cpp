#include "student.h"

Student::Student()
{

}


QString Student::to_string() {
    return("Name: " + full_name + "age" + QString::number(birth_year) + "Expereince: " + QString::number(curs) );
}
