import java.math.BigInteger;
import java.util.Scanner;
public class Main {
     public static void main(String args[]){
        Scanner M = new Scanner(System.in);
        BigInteger ans = new BigInteger("0");
        while(true){
            String s1 = M.nextLine();
            String s2="0";
           if(s1.equals(s2))break;
           
            ans = ans.add( new BigInteger(s1) );
        }
    }
}
