/*
    AUST_toothless
*/
#include <bits/stdc++.h>

#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ( { int a ; read(a) ; a; } )
#define LL ( { Long a ; read(a) ; a; } )
#define DD ({double a; scanf("%lf", &a); a;})
#define ff first
#define ss second
#define mp make_pair

#define pi 3.1415926535897932384626433832795
using namespace std;

typedef long long Long;
typedef long long int64;
typedef unsigned long long ull;

typedef pair<int,int>pii;
typedef pair<string,int>psi;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;

typedef vector<int>    vi;
typedef vector<Long>   vl;
typedef vector<string> vs;
typedef vector<pii>  vpii;
typedef set<int> si;

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)


#define __( args... ) { dbg , args ; cerr << endl; }

struct debugger {
    template< typename T > debugger & operator , ( const T &v ) {
        cerr << v << "\t" ;
        return *this;
    }
} dbg;
// Pair Print
template< class A , class B > ostream &operator << ( ostream &o, const pair<A,B> &p ) {
    return o<<"(" << p.ff << ", " << p.ss << ")" ;
}
//Vector Print
template<class T> ostream& operator<<(ostream& o, const vector<T>& v) {
    o << "[";
    forstl(it,v) o << *it << ", " ;
    return o << "]";
}
//Set Print
template<class T> ostream& operator<<(ostream& o, const set<T>& v) {
    o << "[";
    forstl(it,v) o << *it << ", " ;
    return o << "]";
}
template<class T> inline void MAX( T &a , T b) {
    if (a < b ) a = b;
}
template<class T> inline void MIN( T &a , T b) {
    if (a > b ) a = b;
}

//Fast Reader
template< class T > inline bool read( T &x ) {
    int c = getchar() ;
    int sgn = 1;
    while( ~c && c < '0' || c > '9' ) {
        if( c == '-' )sgn = -1 ;
        c = getchar() ;
    }
    for( x = 0 ; ~c && '0' <= c && c <= '9' ; c = getchar() ) x = x * 10 + c - '0' ;
    x *= sgn ;
    return ~c ;
}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

const int MX = 2e5 + 7 ;
#define INF 7777777
#define NIL 0

vi G[MX];
int n, m, match[MX], dist[MX];

// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// G = NIL[0] G1[G[1---n]] G2[G[n+1---n+m]]

bool bfs() {
    queue< int > Q;
    For(i,n) {
        if(match[i]==NIL) {
            dist[i] = 0;
            Q.push(i);
        } else dist[i] = INF;
    }
    dist[NIL] = INF;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if( u != NIL) {
            forstl(i,G[u]) {
                int v = *i;
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}

bool dfs(int u) {
    if(u != NIL) {
        forstl(i,G[u]) {
            int v = *i;
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}
int hopcroft_karp() {
    int matching = 0 ;
    forab(i,0,2*n) match[i] = NIL;
    // match[] is assumed NIL for all vertex in G
    while(bfs()) {
        For(i,n)
        if(match[i] == NIL && dfs(i)) matching++;
    }
    return matching;
}
void Reset() {
    For(i,2*n) G[i].clear();
}
void Input() {
    Reset();
    while( m-- ) {
        int u = II + 1, v = II + 1 ;
        G[u].pb( n + v );
       // G[v].pb( n + u );
    }
}
int main() {
#ifdef LOCAL
    freopen ("ain.txt", "r", stdin);
    //  freopen ("output.txt", "w", stdout);
#endif
    while( scanf("%d %d",&n,&m) == 2) {
        Input();
        int ans = hopcroft_karp();
        puts( ans == n ? "YES" : "NO" );
    }
}
