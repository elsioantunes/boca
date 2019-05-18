#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

class divisaoException : public runtime_error {
    public:
        divisaoException():runtime_error("runtime error: divisao por zero."){};
};

double divisao(int a, int b) throw(divisaoException){
    if(b==0)
        throw divisaoException();
    else
        return double(a)/b;
}

int main(){
    int a, b;
    while(cin >> a >> b){
        try{
            cout << "resultado: " << fixed << setprecision(2) << divisao(a, b) << endl;
        }catch(divisaoException elsio){
            cout << elsio.what() << endl;
        }
    }
}