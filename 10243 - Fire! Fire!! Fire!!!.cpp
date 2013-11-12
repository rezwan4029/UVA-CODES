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

const int MX  = 1007 ;
int N ;
vi edges[MX];
int dp[MX][2];
bool Vis[MX][2];
int solve(int u , bool isGuard , int par){
    int &ret = dp[u][isGuard];
    if( Vis[u][isGuard] )return ret ;
    Vis[u][isGuard] = true ;
    ret = 0 ;
    forstl(it,edges[u]){
        int v = *it ;
        if( v != par ){
            if( isGuard == false ) ret +=  solve(v,1,u) ;
            else ret += min( solve(v,1,u) , solve(v,0,u) );
        }
    } ret += isGuard ;
    return ret  ;
}
int main()
{
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    while( scanf("%d",&N) &&N ){
        For(u,N){
            int M = II ;
            rep(j,M){
                int v = II ;
                edges[u].pb(v);
            }
        }
        int Ans = 1 ;
        if( N != 1 ) Ans = min(  solve(1,1,-1) , solve(1,0,-1) );
        printf("%d\n",Ans);
        ms(Vis,false);
        For(i,N) edges[i].clear();
    }
}
