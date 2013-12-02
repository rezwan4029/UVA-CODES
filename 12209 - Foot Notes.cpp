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

const int MX = 507;
const int INF = 1e8;
int N , S , W ;
vi article[MX];
int Vis[MX],T;
int dp[MX];

int solve(int p){
    if( p == N ) return 0 ;
    int &ret = dp[p];
    if( Vis[p] == T )return ret ;
    Vis[p] = T ;
    ret = INF ;
    set<int>st;
    forab(i,p,N-1) {
        forstl(it,article[i]) st.insert(*it);
        int tot = st.size() ;
        if( tot + i - p >= S ) break ;
        ret = min( ret , solve(i+1)+tot );
    }
    return ret ;
}

int main(){
    #ifdef LOCAL
       freopen ("in.txt", "r", stdin);
    #endif
    int test = II ;
    For(cs,test){
        N = II , S = II , W = II ;
        rep(i,W){
            int k = II ;
            rep(j,k) { int x = II - 1 ; article[x].pb(i);  }
        }
        ++T;
        int Ans = solve(0);
        printf("Case %d: %d\n",cs,Ans == INF ? -1 : Ans );
        rep(i,N) article[i].clear();
    }
}
