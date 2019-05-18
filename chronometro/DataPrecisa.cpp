#include <iostream>

class Data
{
    private:
            int dia, mes, ano;
    public:
            Data();
            Data(int, int, int);
            void setDia(int);
            void setMes(int);
            void setAno(int);
            int getDia();
            int getMes();
            int getAno();
            bool valida();
            bool bissexto();
            static int ultimoDiaDoMes(Data);
            void incrementa();
            void decrementa();
};

class Relogio
{
    private:
            int hora, minuto, segundo;
    public:
            Relogio();
            Relogio(int, int, int);
            void setHora(int);
            void setMinuto(int);
            void setSegundo(int);
            int getHora();
            int getMinuto();
            int getSegundo();
            void incrementa();
            void decrementa();
};

class DataPrecisa : public Data, public Relogio
{
    private:
            bool regressivo;
    public:
            DataPrecisa();
            DataPrecisa(int, int, int, int, int, int);
            DataPrecisa(Data);
            DataPrecisa(Data, Relogio);
            void setRegressivo(bool);
            bool isRegressivo();
            DataPrecisa operator ++(int);
};

DataPrecisa::DataPrecisa()
{   }

DataPrecisa::DataPrecisa(int h , int m, int s, int d, int me, int a)
{
    this->setHora(h);
    this->setMinuto(m);
    this->setSegundo(s);
    this->setDia(d);
    this->setMes(me);
    this->setAno(a);
    this->setRegressivo(false);
}

DataPrecisa::DataPrecisa(Data dt) : Data(dt.getDia(), dt.getMes(), dt.getAno())
{
    this->setHora(0);
    this->setMinuto(0);
    this->setSegundo(0);
    this->setRegressivo(false);
}

DataPrecisa::DataPrecisa(Data dt, Relogio r) : Data(dt.getDia(), dt.getMes(), dt.getAno()), Relogio(r.getHora(), r.getMinuto(), r.getSegundo())
{
    this->setRegressivo(false);
}

void DataPrecisa::setRegressivo(bool v)
{
    this->regressivo = v;
}

bool DataPrecisa::isRegressivo()
{
    return this->regressivo;
}

DataPrecisa DataPrecisa::operator ++(int)
{
    DataPrecisa atual(this->getHora(), this->getMinuto(), this->getSegundo(), this->getDia(), this->getMes(), this->getAno());
    this->Relogio::incrementa();
    if(this->getHora() > 23)
    {
        this->Data::incrementa();
        this->setHora(0);
    }
    return atual;
}

Data::Data()
{   }

Data::Data(int d, int m, int a)
{
    this->setDia(d);
    this->setMes(m);
    this->setAno(a);
}

void Data::setDia(int d)
{
    this->dia = d;
}

void Data::setMes(int m)
{
    this->mes = m;
}

void Data::setAno(int a)
{
    this->ano = a;
}

int Data::getDia()
{
    return this->dia;
}

int Data::getMes()
{
    return this->mes;
}

int Data::getAno()
{
    return this->ano;
}

bool Data::valida()
{
    return( (   (this->getMes() == 1 || this->getMes() == 3 || this->getMes() == 5 || this->getMes() == 7 || this->getMes() == 8 || this->getMes() == 10 || this->getMes() == 12) && this->getDia()>0 && this->getDia()<32 ) ||
            (   (this->getMes() == 4 || this->getMes() == 6 || this->getMes() == 9 || this->getMes() == 11) && this->getDia()>0 && this->getDia()<31 ) ||
            (   this->getMes() == 2 && this->getDia()>0 && this->getDia()<29) || (this->getMes() == 2 && this->bissexto() && this->getDia()>0 && this->getDia()<30));
}

bool Data::bissexto()
{
    return this->getAno()%400 == 0 || (this->getAno()%100 != 0 && this->getAno()%4 == 0);
}

int Data::ultimoDiaDoMes(Data dt)
{
    switch(dt.getMes())
    {
        case 1: return 31;
        case 2: return dt.bissexto()?29:28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
    }
}

void Data::incrementa()
{
    this->setDia(this->getDia()+1);
    if(!this->valida())
    {
        this->setDia(1);
        this->setMes(this->getMes()+1);
        if(!this->valida())
        {
            this->setMes(1);
            this->setAno(this->getAno()+1);
        }
    }
}

void Data::decrementa()
{
    this->setDia(this->getDia()-1);
    if(!this->valida())
    {
        this->setMes(this->getMes()-1);
        this->setDia(Data::ultimoDiaDoMes(*this));
        if(!this->valida())
        {
            this->setAno(this->getAno()-1);
            this->setMes(12);
            this->setDia(31);
        }
    }
}

Relogio::Relogio()
{   }

Relogio::Relogio(int h, int m, int s)
{
    this->setHora(h);
    this->setMinuto(m);
    this->setSegundo(s);
}

void Relogio::setHora(int h)
{
    this->hora = h;
}

void Relogio::setMinuto(int m)
{
    this->minuto = m;
}

void Relogio::setSegundo(int s)
{
    this->segundo = s;
}

int Relogio::getHora()
{
    return this->hora;
}

int Relogio::getMinuto()
{
    return this->minuto;
}

int Relogio::getSegundo()
{
    return this->segundo;
}

void Relogio::incrementa()
{
    this->setSegundo(this->getSegundo()+1);
    if(this->getSegundo()>59)
    {
        this->setMinuto(this->getMinuto()+1);
        this->setSegundo(0);
        if(this->getMinuto()>59)
        {
            this->setHora(this->getHora()+1);
            this->setMinuto(0);
        }
    }
}

void Relogio::decrementa()
{
    this->setSegundo(this->getSegundo()-1);
    if(this->getSegundo() < 0)
    {
        this->setMinuto(this->getMinuto()-1);
        this->setSegundo(59);
        if(this->getMinuto() < 0)
        {
            this->setHora(this->getHora()-1);
            this->setMinuto(59);
        }
    }
}

int main()
{
    DataPrecisa dt(23,55,0,28,2,2015);
    int i;
    
    for(i=0; i<1000; i++)
    {
        std::cout << dt.getDia() << "/" << dt.getMes() << "/" << dt.getAno() << " " << dt.getHora() << ":" << dt.getMinuto() << ":" << dt.getSegundo() << std::endl;
        dt++;
    }
    return 0;
}