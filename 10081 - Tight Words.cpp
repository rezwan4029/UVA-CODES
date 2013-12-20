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

const int MX = 100 + 7 ;
const int INF = 1e8 + 7;
int N , k  ;
double dp[MX][12];
bool Vis[MX][12];
double solve(int pos , int pre){
    if( pos == N ) return 1.00 ;
    double &ret = dp[pos][pre];
    if( Vis[pos][pre] ) return ret ;
    Vis[pos][pre] = true ;
    ret = 0 ;
    forab(i,0,k) if( abs(pre-i) <= 1 ) ret += solve(pos+1,i);
    ret /= double(k+1);
    return ret ;
}
int main(){
    #ifdef LOCAL
        freopen ("in.txt", "r", stdin);
    #endif
    while( scanf("%d %d",&k,&N) != EOF ){
        ms(Vis,false);
        double ans = 0 ;
        forab(i,0,k) ans += solve(1,i);
        ans /= double(k+1);
        printf("%.5lf\n",ans*100.);
    }
}
