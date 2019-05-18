#include <iostream>
#include <string>
using namespace std;

struct Racional{
    int a, b;
};

Racional racional(int x, int y){
    Racional f;
    f.a = x;
    f.b = y;
    return f;
};

Racional soma(Racional f1, Racional f2){
    return racional( f1.a*f2.b + f1.b*f2.a,  f1.b*f2.b);
};

Racional negativo(Racional f){
    return racional(f.a*-1,f.b);
};

Racional sub(Racional f1, Racional f2){
    return soma(f1, negativo(f2));
};

Racional mult(Racional f1, Racional f2){
    return racional(f1.a*f2.a,f1.b*f2.b);
};

Racional divisao(Racional f1, Racional f2){
    return racional(f1.a*f2.b,f1.b*f2.a);
};

int mdc(Racional f){
    int t, a = f.a, b = f.b;
    while(b){t=b;b=a%b;a=t;}
    return (a>0?a:-a);
};

Racional reduz(Racional f){
    return racional(f.a/mdc(f),f.b/mdc(f));
};

int main(){
    int a,b,c,d;
    string op;
    while (cin >> a >> b>> op>> c>> d) {
    
        Racional f1,f2,r;
        f1.a = a;  f1.b = b;
        f2.a = c;  f2.b = d;
        
        if(op=="+") r = soma(f1,f2);
        if(op=="-") r = sub(f1,f2);
        if(op=="/") r = divisao(f1,f2);
        if(op=="*") r = mult(f1,f2);
        r = reduz(r);

        cout << r.a << " " << r.b << endl;
    }
    return 0;
}


