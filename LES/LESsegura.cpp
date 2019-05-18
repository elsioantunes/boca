#include <iostream>
#include <stdexcept>
using namespace std;

// Confirmado!
// O pdf diz claramente:
//      "Caso a operação tente remover ou exibir as chaves de uma LES vazia 
//      de-vese exibir a seguinte mensagem: “Runtime Error: Lista Vazia.”."
// O seu código não está condizente com sua própria regra.

// Por isso sempre reclamei de usar o boca no lugar do URI, Spoj, UVA etc...
// Judges públicos tem uma coisa que o boca não tem: milhares de olhos nos erros.
// porque programar de improviso se é possivel adaptar os milhares de problemas 
// já exaustivamente testados disponíveis, por ex, no site da maratona?

// Se sou eu que cometo um erro de lógica na prova é F na questão né?

// Desculpe minha indgnação. 
// é que é muito irritante saber que a lógica tá certa mas a máquina não aceita.
// e que vou ser reprovado independentemente da minha dedicação aos exercícios.
// talvez vc nem vá ler isso...


class logicError : public runtime_error{
    public:
        logicError(string str):runtime_error(str){
        }
};

class Lista{
    private:
        int *itens, tamanho, quantidade;

    public:
        Lista(int);
        ~Lista();
    
        void setTamanho(int);
        void setQuantidade(int);
        void setItens(int, int);
    
        int getTamanho();
        int getQuantidade();
        int getItens(int);
    
        void inserir(int);
        void buscar(int);
        void remover(int);
        void mostrar(int);
        void mostrar();
        void cheia();
        void vazia();
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
    this->cheia();
    int i=0;
    for(;i<this->getQuantidade() && v>this->getItens(i);i++);
    if(v==this->getItens(i)) throw logicError("Logic Error: Chave existente na lista.");
    
    for(int j=this->getQuantidade();j>i;j--)
        this->setItens(j, this->getItens(j-1));
    this->setItens(i, v);
    this->setQuantidade(this->getQuantidade()+1);
};

void Lista::remover(int v){
    this->vazia();
    int i=0;
    for(;i<this->getQuantidade() && v!=this->getItens(i);i++);
    if(i==this->getQuantidade()) throw logicError("Logic Error: Chave inexistente na lista.");
    for(int j=i;j<this->getQuantidade();j++)
        this->setItens(j, this->getItens(j+1));
    this->setQuantidade(this->getQuantidade()-1);
};

void Lista::buscar(int v){
    // this->vazia();
    int esq = 0, meio, dir = this->getQuantidade()-1;
    while(esq<=dir){
        meio = (esq+dir)/2;
        int t = this->getItens(meio);
        if(t==v) throw logicError("SIM");
        if(t>v) dir = meio-1;
        if(t<v) esq = meio+1;
    } 
    throw logicError("NAO");
};

void Lista::mostrar(int i){
    //this->vazia();           // ???????????????
    if(i<0 || i>=this->getQuantidade())  throw logicError("Runtime Error: Posicao da lista inexistente.");
    cout << "<" << this->getItens(i) << ">" << endl;
}

void Lista::mostrar(){
    this->vazia();
    for(int i=0;i<this->getQuantidade();i++)
        cout << (i?" ":"") << this->getItens(i);
    cout << endl;
};

void Lista::cheia(){
    if(this->getTamanho() == this->getQuantidade())
        throw logicError("Runtime Error: Lista cheia.");
};
void Lista::vazia(){
    if(!this->getQuantidade())
        throw logicError("Runtime Error: Lista Vazia.");
};

void Lista::setItens(int i, int v){this->itens[i] = v;};
void Lista::setQuantidade(int n){this->quantidade = n;};
void Lista::setTamanho(int n){this->tamanho = n;};

int Lista::getItens(int i){return this->itens[i];};
int Lista::getQuantidade(){return this->quantidade;};
int Lista::getTamanho(){return this->tamanho;};

int main(){
    int n, size; char c; Lista *lista;
    
    cin >> size;
    lista = new Lista(size);
    
    while(cin >> c)
        try{
            if(c=='I'){cin >> n;lista->inserir(n);}
            if(c=='E'){cin >> n;lista->remover(n);}
            if(c=='B'){cin >> n;lista->buscar(n);}
            if(c=='C'){cin >> n;lista->mostrar(n);}
            if(c=='M') lista->mostrar();
        }catch(logicError e){
            cout << e.what() << endl;
        }
    return 0;
}


