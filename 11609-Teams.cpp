import java.math.BigInteger;
import java.util.Scanner;

public class Main
{
   public static BigInteger conv(long  o)
   {  
    return BigInteger.valueOf(o);
   }
   public static void main(String args[])
   {  
      Scanner in = new Scanner(System.in);
      BigInteger num, n;
      int t,cs=1;
      BigInteger M = conv(1000000007);
      t = in.nextInt();
      while(t-->0)
      {  
         n = in.nextBigInteger();

         num = conv(2).modPow(n.subtract(conv(1)), M);

         n = n.mod(M);

         num = n.multiply(num);
         num = num.mod(M);
         System.out.println("Case #" + cs++ + ": " + num);
      }
   }
}
