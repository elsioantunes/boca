#include <iostream>
using namespace std;

class Chrono{

private:
    int h, m, s;

public:
    Chrono(){};

    Chrono(int h, int m, int s){
        this->setHor(h);
        this->setMin(m);
        this->setSeg(s);
    };

    void setHor(int h){
        this->h=h;
    };
    void setMin(int m){
        this->m=m;
    };
    void setSeg(int s){
        this->s=s;
    };


    int getHor(){
        return this->h;
    };
    int getMin(){
        return this->m;
    };
    int getSeg(){
        return this->s;
    };


    void incSeg(){
        if(this->getSeg()<59) 
            this->setSeg(this->getSeg()+1);
        else{ 
            this->setSeg(0);
            this->incMin();
        }
            
    };

    void incMin(){
        if(this->getMin()<59) 
            this->setMin(this->getMin()+1);
        else{
            this->setMin(0);
            this->incHor();
        }
    };

    void incHor(){
        if(this->getHor()<23) 
            this->setHor(this->getHor()+1);
        else{
            this->setHor(0);
        }
    };


    void mostra(){
        int h, m, s, n;
        string ampm = " AM";
        h = this->getHor();
        m = this->getMin();
        s = this->getSeg();
        n = h*60*60+m*60+s;
        
        if(n>=43200){
          ampm = " PM";
          h -=12;
        } 
        if(h==0)h=12;
        cout << h << ":" << m << ":" << s << ampm << endl;
    };
    
};

class Relogio3 : public Chrono {
private:
public:
    Relogio3(){};
    Relogio3(int h, int m, int s):Chrono(h,m,s){}
};


int main(){
    string str;
    int h=0, m=0, s=0;
    //cin >> h >> m >> s;
    Relogio3 t(h,m,s);
    while(cin>>str){
        if(str=="tic") t.incSeg();
        if(str=="tac") t.incMin();
        if(str=="toc") t.incHor();
    }
    t.mostra();
    return 0;
}


