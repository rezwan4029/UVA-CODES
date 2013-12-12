/*
    AUST_royal.flush
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL ({Long a; scanf("%lld", &a); a;})
#define DD ({double a; scanf("%lf", &a); a;})
#define EPS 1e-10
#define pi 3.1415926535897932384626433832795
using namespace std;

typedef long long Long;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef set<int> si;
typedef vector<Long>vl;
typedef pair<int,int>pii;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

const int MX = 307 ;
const int INF = 1e8 + 7;

int x[MX] , y[MX] , dp[MX][MX];

void Reset(){
    rep(i,MX) rep(j,MX) dp[i][j] = INF ;
}

int main(){
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    int test = II ;
    For(cs,test){
        int N = II , Sum = II ;
        rep(i,N) x[i] = II , y[i] = II ;
        Reset();
        dp[0][0] = 0 ;
        for( int i = 0 ; i < N ; i++ ){
            for( int j = x[i] ; j <= Sum; j++ ){
                for( int k = y[i] ; k <= Sum ; k++ ){
                        dp[j][k] = min( dp[j][k] , dp[ j - x[i] ][ k - y[i] ] + 1  );
                }
            }
        }
        int Ans = INF ;
        forab(i,0,Sum) forab(j,0,Sum) if( i * i + j * j == Sum * Sum ) Ans = min( Ans , dp[i][j] );
        if( Ans == INF ) puts("not possible");
        else printf("%d\n",Ans);
    }
}
