#include <bits/stdc++.h>
using namespace std ;
const int M = 1000000 ;
const int MX = 1000007 ;
int dp[MX];
int main() {
    dp[0] = 1 ;
    for( int i = 1 ; i <= MX - 7 ; i++ ) {
         int x = i - sqrt(i) ;
         int y = log(i);
         int z = i * sin(i) * sin(i) ;
         dp[i] = ( dp[x] + dp[y] + dp[z] ) % M ;
    }
    int n ;
    while( scanf("%d",&n) ){
        if( n == -1 ) break ;
        printf("%d\n",dp[n]);
    }
}
