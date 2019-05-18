#include <iostream>
using namespace std;

template<class T>
class Lista{

private:
    T *itens;
    int tamanho, quantidade;

public:
    bool cheia(){return this->getTamanho() == this->getQuantidade();};
    bool vazia(){return this->getQuantidade() == 0;};
    void setItens(int i, T v){this->itens[i] = v;};
    T getItens(int i){return this->itens[i];};
    void setTamanho(int n){this->tamanho = n;};
    void setQuantidade(int n){this->quantidade = n;};
    int getTamanho(){return this->tamanho;};
    int getQuantidade(){return this->quantidade;};
    ~Lista(){delete this->itens;};
    
    Lista(int n){
        this->itens = new T[n];
        this->setQuantidade(0);
        this->setTamanho(n);
    };
    
    
    void inserir(T v){
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
    
    
    int remover(T v){
        if(!this->vazia()){
            int i = 0;
            while(i<this->getQuantidade() && v!=this->getItens(i))
                i++;
            if(i!=this->getQuantidade()){
                T r = this->getItens(i);
                for(int j=i;j<this->getQuantidade();j++)
                    this->setItens(j, this->getItens(j+1));
                this->setQuantidade(this->getQuantidade()-1);
                return r;
            }
        }
        return 0;
    };
    
    int busca(T v){
        for(int i=0;i<this->getQuantidade();i++)
            if(this->getItens(i)==v)return true;
        return false;
    };
    
    void mostra(){
        if(!this->vazia()){
            for(int i=0;i<this->getQuantidade();i++)
                cout << (i?" ":"") << this->getItens(i);
            cout << endl;
        }
    };
    
};




int main(){
    int n;
    char m;
    char c;
    cin >> n;
    Lista<char> *lista = new Lista<char>(n);
    while(cin >> c){
        if(c=='B'){
            cin >> m;
            cout << (lista->busca(m)?"SIM":"NAO") << endl;
        }
        if(c=='I'){
            cin >> m;
            lista->inserir(m);
        }
        if(c=='R'){
            cin >> m;
            lista->remover(m);
        }
        if(c=='M')lista->mostra();
    }

    return 0;
}


