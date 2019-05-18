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

int main(){
    int n, v;
    char c;
    Lista lista(1024);




    cout << ":"<< lista.getQuantidade() << endl;
    lista.inserir(12);
    lista.inserir(7);
    lista.inserir(6);
    lista.inserir(2);
    lista.inserir(1);
    lista.inserir(192);

    
    cout << ":"<< lista.getQuantidade() << endl;
    lista.mostra();
    cout << ":"<< lista.getQuantidade() << endl;
    


    
    
    
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


