#include <iostream>
using namespace std;


class Fila{

private:
    int *itens, first, last, tamanho, quantidade;
    
public:
    
    Fila();
    Fila(int size){
        this->setFirst(0);
        this->setLast(0);
        this->itens = new int[size];
        this->setQuantidade(0);
        this->setTamanho(size);
    };
    ~Fila(){
        delete this->itens;
    }
    
    void setItens(int i, int v){
        this->itens[i] = v;
    };

    void setFirst(int n){
        this->first = n;
    }
    void setLast(int n){
        this->last = n;
    }
    
    void setTamanho(int n){
        this->tamanho = n;
    };
    
    void setQuantidade(int n){
        this->quantidade = n;
    };
    

    int getItens(int i){
        return this->itens[i];
    };

    
    int getQuantidade(){
        return this->quantidade;
    };


    int getTamanho(){
        return this->tamanho;
    };

    
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
        return -1; // no pdf tá dizendo que o zero serve. Nao serve!
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


