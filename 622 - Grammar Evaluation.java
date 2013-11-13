/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


/**
 *
 * @author MARUF
 */
import java.util.*;

public class Main{

  static boolean isDelim(char c) {
    return c == ' ';
  }

  static boolean isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
  }

  static int priority(char op) {
    if( op == '+' || op == '-' ) return 1 ;
    if( op == '*' || op == '/' || op == '%' ) return 2 ;
    return -1;
  }

  static void processOperator(LinkedList<Integer> st, char op) {
    int r = st.removeLast();
    int l = st.removeLast();
    if ( op == '+' )     { st.add(l+r); }
    else if ( op == '-' ){ st.add(l-r); }
    else if ( op == '*' ){ st.add(l*r); }
    else if ( op == '/' ){ st.add(l/r); }
    else if ( op == '%' ){ st.add(l%r); }
  }

  public static int eval(String s) {
    LinkedList<Integer> st = new LinkedList<Integer>();
    LinkedList<Character> op = new LinkedList<Character>();
    for (int i = 0; i < s.length(); i++) {
      char c = s.charAt(i);
      if (isDelim(c))
        continue;
      if (c == '(')
        op.add('(');
      else if (c == ')') {
        while (op.getLast() != '(')
          processOperator(st, op.removeLast());
        op.removeLast();
      } else if (isOperator(c)) {
        while (!op.isEmpty() && priority(op.getLast()) >= priority(c))
          processOperator(st, op.removeLast());
        op.add(c);
      } else {
        String operand = "";
        while (i < s.length() && Character.isDigit(s.charAt(i)))
          operand += s.charAt(i++);
        --i;
        st.add(Integer.parseInt(operand));
      }
    }
    while (!op.isEmpty())
      processOperator(st, op.removeLast());
    return st.get(0);
  }
  public static boolean isdigit(char x){
      if( x >= '0' && x <= '9' ) return true ;
      return false ;
  }
  public static boolean isalpha(char x ){
      if( x >= 'a' && x <= 'z' ) return true ;
      if( x >= 'A' && x <= 'Z' ) return true ;
      return false ;
  }
  public static boolean isValid(String Str){
      int bracket = 0 ;
      int len = Str.length();
      for( int i = 0 ; i < len ; i++ ){
          if( isdigit(Str.charAt(i)) ) continue;
          if( Str.charAt(i) == '(' ) bracket++;
          else if( Str.charAt(i) == ')' ) bracket--;
          if( bracket < 0 ) return false;
          if( isalpha(Str.charAt(i)))return false;
          else if( (Str.charAt(i) == '(' ) && ( i != 0 && isdigit(Str.charAt(i-1)) ) ) return false ;
          else if( (Str.charAt(i) == ')' ) && ( isOperator(Str.charAt(i-1)) || Str.charAt(i) == '(' ) ) return false ;
          else if( i == 0 && Str.charAt(i) != '(' )return false;
          else if( i != 0 && isOperator(Str.charAt(i)) && ( isOperator(Str.charAt(i-1))|| Str.charAt(i-1) == '(' ) )return false;
      }
      return (bracket == 0 );
  }
  public static void main(String[] args) throws Exception {
      Scanner ob = new Scanner ( System.in );
      int test = ob.nextInt();
      while(test-->0){
          String exp = ob.next();
          if( isValid(exp) )
                 System.out.println( eval(exp) );
          else 
                System.out.println( "ERROR" );
      }
  }
}
