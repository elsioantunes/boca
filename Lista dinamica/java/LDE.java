import java.util.Scanner;

// compare com a versão anterior (sem setters e getters)
// eu entendi que eles são necessários... mas são feios!

class Celula{
    private
        int n;
        Celula prox;

    public
        Celula(){this.setProx(null);};
        void setProx(Celula obj){this.prox = obj;};
        void setN(int v){this.n = v;};

        Celula getProx(){return this.prox;};
           int getN(){return this.n;};
};

public class LDE{
    private
        Celula ini;

    public
        LDE(){
            this.ini = new Celula();
        };

        Celula getIni(){return this.ini;}
        void setIni(Celula obj){this.ini = obj;}

        void inserir(int n){
            Celula aux, bux;
            aux = this.getIni();
            while(aux.getProx()!=null){
                if(aux.getProx().getN()>n)break;
                aux = aux.getProx();
            }
            if(aux.getN()!=n){
                bux = aux.getProx();
                aux.setProx(new Celula());
                aux.getProx().setProx(bux);
                aux.getProx().setN(n);
            }
        };

        void remover(int n){
            if(this.ini.getProx()!=null){
                Celula aux, bux;
                aux = this.getIni();
                while(aux.getProx()!=null){
                    if(aux.getProx().getN()==n){
                        bux = aux.getProx().getProx();
                        aux.setProx(bux);
                        break;
                    };
                    aux = aux.getProx();
                };
            };
        };

        boolean buscar(int n){
            if(this.ini.getProx()!=null){
                Celula aux;
                aux = this.getIni();
                while(aux.getProx()!=null){
                    aux = aux.getProx();
                    if(aux.getN()==n)return true;
                };
            };
            return false;
        };

        void mostra(){
            if(this.ini.getProx()!=null){
                Celula aux;
                aux = this.getIni();
                while(true){
                    aux = aux.getProx();
                    if(aux==null)break;
                    System.out.print((ini.getProx()==aux?"":" ") + aux.getN());
                };
                System.out.println();
            };
        };

        public static void main(String[] args){
            char c;
            int n;
            Scanner scan = new Scanner(System.in);
            LDE lista;
            lista = new LDE();
            while(scan.hasNext()){
                c = scan.next().charAt(0);
                if(c=='I') {
                    n = scan.nextInt();
                    lista.inserir(n);
                };
                if(c=='R') {
                    n = scan.nextInt();
                    lista.remover(n);
                };
                if(c=='B') {
                    n = scan.nextInt();
                    System.out.println(lista.buscar(n)?"SIM":"NAO");
                };
                if(c=='L') lista.mostra();
            };
        };
};

