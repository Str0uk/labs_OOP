#include "employe.h"


QString Employe::to_string() {
    return("Name: " + full_name + "age" + QString::number(birth_year));
}

Employe::Employe(){

}
