#include "teacher.h"

Teacher::Teacher()
{

}


QString Teacher::to_string() {
    return("Name: " + full_name + "age" + QString::number(birth_year) + "Expereince: " + QString::number(countOfClasses) );
}
