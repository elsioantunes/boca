#include <iostream>
using namespace std;

class Data{

private:
    int dia, mes, ano;

public:
    Data(){};

    Data(int d, int m, int a){
        this->setDia(d);
        this->setMes(m);
        this->setAno(a);
    };

    void setDia(int d){
        this->dia=d;
    };
    void setMes(int m){
        this->mes=m;
    };
    void setAno(int a){
        this->ano=a;
    };


    int getDia(){
        return this->dia;
    };
    int getMes(){
        return this->mes;
    };
    int getAno(){
        return this->ano;
    };


    void incDia(){
        this->setDia(this->getDia()+1);
    };
    void incMes(){
        this->setMes(this->getMes()+1);
    };
    void incAno(){
        this->setAno(this->getAno()+1);
    };

    void decDia(){
        this->setDia(this->getDia()-1);
    };
    void decMes(){
        this->setMes(this->getMes()-1);
    };
    void decAno(){
        this->setAno(this->getAno()-1);
    };


    bool bissexto(int a){
        return ((a%4)==0 && (a%100)!= 0) || (a%400)==0;    
    };
    
    int diames(int m){
        int dm[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
        if(this->bissexto(this->getAno())&&m==2) 
            return 29;
        else
            return dm[m];
    };
        
    void mostra(){
        cout << this->getDia() << "/" << this->getMes() << "/" << this->getAno() << endl;
    };
    
    void operator ++(int){
        if(this->getDia()<this->diames(this->getMes())){
            this->incDia();
        }else {
            this->setDia(1);
            if(this->getMes()<12){
                this->incMes();
            }else{
                this->setMes(1);
                this->incAno();
            }
        }
    };

    void operator --(int){
        if(this->getDia()>1){
            this->decDia();
        }else {
            if(this->getMes()>1){
                this->setDia(this->diames(this->getMes()-1));
                this->decMes();
            }else{
                this->setDia(31);
                this->setMes(12);
                this->decAno();
            }
        }
    };
};



int main(){
    int n, d, m, a, p;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> d >> m >> a;
        Data dt(d,m,a);
        
        cin >> p;
        char *s;
        int c=0;
        s = new char[p];
        cin >> s;
        for(int j=0;j<p;j++){
            if(s[j]=='>')dt ++;
            if(s[j]=='<')dt --;
        }
        dt.mostra();
    }

    return 0;
}


