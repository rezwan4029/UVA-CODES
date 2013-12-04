import java.math.*;
import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner ob = new Scanner(System.in);
        while(ob.hasNext()){
            BigInteger x = ob.nextBigInteger();
            if( x.equals( BigInteger.ZERO ) ){
                System.out.println(1);
                continue;
            }
            BigInteger ans = ( x.multiply(x) ).subtract(x);
            ans = ans.add( BigInteger.valueOf(2) );
            System.out.println(ans);
        }
    }
}
