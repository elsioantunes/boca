#include <iostream>
using namespace std;

template <class T>
class Pilha{
    private:
        int tamanho, top;
        T *itens;
    public: 
        Pilha(){};
        Pilha(int size){
            this->itens = new T[size];
            this->setTamanho(size);
            this->setTop(-1);
        };
        
        void setItens(int i, T v){this->itens[i] = v;};
        void setTop(int v){this->top = v;};
        void setTamanho(int v){this->tamanho = v;};
        int getTamanho(){return this->tamanho;};
        T getItens(int i){return this->itens[i];};
        int getTop(){return this->top;};
        
        void push(T v){
            if(!this->cheia()){
                this->setTop(this->getTop()+1);
                this->setItens(this->getTop(), v);
            }
        };
        
        T pop(){
            if(!this->vazia()){
                this->setTop(this->getTop()-1);
                return this->getItens(this->getTop()+1);
            }
        };
        
        bool vazia(){return this->getTop()==-1;};
        bool cheia(){return this->getTop()==this->getTamanho()-1;};
        void mostra(){
            int n = this->getTop()+1;
            while(n--)
                cout << (n==this->getTop()?"":" ") << this->getItens(n);
            cout << endl;
        }
};


int main(){
    int n;
    string tipo;
    cin >> n >> tipo;

    tipo m;
    Pilha<tipo> *p = new Pilha<tipo>(n);

    for(int i=0;i<n;i++){
        cin >> m;
        p->push(m);
    }
    //p->mostra();
    
    return 0;
}