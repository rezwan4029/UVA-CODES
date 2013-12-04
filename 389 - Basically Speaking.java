import java.math.*;
import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner ob = new Scanner(System.in);
        StringBuilder ret = new StringBuilder();
        while(ob.hasNext()){
          String s = ob.next();
          int b1 = ob.nextInt();
          int b2 = ob.nextInt();
          BigInteger n = new BigInteger(s,b1);
          s = n.toString(b2);
          int len = s.length();
          if( len > 7 ) ret.append("  ERROR" );
          else {
              for(int i = len ; i < 7 ; i++ ) ret.append(" ");
              ret.append(s.toUpperCase());
          }
          ret.append("\n");
        }
        System.out.print(ret.toString());
    }
}
