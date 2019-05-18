import java.util.Scanner;

class Celula{
    private
    int n;
    Celula prox;
};

public class ListaDinamicaClean{
    private
        Celula ini, aux, bux;

    public
        ListaDinamicaClean(){
            ini = new Celula();
            ini.prox = null;
        };
        
        void inserir(int n){
            aux = ini;
            while(aux.prox!=null){
                if(aux.prox.n>n)break;
                aux = aux.prox;
            };
            if(aux.n!=n){
                bux = aux.prox;
                aux.prox = new Celula();
                aux.prox.prox = bux;
                aux.prox.n = n;
            }
        };
        
        void remover(int n){
            if(ini.prox!=null){
                aux = ini;
                while(aux.prox!=null){
                    if(aux.prox.n==n){
                        bux = aux.prox.prox;
                        aux.prox = bux;
                        break;
                    };
                    aux = aux.prox;
                };
            };
        };
        
        boolean buscar(int n){
            if(ini.prox!=null){
                aux = ini;
                while(aux.prox!=null){
                    aux = aux.prox;
                    if(aux.n==n)return true;
                };
            };
            return false;
        };
        
        void mostra(){
            if(ini.prox!=null){
                aux = ini;
                while(true){
                    ini = ini.prox;
                    if(ini==null)break;
                    System.out.print((ini==aux.prox?"":" ") + ini.n);
                };
                ini = aux;
                System.out.println();
            };
        };                   

        public static void main(String[] args){
            char c;
            int n;
            Scanner scan = new Scanner(System.in);
            ListaDinamicaClean lista;
            lista = new ListaDinamicaClean();
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

