#ifndef EQUACAO_H
#define EQUACAO_H

class Equacao
{
public:
    Equacao();
    int MatrizCoeficientes[3][3];
    int TermosIndependentes[3];
    int Incognitas[3];

private:
    void preencherMatrizCoeficientes();
    void preencherTermosIndependentes();
    int* verMatrizCoeficientes();
    int* verTermosIndependentes();
};

#endif // EQUACAO_H
