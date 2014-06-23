#include <bits/stdc++.h>
using namespace std ;
int dp[110];
int main() {
    dp[1] = 1 ;
    for( int x = 2 ; x <= 100 ; x++ ) dp[x] = x * x + dp[x-1] ;
    int n ;
    while( scanf("%d",&n) && n ) printf("%d\n",dp[n]);
}
