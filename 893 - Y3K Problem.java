import java.util.*;
import java.text.DateFormat;
import java.text.SimpleDateFormat;

public class Main {

public static void main(String args[]){
        Scanner ob = new Scanner(System.in); 
        int N , d , m , y ;
        while(true){
            N = ob.nextInt();
            d = ob.nextInt();
            m = ob.nextInt();
            y = ob.nextInt();
            if( N == 0 && d == 0 && m == 0 && y == 0 ) break;
            GregorianCalendar date = new GregorianCalendar( y , m - 1 ,d );
            date.add(Calendar.DATE,N);
            System.out.println( date.get(Calendar.DATE) + " " + (date.get(Calendar.MONTH)+1) + " " + date.get(Calendar.YEAR) );
        }
    }
}
