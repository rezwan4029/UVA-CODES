/*
    Rezwan_4029 , AUST
*/

#include <bits/stdc++.h>

#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL ({Long a; scanf("%lld", &a); a;})
#define DD ({double a; scanf("%lf", &a); a;})
#define ff first
#define ss second
#define mp make_pair
#define gc getchar
#define EPS 1e-10
#define pi 3.1415926535897932384626433832795
using namespace std;

#define FI freopen ("in.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)

typedef long long Long;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef set<int> si;
typedef vector<Long>vl;
typedef pair<int,int>pii;
typedef pair<string,int>psi;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;
typedef vector<pii> vpii;

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

#define __(args...) {dbg,args; cerr<<endl;}
struct debugger {
    template<typename T> debugger& operator , (const T& v) {
        cerr<<v<<"\t";
        return *this;
    }
} dbg;
#define __1D(a,n) rep(i,n) { if(i) printf(" ") ; cout << a[i] ; }
#define __2D(a,r,c,f) forab(i,f,r-!f){forab(j,f,c-!f){if(j!=f)printf(" ");cout<<a[i][j];}cout<<endl;}

template<class A, class B> ostream &operator<<(ostream& o, const pair<A,B>& p) {
    return o<<"("<<p.ff<<", "<<p.ss<<")";   //Pair print
}
template<class T> ostream& operator<<(ostream& o, const vector<T>& v) {
    o<<"[";    //Vector print
    forstl(it,v)o<<*it<<", ";
    return o<<"]";
}
template<class T> ostream& operator<<(ostream& o, const set<T>& v) {
    o<<"[";    //Set print
    forstl(it,v)o<<*it<<", ";
    return o<<"]";
}
template<class T> inline void MAX(T &a , T b) {
    if (a < b ) a = b;
}
template<class T> inline void MIN(T &a , T b) {
    if (a > b ) a = b;
}

//Fast Reader
template<class T>inline bool read(T &x) {
    int c=gc();
    int sgn=1;
    while(~c&&c<'0'||c>'9') {
        if(c=='-')sgn=-1;
        c=gc();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=gc())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

#define SZ 100007

int N , M ;
Long d[SZ][2] ;
bool Vis[SZ][2];

struct Node {
    int v , w ;
    Node() {}
    Node(int _v , int _w) {
        v = _v , w = _w ;
    }
    bool operator <(const Node &a) const {
        if (w != a.w) return (w > a.w);
        return (v > a.v);
    }
};

vector<Node>adj[SZ];

void Reset() {
    rep(i,N+1) {
        adj[i].clear();
        d[i][0] = d[i][1] = -1 ;
        Vis[i][0] =  Vis[i][1] = false ;
    }
}

void Dijstra(int src,int id) {
    priority_queue<Node>Q;
    d[src][id] = 0 ;
    Q.push( Node(src,0) );
    while(!Q.empty()) {
        Node now = Q.top();
        Q.pop();
        int currNode = now.v , currCost = now.w ;
        if(Vis[currNode][id])continue;
        Vis[currNode][id] = true ;
        forstl( it , adj[currNode] ) {
            int vv = it->v , cc = it->w ;
            if( currCost + cc < d[ vv ][id] || d[ vv ][id] == -1 ) {
                d[ vv ][id] = currCost + cc ;
                Q.push( Node( vv , d[ vv ][id] ) );
            }
        }
    }
}

void Input() {
    Reset();
    rep(i,M) {
        int u = II + 1 , v = II + 1 , w = II ;
        adj[u].pb( Node(v,w) );
        adj[v].pb( Node(u,w) );
    }
}

int main() {
   // freopen("ain.txt","r",stdin);
    while( scanf("%d %d",&N,&M) == 2) {
        Input();
        Dijstra(1,0);
        Dijstra(N,1);
        Long dis = d[N][0];
        Long ans = 0;
        int cnt = 1 ;
        For(i,N) {
            forstl(it,adj[i]){
                if( d[i][0] == -1 or d[it->v][1] == -1 ) continue ;
                Long tmp = d[i][0] + it->w + d[it->v][1];
                if(tmp == dis) ans += it->w;
            }
        }
        printf("%lld\n",ans*2);
    }
}
