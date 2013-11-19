import java.math.BigInteger;
import java.util.Scanner;
public class Main 
{    
    static BigInteger catalan[] = new BigInteger[302];
    static BigInteger fact[] = new BigInteger[302]; 
    public static void main(String[] args) 
    {
        catalan[0] = BigInteger.ONE;
        for(int i = 1 ; i <= 300 ; i++)
            catalan[i] = catalan[i-1].multiply( BigInteger.valueOf(2*(2*i -1))).divide(BigInteger.valueOf(i+1));
        
        fact[0] = fact[1] = BigInteger.ONE;
        for(int i = 2 ; i <= 300 ; i++ )
            fact[i] = BigInteger.valueOf(i).multiply(fact[i-1]);
        Scanner ob = new Scanner(System.in);
        while(true)
        {
            int n = ob.nextInt();
            if( n == 0)break;
            System.out.println(fact[n].multiply(catalan[n]));
        }
    }
}
