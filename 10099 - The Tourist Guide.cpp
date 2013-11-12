/*
    Rezwan_4029
    AUST , CSE-25
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL  ({ll  a; scanf("%lld", &a); a;})
#define EPS 1e-10
#define pi 3.1415926535897932384626433832795
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef vector<ll>vl;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

const int MX = 102 ;

int N , M ;
int St , En , Passengers ;
bool Vis[MX];
int d[MX][MX];

void Reset(){
    memset(d,0,sizeof d);
}

void Warshall(){
    For(k,N)For(i,N)For(j,N){
            if( i == j || k == i || j == k ) continue ;
            d[i][j] = max( d[i][j] , min(d[i][k] , d[k][j]) ) ;
    }
}

int main()
{
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    int cs = 1 ;
    while( scanf("%d %d",&N,&M) ){
        if( N == 0 && M == 0 ) break ;
        Reset();
        rep(i,M){
            int u = II , v = II , w = II ;
            d[u][v] = d[v][u] = w ;
        }
        St = II , En = II , Passengers = II ;
        Warshall();
        int ans =  ceil( double( Passengers) / double( d[St][En] - 1 ) )  ;
        printf("Scenario #%d\nMinimum Number of Trips = %d\n\n",cs++,ans);
    }
}
