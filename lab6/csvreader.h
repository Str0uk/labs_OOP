#ifndef CSVREADER_H
#define CSVREADER_H

#include <QString>
#include <fstream>
#include <vector>

#include <employe.h>
#include <abstractreader.h>

using namespace std;

class CSVReader : public AbstractReader
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

    virtual bool is_open() const {return fin.is_open(); };

    virtual std::vector<Employe> readAll();

    virtual AbstractReader& operator>> (Employe &em);

    virtual operator bool (){
        return !(this->fin.eof());
    }

};

#endif // CSVREADER_H
