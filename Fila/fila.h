#include <iostream>
class Fila{
private:
    int *intens;
    int inicio, final;
    int tamanho;

public:
    Fila();
    Fila(int);
    void setItens(int, int);
    void setInicio(int);
    void setFinal(int);
    void setTamanho(int);
    
    int getItens();
    int getInicio();
    int getFinal();
    int getTamanho();

}