// Lista Estatica Sequencial genérica e segura (não esquecer de fazer a dinâmica tb. e em java tb)
#include <iostream>
#include <stdexcept>
using namespace std;

class MeuErro:public runtime_error{
    public:
        MeuErro(string str):runtime_error(str){}
};

template<class T>
class LESSegura{
    private:
        T *itens;
        int tamanho, quantidade;
        
    public:
        LESSegura(){};
        LESSegura(int size){
            this->setTamanho(size);
            this->setQuantidade(0);
            this->itens = new T[size];
        };
        
        void inserir(T v){
            if(this->cheia()) throw MeuErro("Runtime Error: Lista cheia.");
            int i=0;
            while(i<this->getQuantidade() && v>this->getItens(i))
                i++;
            if(v==this->getItens(i)) throw MeuErro("Logic Error: Chave existente na lista.");
            for(int j=this->getQuantidade();j>i;j--)
                this->setItens(j, this->getItens(j-1));
            this->setItens(i, v);
            this->setQuantidade(this->getQuantidade()+1);
        }
        
        void remover(T v){
            if(this->vazia()) throw MeuErro("Runtime Error: Lista Vazia.");
            int i=0;
            while(i<this->getQuantidade()&&v!=this->getItens(i))
                i++;
            if(i==this->getQuantidade()) throw MeuErro("Logic Error: Chave inexistente na lista.");
            for(int j=i;j<this->getQuantidade()-1;j++)
                this->setItens(j, getItens(j+1));
            this->setQuantidade(this->getQuantidade()-1);
        }
        
        void buscar(T v){
            if(this->vazia())throw MeuErro("Runtime Error: Lista Vazia.");
            for(int i=0;i<this->getQuantidade();i++)
                if(v==this->getItens(i)) throw MeuErro("SIM");
            throw MeuErro("NAO");
        }
        
        void exibir(int i){
            // if(this->vazia())throw MeuErro("Runtime Error: Lista Vazia."); // ????????????? erro do professor!
            if(i<0||i>this->getQuantidade()-1) throw MeuErro("Runtime Error: Posicao da lista inexistente.");
            cout << "<" << this->getItens(i) << ">" << endl;
        }

        void exibir(){
            if(this->vazia())throw MeuErro("Runtime Error: Lista Vazia.");
            for(int i=0;i<this->getQuantidade();i++)
                cout << (i?" ":"") << this->getItens(i);
            cout << endl;
        }
        
        void setTamanho(T v){this->tamanho = v;};
        void setQuantidade(T v){this->quantidade = v;};
        void setItens(int i, T v){this->itens[i]=v;};
        int getTamanho(){return this->tamanho;};
        int getQuantidade(){return this->quantidade;};
        T getItens(int i){return this->itens[i];}
        bool cheia(){return this->getQuantidade()==this->getTamanho();};
        bool vazia(){return this->getQuantidade()==0;};
};

int main(){
    int n;
    int m;
    char c;
    LESSegura<int> *lista;
    cin >> n;
    lista = new LESSegura<int>(n);
    while(cin >> c){
        try{
            if(c=='I') cin >> m, lista->inserir(m);
            if(c=='E') cin >> m, lista->remover(m);
            if(c=='B') cin >> m, lista->buscar(m);
            if(c=='C') cin >> m, lista->exibir(m);
            if(c=='M') lista->exibir();
            
        }catch(MeuErro e){
            cout << e.what() << endl;
        }
    }
    
    
    
    
    return 0;
}
