#include "jsonreader.h"

#include <json.hpp>

#include <QString>
#include <iostream>

using namespace std;

JSONReader::JSONReader(const QString& filename)
{
    fin.open(filename.toLatin1().data());
    fin >> json;
}

std::vector<Employe> JSONReader::readAll(){

    std::vector<Employe> result;

    for (auto& e: json){

        Employe c;
        e.at("id").get_to(c.id);
        e.at("birth_year").get_to(c.birth_year);
        e.at("sex").get_to(c.sex);
        std::string str;
        e.at("full_name").get_to(str);
        c.full_name = QString::fromStdString(str);
        result.push_back(c);
    }

    return result;
}

AbstractReader& JSONReader::operator>>(Employe &em){
    if (!(this->json[index].empty())){
            std::string tempStr;

            json[index].at("id").get_to(em.id);
            json[index].at("birth_year").get_to(em.birth_year);
            json[index].at("sex").get_to(em.sex);
            json[index].at("full_name").get_to(tempStr);
            em.full_name = QString::fromStdString(tempStr);

            index++;
        }else {
            fin.close();
        }

        return *this;
}
