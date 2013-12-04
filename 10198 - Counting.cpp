import java.math.*;
import java.util.*;

public class Main {

    static BigInteger[][] dp = new BigInteger[1007][5];
    static boolean[][] V = new boolean[1007][5];

    public static void main(String args[]) {
        Scanner ob = new Scanner(System.in);
        solve(1000, 0);
        while (ob.hasNext()) {
            int n = ob.nextInt();
            System.out.println(dp[n][0]);
        }
    }
    static int a[] = {1, 1, 2, 3};

    static BigInteger solve(int sum, int prev) {
        if (sum <= 0) {
            return (sum == 0) ? BigInteger.ONE : BigInteger.ZERO;
        }
        if (V[sum][prev]) {
            return dp[sum][prev];
        }
        V[sum][prev] = true;
        dp[sum][prev] = BigInteger.ZERO;
 
        for (int i = 0; i < 4; i++) {
            dp[sum][prev] = dp[sum][prev].add(solve(sum - a[i], i));
        }
        return dp[sum][prev];
    }
}
