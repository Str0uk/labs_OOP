#include "csvreader.h"

#include "split.cpp"


CSVReader::CSVReader(const QString& filename)
{
    fin.open(filename.toLatin1().data());

}

CSVReader::~CSVReader(){
    fin.close();
}

std::vector<Employe> CSVReader::readAll(){

    std::vector<Employe> result;


            while (!fin.eof())
            {
                std::string line;
                std::getline(fin, line);


                if (line != "") {
                    auto v = split(line, ';');

                    Employe employee;
                    employee.id = std::stoi(v[0]);
                    employee.full_name = QString::fromStdString(v[1]);
                    employee.birth_year = std::stoi(v[2]);
                    employee.sex = static_cast<Sex>(std::stoi(v[3]));

                    result.push_back(employee);
                }



               }
            return result;
}

CSVReader& CSVReader::operator=(CSVReader&& orher){
    fin = std::move(orher.fin);
    return *this;
}

CSVReader::CSVReader(CSVReader&& orther){
    fin = std::move(orther.fin);
}




