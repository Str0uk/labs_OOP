#ifndef CSVREADER_H
#define CSVREADER_H

#include <QString>
#include <fstream>
#include <vector>

#include <employe.h>

using namespace std;

class CSVReader
{
    std::ifstream fin;

    CSVReader(const CSVReader&) = delete;
    CSVReader& operator=(const CSVReader&) = delete;

public:
    CSVReader(const QString& filename);
   ~CSVReader();
    //Оператор присваивания перемещением
    CSVReader& operator= (CSVReader&& orther);
    // Конструктор перемещения
    CSVReader(CSVReader&& orther);

    bool is_open() const {return fin.is_open(); };

    std::vector<Employe> readAll();

};

#endif // CSVREADER_H
