#include <iostream>
using namespace std;

class Lista{

private:
    int *itens, tamanho, quantidade;

public:
    Lista(int);
    ~Lista();

    void setTamanho(int);
    void setQuantidade(int);
    void setItens(int, int);

    int getTopo();
    int getTamanho();
    int getQuantidade();
    int getItens(int);

    void inserir(int);
    int busca(int);
    int remover(int);
    void mostra();
    bool cheia();
    bool vazia();
};


Lista::Lista(int n){
    this->itens = new int[n];
    this->setQuantidade(0);
    this->setTamanho(n);
};

Lista::~Lista(){
    delete this->itens;
};

void Lista::inserir(int v){
    if(!this->cheia()){
        int i = 0;
        while(i<this->getQuantidade() && v>this->getItens(i))
            i++;
        if(v!=this->getItens(i)){
            for(int j=this->getQuantidade();j>i;j--)
                this->setItens(j, this->getItens(j-1));
            this->setItens(i, v);
            this->setQuantidade(this->getQuantidade()+1);
        }
    }
};


int Lista::remover(int v){
    if(!this->vazia()){
        int i = 0;
        while(i<this->getQuantidade() && v!=this->getItens(i))
            i++;
        if(i!=this->getQuantidade()){
            int r = this->getItens(i);
            for(int j=i;j<this->getQuantidade();j++)
                this->setItens(j, this->getItens(j+1));
            this->setQuantidade(this->getQuantidade()-1);
        }
    }
    return -1;
};

bool Lista::cheia(){
    return this->getTamanho() == this->getQuantidade();
};
bool Lista::vazia(){
    return this->getQuantidade() == 0;
};


void Lista::setItens(int i, int v){
    this->itens[i] = v;
};

int Lista::getTopo(){
    return this->getItens(this->getQuantidade()-1);
};

int Lista::getItens(int i){
    return this->itens[i];
};


void Lista::setTamanho(int n){
    this->tamanho = n;
};
void Lista::setQuantidade(int n){
    this->quantidade = n;
};

int Lista::getTamanho(){
    return this->tamanho;
};
int Lista::getQuantidade(){
    return this->quantidade;
};


int Lista::busca(int a){};

void Lista::mostra(){
    for(int i=0;i<this->getQuantidade();i++)
        cout << this->getItens(i) << endl;
};

int main(){
    int n, v;
    char c;
    Lista lista(1024);




    lista.inserir(6);
    lista.inserir(34);
    lista.inserir(12);
    lista.inserir(34);
    lista.inserir(12);
    lista.inserir(7);
    lista.remover(34);
    lista.remover(7);
    lista.remover(1);
    lista.inserir(1);
    lista.inserir(192);
    lista.mostra();
    


    
    
    
    return 0;
    
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> c >> v;
        if(c=='I') lista.inserir(v);
        if(c=='E') lista.remover(v);
    }
    lista.mostra();
    return 0;
}


