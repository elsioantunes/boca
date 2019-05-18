include <iostream>
using namespace std;


/*******************************************/
/** cell.h                                **/
/*******************************************/
class Cell{
    private:
        int valor;
        Cell *prox;
    public:
        Cell(int);
        void setValor(int);
        void setProx(Cell*);
        Cell *getProx();
        int getValor();
}


/*******************************************/
/** cell.cpp                              **/
/*******************************************/

Cell::Cell(int v){
    this->setValor(v);
    this->setProx(NULL);
}

void Cell::setValor(int v){
    this->valor = v;
}
void Cell::setProx(Cell *p){
    this->prox = p;
}


Cell *Cell::getProx(){
    return this->prox;
}
int Cell::getValor(){
    return this->valor;
}

/*******************************************/
/** lista.h                               **/
/*******************************************/
class Lista{
    private:
        Cell *ini, *fim, *aux;
    
    public:
        Lista(int);
        void setIni(Cell*);
        Cell *getIni();
        void inserir(Cell*);
        Cell *remover(int);
        Cell *buscar(int);
        bool vazia();
}


/*******************************************/
/** lista.cpp                             **/
/*******************************************/

Lista::Lista(int size){
    this->setIni(cell);
};

void Lista::setIni(Cell* cell){
    this->ini = cell;
};

Cell *Lista::getIni(){
    return this->ini;    
};

void Lista::inserir(Cell* cell){
        
};

Cell *Lista::remover(int);
Cell *Lista::buscar(int);
bool Lista::vazia();
