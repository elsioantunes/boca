#include <iostream>
using namespace std;

template <class T>
class Pilha{
    private:
        int tamanho, top;
        T *itens;
    public: 
        void setItens(int i, T v){this->itens[i] = v;};
        void setTop(int v){this->top = v;};
        void setTamanho(int v){this->tamanho = v;};
        int getTamanho(){return this->tamanho;};
        T getItens(int i){return this->itens[i];};
        int getTop(){return this->top;};
        bool vazia(){return this->getTop()==-1;};
        bool cheia(){return this->getTop()==this->getTamanho()-1;};

        Pilha(){};
        Pilha(int size){
            this->itens = new T[size];
            this->setTamanho(size);
            this->setTop(-1);
        };

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
        
        void mostra(){
            int n = this->getTop()+1;
            while(n--)
                cout << (n==this->getTop()?"":" ") << this->getItens(n);
            cout << endl;
        }
};


template<typename T>
void printArray(T lol, int n){
    Pilha<T> *p = new Pilha<T>(n); T m;
    for(int i=0;i<n;i++) cin >> m, p->push(m);
    p->mostra();
};

int main(){
    int n;
    string tipo;

    while(true){
        cin >> n; if(n==0)break;
        int k=0; cin >> tipo;
    
        if(tipo=="int") printArray((int)1,n);
        if(tipo=="char") printArray((char)1,n);
        if(tipo=="float") printArray((float)1,n);
        if(tipo=="string") printArray((string)"",n);
    }
   return 0;
}