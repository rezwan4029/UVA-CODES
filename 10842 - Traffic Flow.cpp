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


#define SZ 100007
struct edge{
    int u,v,w;
    edge( int a ,int b, int c){
        u = a , v = b , w = c;
    }
    edge(){};
};

bool operator < ( edge a ,edge b){  return a.w > b.w ; }

int prev[SZ];
bool Vis[SZ];

int Parent(int i){
    if(i==prev[i])return i;
    return ( prev[i] = Parent( prev[i] ) );
}

int isUnion(int a,int b){
    return Parent(a) == Parent(b);
}

void makeUnion(int a,int b ){
    prev[ Parent(a) ] = Parent(b);
}

int MST(int n , edge *x , int e ){
  sort(x,x+e);
  rep(i,n) prev[i] = i ;
  int mst = 0 , spanning_edges = 0 ;
  rep(i,e){
        if(!isUnion(x[i].u,x[i].v)){
            makeUnion(x[i].u,x[i].v);
            mst += x[i].w;
            spanning_edges ++ ;
            Vis[i] = true ;
        }
   }
   return mst ; // if(spanning edges == n - 1 )
}

int d[110][110];

int main(){
    #ifdef LOCAL
       freopen ("in.txt", "r", stdin);
    #endif
    edge Ed[SZ];
    int test = II ;
    For(cs,test){
        ms(d,0);
        int n = II , m = II , M = 0 ;
        rep(i,m){
            int u = II , v = II , w = II ;
            if( u == v ) continue ;
            d[u][v] = d[v][u] = max( d[u][v] , w );
        }
        rep(i,n)rep(j,n) if(d[i][j] ) {
            Ed[M++] = edge(i,j,d[i][j]) ;
            d[i][j] = d[j][i] = 0 ;
        }
        ms(Vis,false);
        MST(n,Ed,M);
        int Ans = 1000000 ;
        rep(i,M)if(Vis[i]) Ans = min( Ans , Ed[i].w );
        printf("Case #%d: %d\n",cs,Ans);
    }
}
