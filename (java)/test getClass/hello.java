import java.util.Scanner;
public class hello{
    public static void main(String[] args){
        int n;
        String str;
        Scanner scan = new Scanner(System.in);
        n = scan.nextInt();
        str = scan.next();
        System.out.println(str + " :: " +n);
    }
}