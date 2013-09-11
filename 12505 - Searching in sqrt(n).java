import java.util.Scanner;
import java.math.BigInteger;
import java.math.BigDecimal;


public class Main
{
     public static BigDecimal sqrt(BigDecimal x, int scale)
    {
        // Check that x >= 0.
        if (x.signum() < 0) {
            throw new IllegalArgumentException("x < 0");
        }

        // n = x*(10^(2*scale))
        BigInteger n = x.movePointRight(scale << 1).toBigInteger();

        // The first approximation is the upper half of n.
        int bits = (n.bitLength() + 1) >> 1;
        BigInteger ix = n.shiftRight(bits);
        BigInteger ixPrev;

        // Loop until the approximations converge
        // (two successive approximations are equal after rounding).
        do {
            ixPrev = ix;

            // x = (x + n/x)/2
            ix = ix.add(n.divide(ix)).shiftRight(1);

            Thread.yield();
        } while (ix.compareTo(ixPrev) != 0);

        return new BigDecimal(ix, scale);
    }
    

    public static void main(String args[])
    {
        Scanner ob= new Scanner(System.in);
    
        
        int t=ob.nextInt();
       while(t-->0)
        {
    
            BigDecimal a=ob.nextBigDecimal();
            String s = ob.next();
            
            BigDecimal root=sqrt(a,115);
           // System.out.println(root);
            String x = root.toString();
            int tot = x.length();
            int len = x.indexOf('.');
           // System.out.println(len);
            String INT = (String) x.subSequence(len+1,tot);
            int pLen = INT.length();
           // System.out.println(INT);
             
            BigInteger INTB =new BigInteger(INT);
            BigInteger two = BigInteger.valueOf(2);
            String ret = "";
            int ans = 0;
            for ( int it = 1 ; it<= 110 ; it++){
                String NW = (INTB.multiply(two)).toString();
             //  System.out.println("iters- >   "+NW);
                int nLen = NW.length();
                if( nLen == pLen+1 ){
                    ret += '1';
                    String temp = (String) NW.subSequence(1,pLen+1);
                    INTB = new BigInteger(temp);
                  //  pLen = nLen;
                  //  System.out.println("temp- > "+temp);
                }
                else{
                    ret += '0';
                    INTB =  INTB.multiply(two);
                }
           //     System.out.println("bits - > "+ret);
                ans =  ret.indexOf(s) ;
                if(ans !=-1) break;
               
            }
            
           // System.out.println(ret);
            // System.out.println(ret);
            
           // String num = INTB.toString();
           // int L1 = num.length();
           // int L2 = s.length();
      
            //System.out.println(ret);
            System.out.println(ans);
            
            
            
        }
    }

} 
