import java.math.BigInteger;
import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner ob = new Scanner( System.in );
		BigInteger F[] = new BigInteger[ 10007 ];
		F[3] = BigInteger.valueOf(4);
		F[4] = BigInteger.valueOf(7);
		for( int i = 5 ; i <= 10005 ; i++ ){
			F[i] = F[i-1].add( F[i-2] );
		}
		int n ;
		while( ob.hasNext() ){
			n = ob.nextInt();
			System.out.println( F[n] );
		}
	}
}
