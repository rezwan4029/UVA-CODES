
import java.math.*;
import java.util.*;



public class Main {

 static BigInteger get(long n){return BigInteger.valueOf(n);}
    static BigInteger mul(BigInteger x , BigInteger y){ return x.multiply(y);}
    static BigInteger sub(BigInteger x , BigInteger y){ return x.subtract(y);}
    static BigInteger add(BigInteger x , BigInteger y){ return x.add(y);}
    static BigInteger div(BigInteger x , BigInteger y){ return x.divide(y);}
    static BigInteger mod(BigInteger x , BigInteger y){ return x.mod(y);}
    

    public static void main(String args[])
    {
        Scanner ob = new Scanner(System.in);
        int test = ob.nextInt();
        while(test-->0){
            BigInteger a , b ; String c ;
            a = ob.nextBigInteger();
            c = ob.next();
            b = ob.nextBigInteger();
            BigInteger g = a.gcd(b);
            System.out.println( div(a,g) + " / " + div(b,g) );
        }
    }
}
