#include "csvwritter.h"

using namespace std;

CSVWritter::CSVWritter(const QString& filename)
{
    fout.open(filename.toLatin1().data());
}

void CSVWritter::write(std::vector<Employe> em){
    if (is_open()){
        for (const auto &c: em) {
                    fout << c.id << ";" << c.full_name.toStdString() << ";" << c.birth_year << ";" << c.sex << endl;
            }
    }

}


CSVWritter::~CSVWritter(){
    fout.close();
}

CSVWritter& CSVWritter::operator=(CSVWritter&& orher){
    fout = std::move(orher.fout);
    return *this;
}

CSVWritter::CSVWritter(CSVWritter&& orther){
    fout = std::move(orther.fout);
}
