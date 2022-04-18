#include "jsonreader.h"

#include <json.hpp>

#include <QString>
#include <iostream>

using namespace std;
using json = nlohmann::json;

JSONReader::JSONReader(const QString& filename)
{
    fin.open(filename.toLatin1().data());
}

std::vector<Employe> JSONReader::readAll(){

    std::vector<Employe> result;
    nlohmann::json json;
    try {
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
    }  catch (json::exception& e) {
        std::cout << e.what() << '\n';
    }


    return result;
}

AbstractReader& JSONReader::operator>>(Employe &em){

//    std::vector<Employe> result;
//    nlohmann::json json;

//    fin >> json;
//    json.begin();
//    auto e = json.get<Employe>();
//    std::cout<< e ;
//    if (fin.is_open() && !fin.eof()) {
//        std::string line;
//        getline(fin, line);

//        if (!line.empty()){


//            e.at("id").get_to(c.id);
//            e.at("birth_year").get_to(c.birth_year);
//            e.at("sex").get_to(c.sex);
//            std::string str;
//            e.at("full_name").get_to(str);
//            c.full_name = QString::fromStdString(str);
//        }

//    }
    em.full_name = "11111111111";
    em.birth_year = -1;
    em.sex = MAN;
    em.id = -1;
    return *this;
}
