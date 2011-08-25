#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "string.h"
#include <cstdio>
#include <QString>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    connect(ui->solve,SIGNAL(clicked()),this,SLOT(preencherMatrizes()));
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(showAbout()));
    connect(ui->limpar,SIGNAL(clicked()),ui->quadro, SLOT(clear()));
    connect(ui->actionSair,SIGNAL(triggered()),this, SLOT(close()));
    about = new About;
            //float x = ui->lineEdit->text().toFloat();
            //ui->lineEdit->setText(QString::number(30));

            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    matrizCoeficientes[i][j] = new QDoubleSpinBox();
                    ui->gridLayout->addWidget(matrizCoeficientes[i][j],i,2*j);

                    switch(j){
                    case 0:
                        ui->gridLayout->addWidget(new QLabel("x"),i,(2*j)+1);
                        break;
                    case 1:
                        ui->gridLayout->addWidget(new QLabel("y"),i,(2*j)+1);
                        break;
                    case 2:
                        ui->gridLayout->addWidget(new QLabel("z     = "),i,(2*j)+1);
                        break;
                    }

                    }



            }

            for(int i = 0; i < 3; i++){
                matrizTermosInd[i] = new QDoubleSpinBox();
                ui->gridLayout->addWidget(matrizTermosInd[i],i,8);
            }




}


void MainWindow::preencherMatrizes(){

    //Pegando os dados da matriz dos coeficietes
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            coeficietes[i][j] = matrizCoeficientes[i][j]->value();
            }
    }

    //Pegando os dados da matriz dos termos independentes
    for(int i = 0; i < 3; i++){
        termosInd[i] = matrizTermosInd[i]->value();
    }

    //Calcular o determinante Geral
    determinanteGeral = determinante3Por3(coeficietes);
    if(determinanteGeral != 0){
    double valorx, valory,valorz;
    valorx = calcularX(coeficietes,termosInd);
    valory = calcularY(coeficietes,termosInd);
    valorz = calcularZ(coeficietes,termosInd);
    QString valores;
    valores =" ";
    valores.append("X = ");
    valores.append(QString::number(valorx));
    valores.append("\nY = ");
    valores.append(QString::number(valory));
    valores.append("\nZ=");
    valores.append(QString::number(valorz));
    valores.append("\n\n");

    ui->quadro->append(valores);

    }
    else{
        QString msg = "O determinante deu zero!";
        ui->quadro->append(msg);
    }

}



MainWindow::~MainWindow()
{
    delete about;
    delete ui;
}

double MainWindow:: determinante3Por3(double M[3][3]){
        return M[0][0]*( M[1][1]*M[2][2]  - M[1][2]*M[2][1] ) - M[0][1]*( M[1][0]*M[2][2] - M[1][2]*M[2][0] ) + M[0][2]*( M[1][0]*M[2][1] - M[1][1]*M[2][0]);

}


double MainWindow:: calcularX(double M[3][3], double Z[3]){

        double MatrizBuffer[3][3];

        for(int i=0;i<3;i++){
                for(int i2=0;i2<3;i2++){
                        MatrizBuffer[i][i2] = M[i][i2];
                }
        }

        //Substituindo a linha da Matriz pela linha do termo independente
        for(int i=0; i < 3;i++){
                MatrizBuffer[i][0] = Z[i];
        }

        //cout<< "O valor do x eh: "<<determinante3Por3(MatrizBuffer)/determinanteGeral<<endl;
    return determinante3Por3(MatrizBuffer)/determinanteGeral;
}

double MainWindow:: calcularY(double M[3][3], double Z[3]){

        double MatrizBuffer[3][3];

        for(int i=0;i<3;i++){
                for(int i2=0;i2<3;i2++){
                        MatrizBuffer[i][i2] = M[i][i2];
                }
        }

        //Substituindo a linha da Matriz pela linha do termo independente
        for(int i=0; i < 3;i++){
                MatrizBuffer[i][1] = Z[i];
        }

        return determinante3Por3(MatrizBuffer)/determinanteGeral;

}


double MainWindow:: calcularZ(double M[3][3], double Z[3]){

    double MatrizBuffer[3][3];

    for(int i=0;i<3;i++){
            for(int i2=0;i2<3;i2++){
                    MatrizBuffer[i][i2] = M[i][i2];
            }
    }

    //Substituindo a linha da Matriz pela linha do termo independente
    for(int i=0; i < 3;i++){
            MatrizBuffer[i][2] = Z[i];
    }

    return determinante3Por3(MatrizBuffer)/determinanteGeral;

}

void MainWindow::showAbout()
{
    about->show();
}
