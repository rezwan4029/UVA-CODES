#include <bits/stdc++.h>

using namespace std;

const int MX = 300 ;

const int INF = 1e8 ;

int N , freq[MX] , S[MX];

int SUM( int i , int j ){
    if( i > j ) return 0 ;
    return S[j] - S[i-1];
}
int dp[MX][MX];

int solve( int i , int j ){
    if( j < i ) return 0 ;
    if( i == j ) return 0;
    int &ret = dp[i][j];
    if( ret != -1 ) return ret;
    ret = INF ;
    for( int x = i ; x <= j ; x++ ){
        ret = min( ret , solve(i,x-1) + solve(x+1,j) + SUM(i,x-1) + SUM(x+1,j)  );
    }
    return ret ;
}
int main(){
    while( scanf("%d",&N) == 1 ) {
        memset(S,0,sizeof S);
        for( int i = 1 ; i <= N ; i++ ) scanf("%d",freq+i) ;
        for( int i = 1 ; i <= N ; i++ ) S[i] += S[i-1] + freq[i];
        memset(dp,-1,sizeof dp);
        printf("%d\n",solve(1,N));
    }
}
