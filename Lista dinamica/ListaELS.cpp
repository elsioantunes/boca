#include <iostream>
using namespace std;

class ListaELS{
    private:
        struct Celula{
            int n;
            Celula *prox;
        };
        Celula *ini, *aux, *aux2;

    public:
        ListaELS(){
            ini = new Celula();
            ini->prox = NULL;
        };
        int operator +=(int n){
            aux = ini;
            while(aux->prox){
                if(aux->prox->n>n)break;
                aux = aux->prox;
            }
            if(aux->n!=n){
                aux2 = aux->prox;
                aux->prox = new Celula();
                aux->prox->prox = aux2;
                aux->prox->n = n;
            };
        };
        
        void remover(int n){
            if(ini->prox){
                aux = ini;
                while(aux->prox){
                    if(aux->prox->n==n){
                        aux2 = aux->prox->prox;
                        delete aux->prox;
                        aux->prox = aux2;
                        break;
                    } 
                    aux = aux->prox;
                }
            }
        };

        bool buscar(int n){
            if(ini->prox){
                aux = ini;
                while(aux->prox){
                    aux = aux->prox;
                    if(aux->n==n) return true;
                }
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

        ~ListaELS(){
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
    ListaELS lista;
    while(cin >> c){
        if(c=='I') {
            cin >> n;
            lista += n;
        }
        if(c=='R') {
            cin >> n;
            lista.remover(n);
        }
        if(c=='B') {
            cin >> n;
            cout << (lista.buscar(n)?"SIM":"NAO") << endl;
        }
        if(c=='L') lista.mostra();
    };
    return 0;
}