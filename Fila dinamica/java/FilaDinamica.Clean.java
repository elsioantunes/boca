import java.util.Scanner;

class Celula{
    public
    int n;
    Celula prox;
};

public class FilaDinamica{
    private
        Celula ini, fim, aux;

    public
        FilaDinamica(){
            ini = new Celula();
            ini.prox = null;
            fim = ini;
        };
        
        void inserir(int n){
            fim.prox = new Celula();
            fim = fim.prox;
            fim.n = n;
            fim.prox = null;
        };
        
        int remover(){
            if(ini.prox!=null){
                aux = ini;
                ini = ini.prox;
                return ini.n;
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

