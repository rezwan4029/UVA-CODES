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

const int MX = 10007  ;
const int INF = 1e8 + 7;

const int  MAXE = 100007 ;

int src, snk, nNode, nEdge;
int Q[MX], fin[MX], pro[MX], dist[MX];
int flow[MAXE], cap[MAXE], next[MAXE], to[MAXE];

inline void init(int _n) {
    nNode = _n, nEdge = 0;
    ms(fin,-1);
}

inline void add(int u, int v, int c) {
    to[nEdge] = v, cap[nEdge] = c, flow[nEdge] = 0, next[nEdge] = fin[u], fin[u] = nEdge++;
    to[nEdge] = u, cap[nEdge] = c, flow[nEdge] = 0, next[nEdge] = fin[v], fin[v] = nEdge++;
}

bool bfs() {
    int st, en, i, u, v;
    ms(dist,-1);
    dist[src] = st = en = 0;
    Q[en++] = src;
    while(st < en) {
        u = Q[st++];
        for(i=fin[u]; i>=0; i=next[i]) {
            v = to[i];
            if(flow[i] < cap[i] && dist[v]==-1) {
                dist[v] = dist[u]+1;
                Q[en++] = v;
            }
        }
    }
    return dist[snk]!=-1;
}

int dfs(int u, int fl) {
    if(u==snk) return fl;
    for(int &e=pro[u], v, df; e>=0; e=next[e]) {
        v = to[e];
        if(flow[e] < cap[e] && dist[v]==dist[u]+1) {
            df = dfs(v, min(cap[e]-flow[e], fl));
            if(df>0) {
                flow[e] += df;
                flow[e^1] -= df;
                return df;
            }
        }
    }
    return 0;
}

int dinitz() {
    int ret = 0;
    int df;
    while(bfs()) {
        for(int i=0; i<=nNode; i++) pro[i] = fin[i];
        while(true) {
            df = dfs(src, INF);
            if(df) ret += df;
            else break;
        }
    }
    return ret;
}


int main(){
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
       // freopen ("out.txt", "w" , stdout);
    #endif
    int n, e , cs = 1 ;
    while( scanf("%d%d", &n, &e)){
        if( n == 0 && e == 0 ) break ;
        init(n);
        rep(i,e){
            int u = II , v  = II ;
            if( u != v ) add(u, v, 1) ;
        }
        int x = II , y = II ;
        src = 0 ;
        snk = y ;
        add(src,x,2);
        int flow = dinitz();
        printf("Case %d: %s\n",cs++ , flow == 2 ? "YES" : "NO" );
    }
}
