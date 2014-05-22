#include <bits/stdc++.h>
using namespace std ;
typedef long long Long;

Long dp[30][30][400];
int A[30] , N , L , S ;
Long solve(int pos , int taken , int s ){
    if( pos == N ){
        return ( s == S  and taken == L );
    }
    Long &ret = dp[pos][taken][s];
    if(ret != -1 ) return ret ;
    ret = 0 ;
    ret += solve(pos+1,taken+1,s+A[pos]);
    ret += solve(pos+1,taken,s);
    return ret ;
}
int main() {
    int cs = 1 ;
    N = 26 ;
    for( int i = 1 ; i <= N ; i++) A[i-1] = i ;
    while( scanf("%d %d",&L,&S) ){
        if( L == 0 and S == 0 ) return 0 ;
        memset(dp,-1,sizeof dp);
        Long Ans = 0;
        if ( L <= 26 and S <= 380 ) Ans = solve(0,0,0);
        printf("Case %d: %lld\n",cs++,Ans);
    }
}
