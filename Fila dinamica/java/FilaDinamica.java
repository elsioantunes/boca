import java.util.Scanner;

class Celula{
    private
        int n;
        Celula prox;
    
    public
        Celula(){};
        Celula getProx(){return this.prox;};
        void setProx(Celula obj){this.prox = obj;}
        int getN(){return this.n;};
        void setN(int m){this.n=m;}
};

public class FilaDinamica{
    private
        Celula ini, fim;

    public
        FilaDinamica(){
            this.setIni(new Celula());
            this.getIni().setProx(null);
            this.setFim(this.getIni());
        };
        
        void setIni(Celula obj){this.ini = obj;}
        void setFim(Celula obj){this.fim = obj;}
        Celula getIni(){return this.ini;};
        Celula getFim(){return this.fim;};

        void inserir(int n){
            this.getFim().setProx(new Celula());
            this.setFim(this.getFim().getProx());
            this.getFim().setN(n);
            this.getFim().setProx(null);
        };
        
        int remover(){
            if(this.getIni().getProx()!=null){
                Celula aux = this.getIni();
                this.setIni(this.getIni().getProx());
                return this.getIni().getN();
            }
            return -1;
        };
        
        void mostra(){
            if(this.getIni().getProx()!=null){
                Celula aux = this.getIni();
                while(true){
                    this.setIni(this.getIni().getProx());
                    if(this.getIni()==null)break;
                    System.out.print((this.getIni()==aux.getProx()?"":" ") + this.getIni().getN());
                }
                this.setIni(aux);
                System.out.println();
            };
        };                   

        public static void main(String[] args){
            char c;
            int n;
            Scanner scan = new Scanner(System.in);
            FilaDinamica fila;
            fila = new FilaDinamica();
            while(scan.hasNext()){
                c = scan.next().charAt(0);
                if(c=='E') {
                    n = scan.nextInt();
                    fila.inserir(n);
                }
                if(c=='D') {
                    n = fila.remover();
                    if(n!=-1)
                        System.out.println("<" + n + ">");
                }
                if(c=='M') fila.mostra();
            };
        }
};

