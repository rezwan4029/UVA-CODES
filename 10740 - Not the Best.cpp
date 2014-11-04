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
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<"\t"; return *this; }}dbg;
#define __1D(a,n) rep(i,n) { if(i) printf(" ") ; cout << a[i] ; }
#define __2D(a,r,c,f) forab(i,f,r-!f){forab(j,f,c-!f){if(j!=f)printf(" ");cout<<a[i][j];}cout<<endl;}

template<class A, class B> ostream &operator<<(ostream& o, const pair<A,B>& p){ return o<<"("<<p.ff<<", "<<p.ss<<")";} //Pair print
template<class T> ostream& operator<<(ostream& o, const vector<T>& v){ o<<"[";forstl(it,v)o<<*it<<", ";return o<<"]";} //Vector print
template<class T> ostream& operator<<(ostream& o, const set<T>& v){ o<<"[";forstl(it,v)o<<*it<<", ";return o<<"]";} //Set print
template<class T> inline void MAX(T &a , T b){ if (a < b ) a = b;}
template<class T> inline void MIN(T &a , T b){ if (a > b ) a = b;}

//Fast Reader
template<class T>inline bool read(T &x){int c=gc();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=gc();}for(x=0;~c&&'0'<=c&&c<='9';c=gc())x=x*10+c-'0';x*=sgn;return ~c;}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

const int MX = 1007 ;
const int INF = 1e8 ;
int N , M , d[MX][12];
struct edge {
    int v, w;
    edge(int v,int w):v(v),w(w){}
};
vector<edge>adj[MX];
struct info {
    int v, w, k;
    bool operator < ( const info &b ) const {
        return w > b.w;
    }
};
int kthBestShortestPath( int src , int sink , int K ) {
    priority_queue < info, vector <info> > Q;
    info u, v;
    rep(i,N+1) rep(j,K) d[i][j] = INF;
    u.v = src; u.k = 0; u.w = 0;
    Q.push(u);
    while( !Q.empty() ) {
        u = Q.top(); Q.pop();
        forstl(it,adj[u.v]){
            v.v = it->v;
            int cost = it->w + u.w;
            for( v.k = u.k; v.k < K; v.k++ ) {
                if( cost == INF ) break;
                if( d[v.v][v.k] >= cost && (v.v == 0 || cost >= d[v.v][v.k-1]) ) {
                    swap( cost, d[v.v][v.k] );
                    v.w = d[v.v][v.k];
                    Q.push(v);
                    break;
                }
            }
            for( v.k++; v.k < K; v.k++ ) {
                if( cost == INF ) break;
                if( d[v.v][v.k] >= cost && (v.v==0 || cost >= d[v.v][v.k-1]) ) swap( cost, d[v.v][v.k] );
            }
        }
    }
    if( d[sink][K-1] == INF ) return -1 ;
    return d[sink][K-1] ;
}
int main(){
  //  freopen("ain.txt","r",stdin);
    while( 1 ){
        N = II , M = II ;
        if( N == 0 and M == 0 ) break ;
        int SRC = II , SNK = II , K = II ;
        while( M-- ){
            int x = II , y = II , z = II ;
            adj[x].pb( edge(y,z) );
          //  adj[y].pb( edge(x,z) );
        }
        printf("%d\n",kthBestShortestPath(SRC,SNK,K));
        rep(i,N+1) adj[i].clear();
    }
}
