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


#define SZ 2007

const int INF = 1e8 + 7 ;

int N , M , d[SZ] , pred[SZ] , inNegCycle[SZ];

struct Edge {
    int u, v, w;
    Edge(){}
    Edge(int _u , int _v, int _w) : u(_u) , v(_v), w(_w) {}
};

Edge edges[SZ];

vi adj[SZ] , back ;

void Reset() {
    rep(i,SZ){
        d[i] = 0;
        pred[i] = -1 ;
        adj[i].clear();
        inNegCycle[i] = false ;
    }
    back.clear();
}

void relax(int u, int v, int w) {
    if (d[v] > d[u] + w  ) {
        d[v] = d[u] + w ;
        pred[v] = u;
    }
}

bool Bellman(int src)
{
    For(k,N-1) rep(i,M)  relax( edges[i].u , edges[i].v , edges[i].w);
    bool cycle = false ;
    rep(i,M) if (d[edges[i].v] > d[edges[i].u] + edges[i].w) cycle =  true , back.pb( edges[i].u );
    return cycle;
}

void Input(){
    N = II , M = II ;
    rep(i,M){
        int u = II , v  = II , w = II ;
        edges[i] =  Edge(v,u, w) ;
        adj[v].pb(u); // reverse edge
    }
}

void printPath(int u ){
    if(u == -1 )return ;
    printPath( pred[u] );
    cout << u << " ";
}

void dfs(int u ){
    inNegCycle[u] = true ;
    forstl(i,adj[u]){
        if( !inNegCycle[*i] ) dfs(*i);
    }
}

int main(){
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    int test = II ;
    For(cs,test) {
        Reset();
        Input();
        printf("Case %d:",cs);
        bool hasNegCycle = Bellman(0);
        if(!hasNegCycle){
            printf(" impossible");
        }
        else {
            forstl(i,back) if( !inNegCycle[*i] ) dfs(*i);
            rep(i,N) if( inNegCycle[i] ) printf(" %d",i);
        }
        puts("");
    }
}
