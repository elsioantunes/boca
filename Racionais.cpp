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

    Racional operator + (Racional r){
        return Racional(this->a*r.b + this->b*r.a, this->b*r.b);
    }
    
    Racional operator - (Racional r){
        return Racional(this->a*r.b - this->b*r.a, this->b*r.b);
    }
    
    Racional operator * (Racional r){
        return Racional(this->a*r.a, this->b*r.b);
    }
    
    Racional operator / (Racional r){
        return Racional(this->a*r.b, this->b*r.a);
    }
    

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
    }

    void mostra(){
        cout << this->a << " " << this->b << endl;
    }
};

int main(){
    int a,b,c,d;
    char s;
    while ((cin >> a >> b>> s >> c>> d)) {

        Racional f1(a,b),f2(c,d),r;

        if(s=='+') r = f1 + f2;
        if(s=='-') r = f1 - f2;
        if(s=='/') r = f1 / f2;
        if(s=='*') r = f1 * f2;
        r.reduz();
        r.mostra();
    }
    return 0;
}


