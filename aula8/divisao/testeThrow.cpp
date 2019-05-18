#include <iostream>
#include <stdexcept>
using namespace std;

class parException : public runtime_error {
    public:
        parException(string text):runtime_error(text){
            
        };
};

class imparException : public runtime_error {
    public:
        imparException(string text):runtime_error(text){
        };
};

void teste(int a) throw(parException, imparException){
    if(a%2==0)
        throw parException("par, porra!");
    else
        throw parException("impar");
}

int main(){
    int a;

    while(cin >> a){
        try{
            teste(a);
        }catch(parException e){
            cout << e.what() << endl;
        }catch(imparException e){
            cout << e.what() << endl;
        }
    }
}

/*
coisas pra ler depois

http://blog.caelum.com.br/lidando-com-exceptions/
*/