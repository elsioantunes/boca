import java.util.Scanner;
public class hello{
    public static void main(String[] args){
        int n;
        //String str;
        //Scanner scan = new Scanner(System.in);
        //n = scan.nextInt();
        //str = scan.next();
        
        
        
        Obj obj1, obj2;
        
        obj1 = new Obj();
        
        obj1.a = 3;
        obj2 = obj1;
        obj1.a = 4;
        
        System.out.println(obj2.a);
    }
}

class Obj{
    public int a=9;
}