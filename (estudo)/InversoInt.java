import java.util.Scanner;
public class InversoInt{
    public static void main(String[] args){
        Pilha p = new Pilha(10);
        Scanner scan = new Scanner(System.in);

        int n = scan.nextInt();
        for(int i=0;i<n;i++)
            p.push(scan.nextInt());
            
        while(!p.vazia())
            System.out.print(p.pop() + (p.vazia()?"\n":" "));
        
    }
} 

class Pilha{
    public int tamanho, quantidade;
    public int[] itens;
    Pilha(){}
    Pilha(int size){
        this.itens = new int[size];
        this.tamanho = size;
        this.quantidade = -1;
    }
    
    public void push(int v){
        if(!this.cheia()){
            this.quantidade++;
            this.itens[this.quantidade] = v;
        }
    }
    
    public int pop(){
        if(!this.vazia()){
            this.quantidade--;
            return this.itens[this.quantidade+1];
        }
        return -1;
    }

    public boolean cheia(){
        return this.quantidade == this.tamanho-1;
    }
    
    public boolean vazia(){
        return this.quantidade == -1;
    }
};
