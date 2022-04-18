#include "worker.h"

#include "QString"

Worker::Worker()
{

}

QString Worker::to_string() {
    return("Name: " + full_name + "age" + QString::number(birth_year) + "Expereince: " + QString::number(experience) );
}
