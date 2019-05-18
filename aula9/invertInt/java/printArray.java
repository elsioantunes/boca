import java.util.Scanner;

public class printArray<T>{
    public Object[] itens;
    public int top;
    public int size;
    
    public printArray(){};
    public printArray(int n){
        top = -1;
        size = n;
        this.itens = new Object[n];
        itens = (T[])itens;
    }
    
    public void push(T n){
        if(top!=size-1){
            top++;
            itens[top] = n;
        }
    } 

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int n = 5;
        printArray pilha = new printArray(n);
        while(scan.hasNext()){
            String a = scan.next();
            if(a.equals("qw"))break;
            pilha.push(a);
        }
        for(int i=0;i<=pilha.top;i++)
            System.out.print((i==0?"":" ") + pilha.itens[pilha.top-i]);
        System.out.println();
    }
}


/*
printArray.java:12: error: <identifier> expected
        this.itens = new (T[])Object[n];
                        ^
printArray.java:12: error: '.class' expected
        this.itens = new (T[])Object[n];
                             ^
printArray.java:12: error: ';' expected
        this.itens = new (T[])Object[n];
                              ^
printArray.java:12: error: not a statement
        this.itens = new (T[])Object[n];
                                    ^
4 errors

*/