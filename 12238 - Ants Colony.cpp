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

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

#ifdef LOCAL
#define __(args...) {dbg,args; cerr<<endl;}
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<"\t"; return *this; }}dbg;
#define __1D(a,n) rep(i,n) { if(i) printf(" ") ; cout << a[i] ; }
#define __2D(a,r,c,f) forab(i,f,r-!f){forab(j,f,c-!f){if(j!=f)printf(" ");cout<<a[i][j];}cout<<endl;}
#endif
template<class A, class B> ostream &operator<<(ostream& o, const pair<A,B>& p){ return o<<"("<<p.ff<<", "<<p.ss<<")";} //Pair print
template<class T> ostream& operator<<(ostream& o, const vector<T>& v){ o<<"[";forstl(it,v)o<<*it<<", ";return o<<"]";} //Vector print
template<class T> ostream& operator<<(ostream& o, const set<T>& v){ o<<"[";forstl(it,v)o<<*it<<", ";return o<<"]";} //Set print

//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


const int MX = 1e5 + 7 ;
const int MXLG = 22 ;
const int INF = 1e8 + 7;
vector<pii>edge[MX] ;
int N , P[MX][MXLG] , L[MX] , T[MX];
Long dist[MX];
bool Vis[MX];
void dfs(int u , int p , int d){
    Vis[u] = true ;
    T[u] = p ; L[u] = d ;
    forstl(i,edge[u]){
        int v = i->ff , w = i->ss;
        if( Vis[v] ) continue;
        P[v][0] = u ;
        dist[v] = dist[u] + w ;
        dfs(v,u,d+1);
    }
}
void preprocess() {
    for( int i = 1 ; i <= N ; i++ ){
        for( int j = 0 ; (1 << j) < N ; j++ ){
            P[i][j] = -1 ;
        }
    }
    dfs(0,-1,0); // call with u = 0 becase The first anthill, numbered 0, did not require any tunnel
    for( int j = 1 ; (1 << j) < N ; j++ ) {
        for( int i = 1 ; i <= N ; i++ ) {
            if( P[i][j - 1] == -1 ) continue ;
            P[i][j] = P[ P[i][j - 1] ][j - 1];
        }
    }
}
void Reset(){
    for( int i = 0 ; i <=  N ; i++ ){
        edge[i].clear();
        Vis[i] = false ;
        dist[i] = -1;
    }
    dist[0] = 0 ;// 0 is root of  the tree
}
int lca(int p , int q){
    if(L[p] < L[q] ) swap(p,q);
    int lg ;
    for( lg = 1 ; (1 << lg) <= L[p] ; ++lg );
    lg--;
    for( int i = lg ; i >= 0 ; i--){
        if( L[p] - (1 << i) >= L[q] ){
            p = P[p][i];
        }
    }
    if( p == q ) return p ;
    for( int i = lg ; i >= 0 ; i-- ){
        if( P[p][i] != -1 && P[p][i] != P[q][i]){
            p = P[p][i];
            q = P[q][i];
        }
    }
    return T[p];
}
void Input(){
    Reset();
    For(u,N-1) {
        int v , w ;
        read(v) , read(w);
        edge[u].pb(mp(v,w));
        edge[v].pb(mp(u,w));
    }
}
int main(){
#ifdef LOCAL
         FI ;
#endif
    while( read(N) ) {
        if( !N ) return 0;
        Input();
        preprocess();
        int Q ; read(Q);
        rep(q,Q){
            if(q) printf(" ");
            int x , y ; read(x) , read(y);
            int a = lca(x,y);
            Long Ans = dist[x] + dist[y] - 2 * dist[a] ;
            printf("%lld",Ans);
        }
        printf("\n");
    }
}
