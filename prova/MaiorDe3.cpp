#include <iostream>
using namespace std;

class Racional{
public:
    int a, b;
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
    

    bool operator > (Racional m){
        if(this->a*m.b > this->b*m.a) return true;
        return false;
    }
};



template <typename T>
T maiordetres(T a, T b, T c){
    if(a > b && a > c) return a;
    if(b > a && b > c) return b;
    if(c > a && c > b) return c;
    return a;
}

int main(){
    string str;
    while(cin >> str){
        if(str=="char"){
            char a, b, c;
            cin >> a >> b >> c;
            cout << maiordetres(a,b,c) << endl;
            
        }else if(str=="int"){
            int a, b, c;
            cin >> a >> b >> c;
            cout << maiordetres(a,b,c) << endl;

        }else if(str=="float"){
            float a, b, c;
            cin >> a >> b >> c;
            cout << maiordetres(a,b,c) << endl;
            
        }else{
            int u, v, w, d, e, f;
            cin >> u >> v >> w >> d >> e >> f;
            Racional a(u,v), b(w,d), c(e,f),r;
            
            if(a > b && a > c) cout << a.a <<"/"<<a.b<<  endl;
            if(b > a && b > c) cout << b.a <<"/"<<b.b<<  endl;
            if(c > a && c > b) cout << c.a <<"/"<<c.b<<  endl;
            
            cout << "fodeu!" << endl;
            
        }
    }
    return 0;
}


