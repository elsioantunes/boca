#include <iostream>
using namespace std;

class Pilha{
    private:
        int *itens, tamanho, top;
    public: 
        Pilha(){};
        Pilha(int size){
            this->itens = new int[size];
            this->setTamanho(size);
            this->setTop(-1);
        };
        
        void setItens(int i, int v){this->itens[i] = v;};
        void setTop(int v){this->top = v;};
        void setTamanho(int v){this->tamanho = v;};
        int getTamanho(){return this->tamanho;};
        int getItens(int i){return this->itens[i];};
        int getTop(){return this->top;};
        
        void push(int v){
            if(!this->cheia()){
                this->setTop(this->getTop()+1);
                this->setItens(this->getTop(), v);
            }
            
        };
        
        int pop(){
            if(!this->vazia()){
                this->setTop(this->getTop()-1);
            return this->getItens(this->getTop()+1);
        };
        
        bool vazia(){return this->getTop()==-1;};
        bool cheia(){return this->getTop()==this->getTamanho()-1;};
        void mostra(){int n = this->getTop()+1;
        while(n--)
            cout << (n==this->getTop()?"":" ") << this->getItens(n);
        cout << endl;
};



int main(){
    int n;
    Pilha *p = new Pilha(5);
    while(cin >> n){
        if(n==13)
            p->mostra();
        else if(n==12)
            p->pop();
        else 
            p->push(n);
    }
    return 0;
}