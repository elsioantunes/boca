import java.util.Scanner;

class Celula{
    public
    int n;
    Celula prox;
};

public class PilhaDinamica{
    private
        Celula ini, fim, aux;

    public
        PilhaDinamica(){
            ini = new Celula();
            ini.prox = null;
            fim = ini;
        };
        
        void inserir(int n){
            aux = ini.prox;
            ini.prox = new Celula();
            ini.prox.n = n;
            ini.prox.prox = aux;
        };
        
        int remover(){
            if(ini.prox!=null){
                aux = ini.prox.prox;
                int r = ini.prox.n;
                ini.prox = aux;
                return r;
            }
            return -1;
        };
        
        void mostra(){
            if(ini.prox!=null){
                aux = ini;
                while(true){
                    ini = ini.prox;
                    if(ini==null)break;
                    System.out.print((ini==aux.prox?"":" ") + ini.n);
                }
                ini = aux;
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

