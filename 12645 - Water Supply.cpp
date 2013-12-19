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

const int MX = 100007;
vi adj[MX],order;
bool used[MX];
int Ans;
int N , M;

void dfs1(int u) {
    used[u] = true ;
    forstl(it,adj[u]) if( !used[ *it ] ) dfs1( *it );
    order.pb(u);
}

void dfs2(int u  ){
    used[u] =  true ;
    forstl(it,adj[u]) if( !used[ *it ] ) dfs2( *it );
}

void Reset(){
    rep(i,N+7){
        adj[i].clear();
    }
    ms(used,false);
    order.clear();
}

void Input(){
    rep(i,M){
        int u = II , v = II  ;
        if(!v)continue;
        adj[u].pb(v);
    }
}

int main(){
     #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    while( scanf("%d %d",&N,&M) != EOF ){
        Reset();
        Input();
        forab(i,0,N) if( !used[i] ) dfs1(i);
        ms(used,false);
        reverse(all(order));
        Ans = 0 ;
        forstl(it,order){
            int v = *it ;
            if( !used[ v ] ){
                if( v == 0 ) { dfs2(v); continue ; }
                Ans++;
                dfs2(v);
            }
        }
        printf("%d\n",Ans);
    }
}
