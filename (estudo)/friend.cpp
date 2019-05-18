#include <iostream>
using namespace std;

class Teste{
    private:
        int *itens;
    public:
        Teste();
        Teste(int size){
            itens = new int[size];
            itens[2] = 3;
        };
        int operator[](int i){
            return itens[i];
        };

};




int main(){
    
    Teste *t = new Teste(5), q=*t;

    
    
    cout << q[2]<< endl;
    return 0;
}


