#include <iostream>
using namespace std;

template<class T>
class Pilha{

private:
    T *itens;
    int tamanho, quantidade;

public:
    void setItens(int i, T v){this->itens[i] = v;};
    void setTamanho(int n){this->tamanho = n;};
    void setQuantidade(int n){this->quantidade = n;};
    T getItens(int i){return this->itens[i];};
    int getTamanho(){return this->tamanho;};
    int getQuantidade(){return this->quantidade;};
    bool cheia(){return this->getTamanho() == this->getQuantidade();};
    bool vazia(){return this->getQuantidade() == 0;};
    ~Pilha(){delete this->itens;};
    
    Pilha(int n){
        this->itens = new T[n];
        this->setQuantidade(0);
        this->setTamanho(n);
    };
    
    void push(T v){
        if(!this->cheia()){
            this->setItens(this->getQuantidade(), v);
            this->setQuantidade(this->getQuantidade()+1);
        }
    };
    
    
    void pop(){
        if(!this->vazia())
            this->setQuantidade(this->getQuantidade()-1);
    };
    
    void mostra(){
        if(!this->vazia())
            cout << this->getItens(this->getQuantidade()-1) << endl;
    }
    
    void mostra(bool ord){
        if(!this->vazia()){
            int j = this->getQuantidade();
            for(int i=0;i<j;i++)
                cout << (i?" ":"") << this->getItens((ord?i:j-1-i));
            cout << endl;
        };
    }
};




int main(){
    int n;
    int m;
    char c;
    cin >> n;
    Pilha<int> *pilha = new Pilha<int>(n);
    while(cin >> c){
        if(c=='E') {
            cin >> m;
            pilha->push(m);
        };
        if(c=='D') pilha->pop();
        if(c=='B') pilha->mostra(true);
        if(c=='X') pilha->mostra(false);
        if(c=='T') pilha->mostra();
    }
    return 0;
}


