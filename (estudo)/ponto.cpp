#include <iostream>
using namespace std;

class Ponto{
    private:
            float x, y;
    public:
            Ponto();
            Ponto(float, float);
            void setX(float);
            void setY(float);
            float getX();
            float getY();
            Ponto operator+ (int);
            Ponto operator+ (Ponto);
            friend Ponto operator+ (int, Ponto);
};

Ponto::Ponto(){};
Ponto::Ponto(float x, float y){
    this->setX(x);
    this->setY(y);
};

void Ponto::setX(float v){
    this->x = v;
};
void Ponto::setY(float v){
    this->y = v;
};
float Ponto::getX(){
    return this->x;
};
float Ponto::getY(){
    return this->y;
};
Ponto Ponto::operator+ (int n){
    return Ponto(this->getX()+n,this->getY()+n);
};
Ponto Ponto::operator+ (Ponto p){
    return Ponto(this->getX()+p.getX(),this->getY()+p.getY());
};




Ponto operator+ (int n, Ponto p){
    return Ponto(p.getX()+n,p.getY()+n);
};


int main(){
    Ponto p(12.3,14.4), q(.3,.4), r;
    r = 2+p; 

    
    cout << r.getX() << "," << r.getY() << endl;
    return 0;
}


