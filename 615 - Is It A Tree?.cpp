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

const int MX = 100007 ;
const int INF = 1e8 + 7;

vi edges[MX];
bool Vis[MX];
int In[MX];
int Cnt ;
bool foundCycle ;
void Dfs(int u ){
    Vis[u] = true ;
    Cnt++;
    forstl(it,edges[u]){
        if( !Vis[*it] ) Dfs(*it);
        else  foundCycle = true ;
    }
}
int main(){
    #ifdef LOCAL
     // freopen ("in.txt", "r", stdin);
       //freopen ("out.txt","w",stdout);
    #endif
    int u , v , cs = 1 ;
    while( true ){
        ms(In,0) ;
        map<int,int>M;
        int n = 0 ;
        rep(i,MX) edges[i].clear() , Vis[i] = false ;
        while( scanf("%d %d",&u,&v) ) {
            if( u == 0 && v == 0 ) break ;
            if( u == -1 && v == -1 ) return 0 ;
            if( !M[u] ) M[u] = ++n ;
            if( !M[v] ) M[v] = ++n ;
            edges[ M[u] ].pb( M[v] );
            In[ M[v] ]++;
        }
        foundCycle = false ;
        Cnt = 0 ;
        For(i,n) if( In[i] == 0 ) { Dfs(i) ; break ; }
        if( Cnt == n  && !foundCycle ) printf("Case %d is a tree.\n",cs++);
        else printf("Case %d is not a tree.\n",cs++);
    }
}
