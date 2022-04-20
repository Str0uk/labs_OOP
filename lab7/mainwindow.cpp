#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mybrowser.h"
#include "csvexception.h"

#include <csvreader.h>
#include <jsonreader.h>
#include <csvwritter.h>
#include <iostream>
#include <QDebug>
#include <QFileDialog>


using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

//Поиск по фамилии
void MainWindow::SearchEmploye(){
    ui->textBrowser->clear(); //Очищение браузера от продыдущих поисков.

    ui->textBrowser->GreenText("Searching..");

    if(ui->editSearch->text().isEmpty()){
        for (const auto &e: employes){
            ui->textBrowser->append("ID: " + QString::number(e.id) + ", " + e.full_name + ", " + QString::number(e.age()) + " years");
        }
    }
    //ui->textBrowser->append("Searching..");
    for (const auto &e: employes) {
        if (e.full_name == ui->editSearch->text()){
            ui->textBrowser->append("ID: " + QString::number(e.id) + ", " + e.full_name + ", " + QString::number(e.age()) + " years");
        }
    }
}

// Обработчик нажатия на кнопку ButtonAdd
void MainWindow::AddEmploye(){
    Employe em;
    em.id = ui->EditID->text().toInt();
    em.full_name = ui->EditName->text();
    em.birth_year = ui->EditYear->text().toInt();
    em.sex = static_cast<Sex>(ui->comboSex->currentIndex());


    employes.push_back(em);

    CSVWritter csv("C:\\content\\OOP\\lab2\\lab2\\updated_database.csv");

    csv.write(employes);

    ui->textBrowser->clear();
    ui->textBrowser->RedText("Person is added.");
    ui->EditID->clear();
    ui->EditName->clear();
    ui->EditYear->clear();

}


void MainWindow::on_toolButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                      "/home",
                                                      tr("Base (*.csv *.json)"));
    this->fileName = fileName;
    //Открытие файла
    if(fileName.right(1) == QString::fromStdString("v")){
        CSVReader csv(fileName);
        read(csv);


    }
    if(fileName.right(1) == QString::fromStdString("n")){
        JSONReader json(fileName);
        read(json);
    }

    // сортировка
        std::sort(employes.begin(), employes.end());

}

void MainWindow::read(AbstractReader& reader){

    if (reader.is_open()){
        //Чтение из файла в вектор
        try {
            employes = reader.readAll();
            Employe em;

            while( reader >> em){
                std::cout << em << std::endl;
            }
        }  catch (CSVException &em) {
            std::cerr<< "Error in line " << em.GetLine();
        }

    }

}
