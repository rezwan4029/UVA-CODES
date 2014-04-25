#include <stdio.h>
#include <string.h>

const int MOD = 1000000009 ;
typedef long long Long ;
const int MX = 600 ;

int N , k , D[MX];
Long dp[MX][MX] , nCr[MX][MX];
int Vis[MX][MX] , cs ;

Long solve(int nth, int rem){
    if( nth == 0 ) return rem == 0 ;
    if( Vis[nth][rem] == cs ) return dp[nth][rem];
    Vis[nth][rem] = cs ;
    Long ret = 0 ;
    for( int i = 0 ; i <= k and i <= rem ; i++ ) {
        ret += ( nCr[rem][i] * solve(nth-1,rem-i) ) % MOD ;
        ret %= MOD;
    }
    return dp[nth][rem] = ret ;
}

int main() {

   nCr[0][0] = 1;
   for( int i = 1 ; i < MX ; i++ ) {
		nCr[i][0] = 1;
		for( int j = 1 ; j <= i ; j++) nCr[i][j] = ( nCr[i-1][j-1] + nCr[i-1][j] ) % MOD  ;
   }

   int T ;
   scanf("%d",&T);
   for( cs = 1 ; cs <= T ;cs++ ) {
        scanf("%d %d",&N,&k);
        for( int i = 0 ; i <= N ; i++ ) scanf("%d",&D[i]);
        Long Ans = 1 ;
        for( int i = 1 ; i <= N ; i++ ) Ans = ( Ans * solve( D[i-1] , D[i] ) ) % MOD ;
        printf("Case %d: %lld\n",cs,Ans);
   }
}
