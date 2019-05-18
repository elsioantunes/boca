import java.util.Scanner;
public class PilhaInt{
    public static void main(String[] args){
        char c;
        Scanner scan = new Scanner(System.in);
        int size = scan.nextInt();
        Pilha pilha = new Pilha(size);
        while(scan.hasNext()){
            c = scan.next().charAt(0);
            if(c=='E') {int m = scan.nextInt(); pilha.push(m);}
            if(c=='D') pilha.pop();
            if(c=='T') pilha.show();
            if(c=='B') pilha.show(true);
            if(c=='X') pilha.show(false);
        }
    }
}

class MeuErro extends Exception{
    public MeuErro(String str){
        super(str);
    };
};

class Pilha{
    private int top, itens[], tamanho;
    Pilha(){};
    Pilha(int size){
        this.setTamanho(size);
        this.setTop(-1);
        this.itens = new int[size];
    };
    
    public void push(int v){
        if(!this.cheia()){
            this.setTop(this.getTop()+1);
            this.setItens(this.getTop(), v);
        };
    };
    
    public void pop(){
        if(!this.vazia()){
            this.setTop(this.getTop()-1);
        };
    };
    
    public void show(boolean t){
        if(!this.vazia()){
            for(int i=0;i<=this.getTop();i++)
                System.out.print((i!=0?" ":"") + this.getItens(t?i:this.getTop()-i));
            System.out.println();
        }
    };

    public void show(){
        System.out.println(this.getItens(this.getTop()));
    }

    public void setTamanho(int n){this.tamanho = n;};
    public void setTop(int n){this.top = n;};
    public void setItens(int i, int v){this.itens[i] = v;};

    public int getItens(int i){return this.itens[i];};
    public int getTamanho(){return this.tamanho;};
    public int getTop(){return this.top;};

    public boolean cheia(){return this.getTop()==this.getTamanho()-1;};
    public boolean vazia(){return this.getTop()==-1;};
}

