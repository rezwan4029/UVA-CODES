import java.math.*;
import java.util.*;

public class Main {
    static BigInteger[][] dp = new BigInteger[52][4002];
    static boolean[][] Vis = new boolean[52][4002];
    static int n , s , k ;
    static BigInteger solve(int turn, int sum) {
        if (turn == k) return sum == s ? BigInteger.ONE : BigInteger.ZERO;
        if (Vis[turn][sum]) return dp[turn][sum];
        Vis[turn][sum] = true;
        BigInteger ret = BigInteger.ZERO;
        for(int i = 1 ; i <= n ; i++ ) if(sum + i <= s) ret = ret.add( solve(turn + 1, sum + i) );
        return dp[turn][sum] = ret ;
    }

    public static void main(String args[]) {
        Scanner ob = new Scanner(System.in);
        while( ob.hasNextInt()){
            n = ob.nextInt();
            k = ob.nextInt();
            s = ob.nextInt();
            for(int i = 0 ; i <= k ; i++ )for(int j = 0 ; j <= s ; j++ )Vis[i][j] = false ;
            BigInteger a = BigInteger.ZERO ;
            if( !(k > s || n * k < s) ) a = solve(0,0);
            BigInteger b = BigInteger.valueOf(n).pow(k);
            System.out.println(a+"/"+b);
        }
    }
}
