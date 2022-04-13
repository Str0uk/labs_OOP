#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
enum Sex { MAN, WOMAN};

class Employe
{
 public:
    int id;
    QString full_name;
    int birth_year;
    int age() const { return 2022 - birth_year; };
    Sex sex;
    Employe();

    QString to_string();

    // Создана для того, чтобы при сортировке не использывать лямба функции
    friend bool operator< (const Employe& d1, const Employe& d2){
        return d1.birth_year < d2.birth_year;
    }

    //Предназначен для вывода в поток упрощенным синтаксисом
    friend std::ostream& operator<< (std::ostream& out, const Employe& em){
        out << "ID: " << em.id << " Full Name: " << em.full_name.toStdString() << ", age: " << em.age();
        return out;
    }
};

#endif // EMPLOYE_H
