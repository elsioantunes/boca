import java.util.Scanner;

class troca{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        meuint a = new meuint(scan.nextInt());
        meuint b = new meuint(scan.nextInt());
        System.out.println(a.valor + " : " + b.valor);
        trocar(a, b);
        System.out.println(a.valor + " : " + b.valor);
    }
    public static void trocar(meuint a, meuint b){
        int tmp = a.valor;
        a.valor = b.valor;
        b.valor = tmp;
    };
}

class meuint{
    public int valor;
    public meuint(int a){
        valor = a;
    }
}