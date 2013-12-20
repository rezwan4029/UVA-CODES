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

const int MX = 507 ;
const int INF = 1e8 + 7;

Long dp[MX][27];
bool Vis[MX][27];
int n , val ;
Long solve(int i , int j){
    if( i == n && j == 1 ) return val ;
    Long &ret = dp[i][j];
    if( Vis[i][j] ) return ret ;
    Vis[i][j] = true ;
    ret = 0 ;
    if( i < j )
    {
        for( int k = i ; k < j ; k++ )
            ret = max( ret , solve(i,k)+solve(k+1,j) );
    }
    else
    {
        Long r1 = 0 , r2 = 0 ;
        if( i < n )
        {
            for( int k = i+1 ; k <= n ; k++ )
                r1 = max( r1 , solve(k,1)+solve(k,j) );
        }
        if( j > 0 )
        {
            for( int k = 1 ; k < j ; k++ )
                 r2 = max( r2 , solve(i,k)+solve(n,k) );
        }
        ret = r1 + r2 ;
    }
    return ret ;
}

int main(){
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    while( scanf("%d %d",&n,&val) != EOF )
    {
        ms(Vis,false);
        printf("%lld\n",solve(1,n));
    }
}
