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

    bool valida_old(){
        int diames[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
        if(this->getMes() > 12) return false;
        if(this->getMes() < 1)  return false;
        if(this->getAno() < 0)  return false;
        if(this->getDia() < 1)  return false;
        if(this->getDia() > diames[this->getMes()]) return false;
        if(this->getMes() == 2 && !this->bissexto(this->getAno()) && this->getDia()==29) return false;
        return true;
    };

    bool valida(int d, int m, int a){
        int diames[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
        if(m > 12 || m < 1) return false;
        if(a < 0)  return false;
        if(d < 1 || d > diames[m]) return false;
        if(m == 2 && !this->bissexto(a) && d==29) return false;
        return true;
    };


    bool bissexto(int a){
        return ((a%4)==0 && (a%100)!= 0) || (a%400)==0;    
    };
        
    void mostra(){
        cout << this->getDia() << "/" << this->getMes() << "/" << this->getAno() << endl;
    };
    
    void operator ++(int){
        if(this->valida(this->getDia()+1,this->getMes(),this->getAno())){
            this->setDia(this->getDia()+1);
        }
        else if(this->valida(1,this->getMes()+1,this->getAno())){
            this->setDia(1);
            this->setMes(this->getMes()+1);
        }
        else if(this->valida(1,1,this->getAno()+1)){
            this->setDia(1);
            this->setMes(1);
            this->setAno(this->getAno()+1);
        }
    }

    
    void operator --(int){
        int diames[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

        
        if(this->getDia()>1){
            this->setDia(this->getDia()-1);
        }else if(this->getMes()>1){
            this->setMes(this->getMes()-1);
            if(this->getMes()==2)
                if(this->bissexto(this->getAno()))
                    this->setDia(29);
                else
                    this->setDia(28);
            else
                this->setDia(diames[this->getMes()]);
        }else if(this->getMes()==1){
            this->setMes(12);
            this->setDia(31);
            this->setAno(this->getAno()-1);
        }
    }
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


