#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QLineEdit>
#include <QDoubleSpinBox>
#include <string>
#include <iostream>

#include "about.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    double determinante3Por3(double M[3][3]);
    double calcularX(double M[3][3],double Z[3]);
    double calcularY(double M[3][3],double Z[3]);
    double calcularZ(double M[3][3],double Z[3]);
    double determinanteGeral;
    //void preencherMatrizes();

private:
    Ui::MainWindow *ui;

    QDoubleSpinBox* matrizCoeficientes[3][3];
    QDoubleSpinBox* matrizTermosInd[3];
    double coeficietes[3][3];
    double termosInd[3];
    About *about;

private slots:
    void preencherMatrizes();
    void showAbout();
};

#endif // MAINWINDOW_H
