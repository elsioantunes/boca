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


template<typename T>
void printArray(T *v, int n){
    Pilha<T> *p = new Pilha<T>(n);
    for(int i=0;i<n;i++){
        p->push(v[i]);
    }
    p->mostra();
};

int main(){
    int n;
    string tipo;

    while(true){
        cin >> n;
        if(n==0)break;
        int k=0;
        cin >> tipo;
    
        if(tipo=="int"){
            int m;
            int *V = new int[n];
            for(int i=0;i<n;i++){
                cin >> m;
                V[k++] = m;
            }
            printArray(V, n);
        }
    
    
        if(tipo=="char"){
            char m;
            char *V = new char[n];
            for(int i=0;i<n;i++){
                cin >> m;
                V[k++] = m;
            }
            printArray(V, n);
        }
    
    
        if(tipo=="float"){
            float m;
            float *V = new float[n];
            for(int i=0;i<n;i++){
                cin >> m;
                V[k++] = m;
            }
            printArray(V, n);
        }
    
    
        if(tipo=="string"){
            string m;
            string *V = new string[n];
            for(int i=0;i<n;i++){
                cin >> m;
                V[k++] = m;
            }
            printArray(V, n);
        }
    }
    


   return 0;
}