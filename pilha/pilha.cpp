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
    void incQuantidade();
    void decQuantidade();
    int getItens(int);
    void inserir(int);
    int busca(int);
    int remover(int);
    void mostra();
    bool cheia();
    bool vazia();
    
    void push(int);
    void pop();
};


Lista::Lista(int n){
    //cout << "hello pai!: " << n << endl;
    this->itens = new int[n];
    this->setTamanho(n);
    this->setQuantidade(0);
};

Lista::~Lista(){
    delete this->itens;
};


void Lista::push(int v){
    if(this->getQuantidade()<this->getTamanho()){
        this->itens[this->getQuantidade()] = v;
        this->incQuantidade();
    }
}

void Lista::pop(){
    this->decQuantidade();
}

void Lista::inserir(int v){

/*

void inserir(lista *l1, int valor){ // insere, ordenadamente, um valor na lista
    int i=0;
    while(i<(*l1).tam && valor>=(*l1).elem[i])
        i++;
    for(int j=(*l1).tam; j>i; j--)
        (*l1).elem[j] = (*l1).elem[j-1];
    (*l1).elem[i] = valor;
    (*l1).tam++;}

*/    

    if(this->getQuantidade()==0){
        this->itens[0] = v;
    }else{
        if(v>this->getTopo()){
            this->itens[this->getQuantidade()] = v;
        }else{
            this->itens[this->getQuantidade()] = itens[this->getQuantidade()-1];
        }
    }
    this->setQuantidade(this->getQuantidade()+1);
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
void Lista::incQuantidade(){
    this->quantidade++;
};
void Lista::decQuantidade(){
    if(this->quantidade)
        this->quantidade--;
};


bool Lista::cheia(){
    return this->getTamanho() == this->getQuantidade();
};
bool Lista::vazia(){
    return this->getQuantidade() == 0;
};


int Lista::busca(int a){};
int Lista::remover(int a){};


void Lista::mostra(){
    for(int i=0;i<this->getQuantidade();i++)
        cout << this->getItens(i) << endl;
};


class Pilha : public Lista{
private:
public:
    
    Pilha(int n):Lista(n){
    };
    
    void push(int v){
        //cout << "push: " << v<< endl;
        this->Lista::push(v);
    }

    void pop(){
        //cout << "pop: " << endl;
        this->Lista::pop();
    }

    void imprime_b(){
        //cout << "imprimindo base" << endl;
        for(int i=0;i<this->getQuantidade();i++)
            cout << this->getItens(i) << endl;
    }

    void imprime_t(){
        //cout << "imprimindo topo" << endl;
        int n = this->getQuantidade();
        for(int i=0;i<n;i++)
            cout << this->getItens(n-i-1) << endl;
    }
};



int main(){
    int n, v;
    char c;
    
    cin >> n;
    Pilha pilha(n);
    while(cin >> c){
        if(c=='E') {
            cin >> v;
            pilha.push(v);
        }
        if(c=='T') pilha.imprime_t();
        if(c=='B') pilha.imprime_b();
        if(c=='D') pilha.pop();
    }
    return 0;
}


