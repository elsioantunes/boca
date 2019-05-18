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


int Lista::remover(int v){
    if(!this->vazia()){
        int i = 0;
        while(i<this->getQuantidade() && v!=this->getItens(i))
            i++;
        if(i!=this->getQuantidade()){
            int r = this->getItens(i);
            for(int j=i;j<this->getQuantidade();j++)
                this->setItens(j, this->getItens(j+1));
            this->setQuantidade(this->getQuantidade()-1);
            return r;
        }
    }
    return 0;
};

bool Lista::cheia(){
    return this->getTamanho() == this->getQuantidade();
};
bool Lista::vazia(){
    return this->getQuantidade() == 0;
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


// busca do Monael
int Lista::busca(int ch){
    int e=0, d=this->getQuantidade()-1, meio;
    while(e<=d){
        meio = (e+d)/2;
        if(this->getItens(meio) == ch) return meio;
        else if(this->getItens(meio) > ch) d = meio-1;
        else e = meio+1;
    }
    return -1;
}

void Lista::mostra(){
    for(int i=0;i<this->getQuantidade();i++)
        cout << this->getItens(i) << endl;
};

int main(){
    int q, r, v;
    char c;
    cin >> q >> r;
    
    Lista l1(q), l2(r);
    for(int i=0;i<q;i++){
        cin >> c >> v;
        if(c=='I')l1.inserir(v);
        if(c=='E')l1.remover(v);
    }
    for(int i=0;i<r;i++){
        cin >> c >> v;
        if(c=='I')l2.inserir(v);
        if(c=='E')l2.remover(v);
    }
    
    string str = "SIM";
    while(!l1.vazia()){
        if(!l2.remover(l1.getItens(l1.getQuantidade()-1))){
            str = "NAO";
            break;
        }
        l1.remover(l1.getItens(l1.getQuantidade()-1));
    }
    
    cout << str << endl;
    


    return 0;
}


