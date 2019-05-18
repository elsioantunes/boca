#include <iostream>
using namespace std;

class Racional{
private:
    int a, b;

public:
    Racional(){};
    Racional(int a, int b){
        this->a = a;
        this->b = b;
    };

    Racional reduz(){
        int t;
        int a = this->a;
        int b = this->b;
        while(b){
            t=b;
            b=a%b;
            a=t;
        }
        a = (a>0?a:-a);
        return Racional(this->a /=a, this->b /=a);
    };
    
    bool operator == (Racional m){
        m.reduz();
        this->reduz();
        if(m.a==this->a&&m.b==this->b) return true;
        return false;
    }
    
};


int main(){
    int a, b, c, d;
    while(cin >> a >> b >> c >> d){
        Racional p(a,b), q(c,d);
        cout << (p==q?"S":"N") << endl;
    }
    return 0;
}


