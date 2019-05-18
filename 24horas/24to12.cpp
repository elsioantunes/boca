#include <string>
#include <iostream>
using namespace std;

class Hora{

private:
    int h, m, s;

public:
    Hora(){};

    Hora(int h, int m, int s){
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

    void mostra(){
        int h, m, s, n;
        h = this->getHor();
        m = this->getMin();
        s = this->getSeg();

        cout << h << ":" << m << ":" << s << endl;
    };
    
};





class Hour{

private:
    int h, m, s;
    string ampm;

public:
    Hour(){};

    Hour(int h, int m, int s, string str){
        this->setHor(h);
        this->setMin(m);
        this->setSeg(s);
        this->setAmpm(" "+str);
    };
    
    Hour(Hora Hr){
        int h, m, s;
        h = Hr.getHor();
        m = Hr.getMin();
        s = Hr.getSeg();
        this->convert(h,m,s);
    };
    
    void convert(int h, int m, int s){
        int n = h*60*60+m*60+s;
        
        this->setAmpm(" AM");
        if(n>=43200){
          this->setAmpm(" PM");
          h -=12;
        } 
        if(h==0) h=12;

        this->setHor(h);
        this->setMin(m);
        this->setSeg(s);
    }
    

    void setHor(int h){
        this->h=h;
    };
    void setMin(int m){
        this->m=m;
    };
    void setSeg(int s){
        this->s=s;
    };
    void setAmpm(string s){
        this->ampm=s;
    };


    string getAmpm(){
        return this->ampm;
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

    void mostra(){
        int h, m, s;
        string str;
        h = this->getHor();
        m = this->getMin();
        s = this->getSeg();
        str = this->getAmpm();
        cout << h << ":" << m << ":" << s << str << endl;
    };
    

    operator Hora(){
        Hora Hr;
        int h = this->getHor();
        Hr.setMin(this->getMin());
        Hr.setSeg(this->getSeg());
        
        if(this->getAmpm() == " AM"){
            if(h==12)h=0;
        }else{
            if(h!=12)h+=12;
        }

        
        Hr.setHor(h);
        return Hr;
    }
};

int main(){
    int h, m, s;
    while(cin>>h>>m>>s){
        Hour M = Hora(h,m,s);
        M.mostra();
    }
    return 0;
}