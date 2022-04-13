#ifndef CSVWRITTER_H
#define CSVWRITTER_H

#include <fstream>
#include <vector>

#include <employe.h>

class CSVWritter

{   std::fstream fout;

    CSVWritter(const CSVWritter&) = delete;
    CSVWritter& operator=(const CSVWritter&) = delete;



public:
    CSVWritter(const QString& filename);
    ~CSVWritter();
    bool is_open() const {return fout.is_open(); };

    void write(std::vector<Employe> em);

    //Оператор присваивания перемещением
    CSVWritter& operator= (CSVWritter&& orther);
    // Конструктор перемещения
    CSVWritter(CSVWritter&& orther);

};

#endif // CSVWRITTER_H
