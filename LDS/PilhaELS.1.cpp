#include <iostream>
using namespace std;

class PilhaELS{
    private:
        struct Celula{
            int n, sentinela;
            Celula *prox;
        };
        Celula *ini, *fim, *aux;
    public:
        PilhaELS(){
            ini = new Celula();
            fim = ini;
            fim->prox = NULL;
        };
        void inserir(int n){
            aux = ini->prox;
            ini->prox = new Celula();
            ini->prox->n = n;
            ini->prox->prox = aux;
        };
        
        int remover(){
            if(ini->prox){
                aux = ini->prox->prox;
                int r = ini->prox->n;
                ini->prox = aux;
                return r;
            }
            return false;
        };
        
        void mostra(){
            if(ini->prox){
                aux = ini;
                while(ini = ini->prox)
                    cout << (ini==aux->prox?"":" ") << ini->n;
                ini = aux;
                cout << endl;
            }
        };                   

        ~PilhaELS(){
            while(ini){
                aux = ini;
                ini = ini->prox;
                delete aux;
            }
        };
};

int main(){
    char c;
    int n;
    PilhaELS pilha;
    while(cin >> c){
        if(c=='E') {
            cin >> n;
            pilha.inserir(n);
        }
        if(c=='D') {
            n = pilha.remover();
            if(n)
                cout << "[" << n << "]" << endl;
        }
        if(c=='M') pilha.mostra();
    };
    return 0;
}