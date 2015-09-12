import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

class Main{
	public static void main (String[] args){
		Scanner ob = new Scanner(System.in);
		int cs = 1 ;
		while(ob.hasNextBigDecimal()){
			BigDecimal a = ob.nextBigDecimal();
			BigDecimal b = ob.nextBigDecimal();
			int res = a.compareTo(b);
			if( res == 1) System.out.println("Case " + cs + ": Bigger");
			else if( res == -1 ) System.out.println("Case " + cs + ": Smaller");
			else System.out.println("Case " + cs + ": Same");
			cs++;
		}
	}
}
