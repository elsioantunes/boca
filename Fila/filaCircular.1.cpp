#include <iostream>
using namespace std;

class Fila{
private:
    int *itens, first, last, tamanho, quantidade;
    
public:
    Fila();
    ~Fila(){delete this->itens;}

    Fila(int size){
        this->setFirst(0);
        this->setLast(0);
        this->itens = new int[size];
        this->setQuantidade(0);
        this->setTamanho(size);
    };

    void setItens(int i, int v){this->itens[i] = v;};
    void setFirst(int n){this->first = n;}
    void setLast(int n){this->last = n;}
    void setTamanho(int n){this->tamanho = n;};
    void setQuantidade(int n){this->quantidade = n;};
    
    int getItens(int i){return this->itens[i];};
    int getQuantidade(){return this->quantidade;};
    int getTamanho(){return this->tamanho;};
    int getFirst(){return this->first;}
    int getLast(){return this->last;}
    
    void incFirst(){this->setFirst((this->getFirst()+1)%this->getTamanho());}
    void incLast(){this->setLast((this->getLast()+1)%this->getTamanho());}
    
    bool isFull(){
        //cout << "   [isFull] first:" << this->getFirst() << " ";
        //cout << "   [isFull] last:" << this->getFirst() << endl;
        return (this->getLast()+1)%this->getTamanho()==this->getFirst();
    };
    
    bool isEmpty(){
        //cout << "   [isEmpty] first:" << this->getFirst() << " ";
        //cout << "   [isEmpty] last:" << this->getFirst() << endl;
        return this->getFirst()==this->getLast();
    };
    
    void push(int v){
        //cout << "push " << v;
        if(!isFull()){
            //if(this->isEmpty()) this->incFirst();
            this->incLast();
            this->setItens(this->getLast(), v);
            //cout << " first: " << this->getLast() << endl;
        //}else{
            //cout << "  ..." << endl;
        }
    };
    
    int pop(){
        //cout << "pop: ";
        if(!this->isEmpty()){
            this->incFirst();
            int r = this->getItens(this->getFirst());
            //cout << r << endl;
            return r;
        }
        //cout << " fail" << endl;
        return -1;
    };
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
            if(r!=-1) cout << r << endl;
        }
    }

    return 0;
}


