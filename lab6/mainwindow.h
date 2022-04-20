#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <vector>

#include <employe.h>
#include <abstractreader.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QString fileName;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void read(AbstractReader& reader);

public slots:
    void SearchEmploye();
    void AddEmploye();

private slots:
    void on_toolButton_clicked();

private:
    Ui::MainWindow *ui;


    std::vector<Employe> employes;
};
#endif // MAINWINDOW_H
