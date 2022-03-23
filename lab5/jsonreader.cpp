#include "jsonreader.h"

#include <json.hpp>

#include <QString>

JSONReader::JSONReader(const QString& filename)
{
    fin.open(filename.toLatin1().data());
}

std::vector<Employe> JSONReader::readAll(){

    std::vector<Employe> result;
    nlohmann::json json;

    fin >> json;

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
