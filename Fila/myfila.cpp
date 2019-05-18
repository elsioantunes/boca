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
            return r;
        }
    }
    return 0;
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











class Fila: public Lista{

private:
    int first, last;
    
public:
    
    Fila();
    Fila(int size):Lista(size){
        this->setFirst(0);
        this->setLast(0);
    };
    
    void setFirst(int n){
        this->first = n;
    }
    void setLast(int n){
        this->last = n;
    }
    
    int getFirst(){
        return this->first;
    }
    int getLast(){
        return this->last;
    }
    
    void push(int v){
        
        if(this->getFirst()<this->getTamanho()){

            this->setItens(this->getFirst(),v);
            this->setFirst(this->getFirst()+1);
            this->setQuantidade(this->getQuantidade()+1);
        }
    }

    int pop(){

        if(this->getQuantidade()>0){

            int r = this->getItens(this->getLast());
            this->setLast(this->getLast()+1);
            if(this->getQuantidade()==1){
                this->setQuantidade(0);
                this->setFirst(0);
                this->setLast(0);
            }else{
                this->setQuantidade(this->getQuantidade()-1);            
            }
            return r;
        }
        return -1;
    }
};




int main(){
    int size, v;
    char c;
    
    cin >> size;
    Fila f(size);

    while(cin >> c){
        if(c=='E') {
            cin >> v;
            f.push(v);
        }
        if(c=='D') {
            int r = f.pop();
            if(r!=-1)cout << r << endl;
        }
    }

    return 0;
}


