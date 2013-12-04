import java.math.*;
import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner ob = new Scanner(System.in);
        while(ob.hasNext()){
          String s1 = ob.next();
          String s2 = ob.next();  
          int minBase1 = 0 , minBase2 = 0 ;
          for(char c : s1.toCharArray() ) if( minBase1 < c ) minBase1 = c ;
          for(char c : s2.toCharArray() ) if( minBase2 < c ) minBase2 = c ;
          minBase1 = Character.digit( (char)minBase1 , 36 ) + 1;
          minBase2 = Character.digit( (char)minBase2 , 36 ) + 1;
          boolean Find = false ;
          int B1 = -1 , B2 = -1;
          BigInteger x,y;
          for( int i = minBase1 ; i <= 36 && !Find ; i++ ){
              for( int j = minBase2 ; j <= 36 && !Find ; j++ ){
                  try{
                      x = new BigInteger(s1,i);
                  }catch(Exception err){ 
                      continue;
                  }
                  try{
                      y = new BigInteger(s2,j);
                  }catch(Exception err){ 
                      continue;
                  }
                  if( x.equals(y) ){
                      Find = true ;
                      B1 = i ;
                      B2 = j ;
                      break;
                  }
              }
          }
          if( Find ) System.out.printf( "%s (base %d) = %s (base %d)\n",s1,B1,s2,B2  );
          else System.out.println( s1 + " is not equal to "+ s2 +" in any base 2..36" ) ;
        }
    }
}
