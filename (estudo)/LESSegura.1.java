import java.util.Scanner;

class MeuErro extends Exception{
    MeuErro(String str){
        super(str);
    }
}

class LESSegura{
    private int[] itens;
    private int tamanho, quantidade;
    LESSegura(){};
    LESSegura(int size){
        this.setTamanho(size);
        this.setQuantidade(0);
        this.itens = new int[size];
    }

    public void inserir(int v) throws MeuErro{
        if(this.cheia()) throw new MeuErro("Runtime Error: Lista cheia.");
            int i = 0;
            while(i<this.getQuantidade() && v>this.getItens(i))
                i++;
            if(v==this.getItens(i)) throw new MeuErro("Logic Error: Chave existente na lista.");
            for(int j=this.getQuantidade();j>i;j--)
                this.setItens(j, this.getItens(j-1));
            this.setItens(i, v);
            this.setQuantidade(this.getQuantidade()+1);
    }

    public void remover(int v) throws MeuErro{
        if(this.vazia()) throw new MeuErro("Runtime Error: Lista Vazia.");
            int i=0;
            while(i<this.getQuantidade()&&v!=this.getItens(i))
                i++;
            if(i==this.getQuantidade()) throw new MeuErro("Logic Error: Chave inexistente na lista.");
            for(int j=i;j<this.getQuantidade()-1;j++)
                this.setItens(j, getItens(j+1));
            this.setQuantidade(this.getQuantidade()-1);
    }

    public void buscar(int v) throws MeuErro{
        if(this.vazia())throw new MeuErro("Runtime Error: Lista Vazia.");
            for(int i=0;i<this.getQuantidade();i++)
                if(v==this.getItens(i)) throw new MeuErro("SIM");
            throw new MeuErro("NAO");
    }

    public void exibir(int i) throws MeuErro{
        // if(this->vazia())throw MeuErro("Runtime Error: Lista Vazia."); // ????????????? erro do professor!
        if(i<0||i>this.getQuantidade()-1) throw new MeuErro("Runtime Error: Posicao da lista inexistente.");
        System.out.println("<" + this.getItens(i) + ">");
    }
    public void exibir() throws MeuErro{
        if(this.vazia()) throw new MeuErro("Runtime Error: Lista Vazia.");
        for(int i=0;i<this.getQuantidade();i++)
            System.out.print((i!=0?" ":"") + this.getItens(i));
        System.out.println();
    }

    public void setTamanho(int v){this.tamanho = v;};
    public void setQuantidade(int v){this.quantidade = v;};
    public void setItens(int i, int v){this.itens[i]=v;};
    public int getTamanho(){return this.tamanho;};
    public int getQuantidade(){return this.quantidade;};
    public int getItens(int i){return this.itens[i];}
    public boolean cheia(){return this.getQuantidade()==this.getTamanho();};
    public boolean vazia(){return this.getQuantidade()==0;};

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        LESSegura lista = new LESSegura(n);
    
        while(scan.hasNext()){
            try{
                char c = scan.next().charAt(0);
                if(c=='I') {int m = scan.nextInt(); lista.inserir(m);}
                if(c=='E') {int m = scan.nextInt(); lista.remover(m);}
                if(c=='B') {int m = scan.nextInt(); lista.buscar(m);}
                if(c=='C') {int m = scan.nextInt(); lista.exibir(m);}
                if(c=='M') lista.exibir();

            }catch(MeuErro e){
                System.out.println(e.getMessage());
            }
        }
    }
}