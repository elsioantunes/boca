#include <iostream>
#include <stdexcept>
using namespace std;

class logicError : public runtime_error{
    public:
        logicError(string str):runtime_error(str){
        }
};

class Vetor{

private:
    int *itens, tamanho, quantidade;

public:
    Vetor(int);
    ~Vetor();
    void setQuantidade(int);
    void setItens(int, int);
    int getQuantidade();
    int getItens(int);
    void inserir(int);
    int buscar(int);
};


Vetor::Vetor(int n){
    this->itens = new int[n];
    this->setQuantidade(0);
};
Vetor::~Vetor(){
    delete this->itens;
};

void Vetor::inserir(int v){
    this->setItens(this->getQuantidade(), v);
    this->setQuantidade(this->getQuantidade()+1);
};

int &operator[](int j){
    if(j<0||j>=this->getQuantidade())
        throw logicError("runtime error: indice fora dos limites do vetor.");
    else
        return this->getItens(j);
};

void Vetor::setItens(int i, int v){this->itens[i] = v;};
int Vetor::getItens(int i){return this->itens[i];};
void Vetor::setQuantidade(int n){this->quantidade = n;};
int Vetor::getQuantidade(){return this->quantidade;};

int main(){
    int n, q;
    Vetor *vetor;
    
    cin >> n;
    vetor = new Vetor(n);
    
    for(int i=0;i<n;i++){
        cin >> q;
        vetor->inserir(q);
    }
    
    while(cin >> q){
        try{
            cout << (vetor[q]) << endl;
        }catch(logicError e){
            cout << e.what() << endl;
        }
    }
    return 0;
}


