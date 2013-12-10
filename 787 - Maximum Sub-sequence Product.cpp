import java.math.*;
import java.util.*;

public class Main {

    public static void main(String args[]) {
        Scanner ob = new Scanner(System.in);
        BigInteger [] a = new BigInteger [107];
        while (ob.hasNext()) {
            int n = 0 ;
            while(true){
                int x = ob.nextInt();
                if( x == -999999)break;
                a[ n++ ] = BigInteger.valueOf(x);
            }
            BigInteger Ans = BigInteger.valueOf(-999999);
            for( int i = 0 ; i < n ; i++){
                BigInteger ret = a[i];
                Ans = Ans.max(ret);
                for( int j = i + 1 ; j < n ; j++ ){
                    ret = ret.multiply(a[j]);
                    Ans = Ans.max(ret);
                }
            }
            System.out.println(Ans);
            
        }
    }
    
}
