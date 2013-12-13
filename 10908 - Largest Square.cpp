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

const int MX = 107 ;
const int INF = 1e8 + 7;
char g[MX][MX];
int m , n , Q ;
int Ok(int x ,int y , int l ){
 if( x + l >= n ) return 0 ;
 if( y + l >= m ) return 0 ;
 if( x - l <  0 ) return 0 ;
 if( y - l <  0 ) return 0 ;
 char curr = g[x][y];
 for( int i = x - l ; i <= x + l ; i++ )
    if( g[i][y-l] != curr || g[i][y+l] != curr ) return 0 ;
 for( int i = y - l ; i <= y + l ; i++ )
    if( g[x+l][i] != curr || g[x-l][i] != curr )return 0 ;
 return 1 ;
}
int main(){
    #ifdef LOCAL
       freopen ("in.txt", "r", stdin);
       //freopen ("out.txt","w",stdout);
    #endif
    int test = II ;
    For(cs,test){
        n = II , m = II , Q = II ;
        printf("%d %d %d\n",n,m,Q);
        rep(i,n) scanf( "%s",g[i]);
        while(Q--){
            int x = II , y = II  ;
            int Ans = 1 ;
            for( int len = 1 ; ; len++ ){
                     if ( Ok(x,y,len) ) Ans = max( Ans , 2*len+1 );
                     else break ;
            }
            printf("%d\n",Ans);
        }
    }
}
