import java.util.Scanner;
class Celula{
    private int val;
    private Celula prox;
    Celula(){};
    Celula(int v){
        this.setProx(null);
        this.setVal(v);
    };
    public void setProx(Celula cell){this.prox = cell;}
    public void setVal(int v){this.val = v;};
    public Celula getProx(){return this.prox;};
    public int getVal(){return this.val;};
}
public class PilhaDinamica{
    private Celula top;
    private int quantidade;
    PilhaDinamica(){
        this.setTop(new Celula(0));
        this.setQuantidade(0);
    };
    
    public void push(int v){
        Celula aux = this.getTop().getProx();
        this.getTop().setProx(new Celula(v));
        this.getTop().getProx().setProx(aux);
        this.setQuantidade(getQuantidade()+1);
    }
    
    public int pop(){
        if(!this.vazia()){
            int r = this.getTop().getVal();
            this.setTop(this.getTop().getProx());
            return r;
        };
        return -1;
    };
    
    public void show(){
        Celula aux = this.getTop();
        while(aux.getProx()!=null){
            aux = aux.getProx();
            System.out.println(" " + aux.getVal());
        }
    }
    
    public void setTop(Celula cell){this.top = cell;}
    public void setQuantidade(int n){this.quantidade = n;};
    public Celula getTop(){return this.top;};
    public int getQuantidade(){return this.quantidade;};
    public boolean vazia(){return this.quantidade==0;};
    
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        PilhaDinamica pilha = new PilhaDinamica();
        while(scan.hasNext()){
            char c = scan.next().charAt(0);
            if(c=='E') pilha.push(scan.nextInt());
            if(c=='D') pilha.pop();
            if(c=='M') pilha.show();
        }
    }
}