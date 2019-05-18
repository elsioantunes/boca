#include <iostream>
using namespace std;

class FilaELS{
    private:
        struct Celula{
            int n;
            Celula *prox;
        };
        Celula *ini, *fim, *aux;
    
    public:
        FilaELS(){
            ini = new Celula();
            ini->prox = NULL;
            fim = ini;
        };
        
        void inserir(int n){
            fim->prox = new Celula();
            fim = fim->prox;
            fim->n = n;
            fim->prox = NULL;
        };
        
        int remover(){      // isso passou no boca, mas ta errado!
            if(ini->prox){
                aux = ini;
                ini = ini->prox;
                delete aux;
                return ini->n;
            }
            return -1;
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

        ~FilaELS(){
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
    FilaELS fila;
    while(cin >> c){
        if(c=='E') {
            cin >> n;
            fila.inserir(n);
        }
        if(c=='D') {
            n = fila.remover();
            if(n!=-1)
                cout << "<" << n << ">" << endl;
        }
        if(c=='M') fila.mostra();
    };
    return 0;
}