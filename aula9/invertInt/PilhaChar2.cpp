#include <iostream>

template <class T>
class Pilha {
private:
    T *itens;
    int tamanho, topo;

public:
    Pilha();
    Pilha(int);
    void setItens(int, T);
    void setTamanho(int);
    void setTopo(int);
    T getItens(int);
    int getTamanho();
    int getTopo();
    bool cheia();
    bool vazia();

    void empilha(T);
    void desempilha();
    void Top();
    void topdown();
    void buttomup();

};

template <class T>
Pilha<T>::Pilha() {

}

template <class T>
Pilha<T>::Pilha(int n) {
    this->itens = new T[n];
    this->setTamanho(n);
    this->setTopo(-1);
}

template <class T>
void Pilha<T>::setItens(int p, T ch) {
    this->itens[p] = ch;
}

template <class T>
void Pilha<T>::setTamanho(int n) {
    this->tamanho = n;
}

template <class T>
void Pilha<T>::setTopo(int n) {
    this->topo = n;
}

template <class T>
T Pilha<T>::getItens(int p) {
    return this->itens[p];
}

template <class T>
int Pilha<T>::getTamanho() {
    return this->tamanho;
}

template <class T>
int Pilha<T>::getTopo() {
    return this->topo;
}

template <class T>
bool Pilha<T>::vazia() {
    if(this->getTopo() == -1) {
        return true;
    } else {
        return false;
    }
}

template <class T>
bool Pilha<T>::cheia() {
    if(this->getTopo() == this->getTamanho()-1) {
        return true;
    } else {
        return false;
    }
}

template <class T>
void Pilha<T>::empilha(T ch) {
    if(this->cheia() == false) {
        if(this->vazia() == true ) {
            this->setTopo(this->getTopo() + 1);
            this->setItens(this->getTopo(), ch);

        } else {
            this->setTopo(this->getTopo() + 1);
            this->setItens(this->getTopo(), ch);

        }
    }
}

template <class T>
void Pilha<T>::desempilha() {
    if(this->vazia()==false) {
        this->setTopo(this->getTopo()-1);
    }

}

template <class T>
void Pilha<T>::Top() {
    if(this->vazia()==false) {
        std::cout<<this->getItens(this->getTopo())<<std::endl;
    }
}

template <class T>
void Pilha<T>::topdown() {
    if(this->vazia() == false) {
        int i;
        for(i = this->getTopo(); i>=0; i--) {
            if(i!=0) {
                std::cout<<this->getItens(i)<<" ";
            } else {
                std::cout<<this->getItens(i)<<std::endl;

            }
        }
    }
}

template <class T>
void Pilha<T>::buttomup() {
    if(this->vazia() == false) {
        int i;
        for(i = 0; i<= this->getTopo(); i++) {
            if(i!=this->getTopo()) {
                std::cout<<this->getItens(i)<<" ";
            } else {
                std::cout<<this->getItens(i)<<std::endl;

            }
        }
    }
}




int main() {

    int n,i;
    char m;
    char op;
    Pilha<char> *novapilha;

    std::cin>>n;

    novapilha = new Pilha<char>(n);




    while(std::cin>>op ) {

        if(op == 'E') {
            std::cin>>m;
            novapilha->empilha(m);
        } else if(op == 'D') {
            novapilha->desempilha();
        } else if(op == 'T') {
            novapilha->Top();
        } else if(op == 'B') {
            novapilha->buttomup();
        } else {
            novapilha->topdown();
        }


    }


    return 0;
}
