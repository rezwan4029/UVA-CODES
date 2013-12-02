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

#define forab(i, a, b)        for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)                forab (i, 0, (n) - 1)
#define For(i, n)                forab (i, 1, n)
#define rofba(i, a, b)        for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)                rofba (i, 0, (n) - 1)
#define rof(i, n)                rofba (i, 1, n)
#define forstl(i, s)        for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

#define SZ 4007

int N , M , d[SZ] , Cost[SZ];
const int INF = 1e8 + 7;

struct Edge {
    int u, v, w;
    Edge(){}
    Edge(int _u , int _v, int _w) : u(_u) , v(_v), w(_w) {}
};

Edge edges[SZ];

void Init(int s) {
    rep(i,N+1){
        d[i] = INF;
    }
    d[s] = 0;
}


bool Bellman(int s)
{
    Init(s);
    bool used  ;
    For(k,N-1)
    {
        used = true ;
        rep(i,M)
        {
            if (d[ edges[i].v ] > d[ edges[i].u ] + edges[i].w && d[ edges[i].u ] != INF )
            {
                d[ edges[i].v ] =  d[ edges[i].u ] + edges[i].w  ;
                used = false ;
            }
        }
        if( used ) break ;
    }
    rep(i,M) if (d[edges[i].v] > d[edges[i].u] + edges[i].w && d[edges[i].u] != INF ) d[ edges[i].v ] = -INF ;
}

void Input(){
    For(i,N) Cost[i] = II ;
    M = II ;
    rep(i,M){
        int u = II , v  = II ;
        int w = ( Cost[v] - Cost[u] ) * ( Cost[v] - Cost[u] ) * ( Cost[v] - Cost[u] ) ;
        edges[i] =  Edge(u, v, w) ;
    }
}


int main(){
    #ifdef LOCAL
       freopen ("in.txt", "r", stdin);
    #endif
    int cs = 1 ;
    while( scanf("%d",&N) == 1 ){
        Input();
        printf("Set #%d\n",cs++);
        Bellman(1);
        int Q = II ;
        while(Q--){
            int x = II ;
            if( d[x] < 3 || d[x] == INF ) puts("?");
            else printf("%d\n",d[x]);
        }
    }
}
