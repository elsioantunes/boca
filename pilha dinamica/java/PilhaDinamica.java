import java.util.Scanner;

class Celula{
    private
        int n; Celula prox;

    public
        Celula(){};
        Celula getProx()           {return this.prox;};
           int getN()              {return this.n;};
          void setN(int n)         {this.n = n;};
          void setProx(Celula obj) {this.prox = obj;};
};

public class PilhaDinamica{
    private
        Celula top;

    public
        PilhaDinamica(){
            this.top = new Celula();
            this.top.setProx(null);
        };

        Celula getTop(){return this.top;};

        void inserir(int n){
            Celula aux = this.top.getProx();
            this.top.setProx(new Celula());
            this.top.getProx().setN(n);
            this.top.getProx().setProx(aux);
        };

        int remover(){
            if(top.getProx()!=null){
                Celula aux = this.top.getProx().getProx();
                int r = this.top.getProx().getN();
                this.top.setProx(aux);
                return r;
            }
            return -1;
        };

        void mostra(){
            if(this.top.getProx()!=null){
                Celula aux = this.getTop();
                while(true){
                    aux = aux.getProx();
                    if(aux == null)break;
                    System.out.print((aux==this.top.getProx()?"":" ") + aux.getN());
                }
                System.out.println();
            }
        };

        public static void main(String[] args){
            char c;
            int n;
            Scanner scan = new Scanner(System.in);
            PilhaDinamica pilha;
            pilha = new PilhaDinamica();
            while(scan.hasNext()){
                c = scan.next().charAt(0);
                if(c=='E') {
                    n = scan.nextInt();
                    pilha.inserir(n);
                }
                if(c=='D') {
                    n = pilha.remover();
                    if(n!=-1)
                        System.out.println("[" + n + "]");
                }
                if(c=='M') pilha.mostra();
            };
        }

};

